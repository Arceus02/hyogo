#include "UnitManager.h"
#include "../util/fastMarching/fastMarching.h"

void UnitManager::draw(Player currentTurn, const ResourceManager &resourceManager, const Vect2D &viewOffset,
                       const Vect2D &minRender, const Vect2D &maxRender) const {
    player1Units.draw(resourceManager, viewOffset, minRender, maxRender, currentTurn);
    player2Units.draw(resourceManager, viewOffset, minRender, maxRender, currentTurn);
}

void UnitManager::add(Player player, Unit *unit) {
    unit->setOwner(player);
    if (unit->getOwner() == PLAYER1) {
        player1Units.add(unit);
    } else {
        player2Units.add(unit);
    }
}

bool UnitManager::selectUnit(const Vect2D &coordCase, Player player, Entity *&selectedEntity) {
    Store<Unit *> *unitVector = (player == PLAYER1) ? &player1Units : &player2Units;
    for (std::vector<Unit *>::iterator it = unitVector->getList().begin(); it != unitVector->getList().end(); ++it) {
        if ((*it)->getPosition().x() == coordCase.x() && (*it)->getPosition().y() == coordCase.y()) {
            if ((*it)->isFinishedTurn() || (*it)->getIsInGarrison()) {
                return false;
            }
            selectedEntity = *it;
            return true;
        }
    }
    return false;
}

bool UnitManager::isUnit(const Vect2D &coordCase) {
    for (std::vector<Unit *>::iterator it = player1Units.getList().begin();
         it != player1Units.getList().end(); ++it) {
        if ((*it)->getPosition().x() == coordCase.x() && (*it)->getPosition().y() == coordCase.y() &&
            !(*it)->getIsInGarrison()) {
            return true;
        }
    }
    for (std::vector<Unit *>::iterator it = player2Units.getList().begin();
         it != player2Units.getList().end(); ++it) {
        if ((*it)->getPosition().x() == coordCase.x() && (*it)->getPosition().y() == coordCase.y() &&
            !(*it)->getIsInGarrison()) {
            return true;
        }
    }
    return false;
}

Unit &UnitManager::getUnit(const Vect2D coordCase, Player &player) {
    assert(isUnit(coordCase));
    for (std::vector<Unit *>::iterator it = player1Units.getList().begin();
         it != player1Units.getList().end(); ++it) {
        if ((*it)->getPosition().x() == coordCase.x() && (*it)->getPosition().y() == coordCase.y()) {
            player = PLAYER1;
            return *(*it);
        }
    }
    for (std::vector<Unit *>::iterator it = player2Units.getList().begin();
         it != player2Units.getList().end(); ++it) {
        if ((*it)->getPosition().x() == coordCase.x() && (*it)->getPosition().y() == coordCase.y()) {
            player = PLAYER2;
            return *(*it);
        }
    }
}

void UnitManager::updatePossibleMoves(const Map &map, BuildingManager &buildingStore, Player player) {
    Store<Unit *> *playerUnitStore = (player == PLAYER1) ? &player1Units : &player2Units;
    for (vector<Unit *>::iterator k = playerUnitStore->getList().begin(); k != playerUnitStore->getList().end(); k++) {
        Unit &unitToMove = *(*k);
        // Apply fast marching
        float INF = 1.0f / 0.0f;
        int maxDistance = unitToMove.getSpeed();

        int minXPos = (unitToMove.getPosition().x() - maxDistance > 0) ? unitToMove.getPosition().x() - maxDistance : 0;
        int minYPos = (unitToMove.getPosition().y() - maxDistance > 0) ? unitToMove.getPosition().y() - maxDistance : 0;
        int maxXPos = (unitToMove.getPosition().x() + maxDistance + 1 < map.getWidth()) ? unitToMove.getPosition().x() +
                                                                                          maxDistance + 1
                                                                                        : map.getWidth();
        int maxYPos = (unitToMove.getPosition().y() + maxDistance + 1 < map.getHeight()) ?
                      unitToMove.getPosition().y() + maxDistance + 1
                                                                                         : map.getHeight();

        int w = maxXPos - minXPos, h = maxYPos - minYPos;
        Image<float> W(w, h);
        W.fill(1);
        for (int x = 0; x < w; x++) {
            for (int y = 0; y < h; y++) {
                Vect2D pos(x + minXPos, y + minYPos);
                if (map.getTerrainType(pos.x(), pos.y()) == RIVER && !unitToMove.getCanWalkThroughRiver()) {
                    W(x, y) = INF;
                }
                if (buildingStore.isBuilding(pos)) {
                    Player buildingOwner;
                    Building &building = buildingStore.getBuilding(pos, buildingOwner);
                    if (player != buildingOwner) {
                        W(x, y) = INF;
                    } else {
                        if (building.getMaxGarrison() == building.getGarrisonSize()) {
                            W(x, y) = INF;
                        } else {
                            W(x, y) = 1;
                        }
                    }
                } else if (isUnit(pos)) {
                    Player unitOwner;
                    Unit &unit = getUnit(pos, unitOwner);
                    if (player != unitOwner) {
                        W(x, y) = INF;
                    }
                }
            }
        }

        vector<PointDist> niv0;
        PointDist p0(unitToMove.getPosition().y() - minYPos, unitToMove.getPosition().x() - minXPos, 0);
        niv0.push_back(p0);
        Image<float> D = fastMarching(W, niv0);

        vector<Vect2D> possibleMoves;
        for (int x = 0; x < w; x++) {
            for (int y = 0; y < h; y++) {
                // no move needed to keep the same position
                if (minXPos + x == unitToMove.getPosition().x() && minYPos + y == unitToMove.getPosition().y()) {
                    continue;
                }
                // no move on cells occupied by another unit
                Vect2D pos(minXPos + x, minYPos + y);
                if (isUnit(pos)) {
                    continue;
                }
                if (D(x, y) <= maxDistance) {
                    Vect2D moveMapCoord(minXPos + x, minYPos + y);
                    possibleMoves.push_back(moveMapCoord);
                }
            }
        }
        unitToMove.setPossibleMoves(possibleMoves);
    }
}

void UnitManager::updatePossibleAttacks(const Map &map, BuildingManager &buildingStore, Player player) {
    Store<Unit *> *playerUnitStore = (player == PLAYER1) ? &player1Units : &player2Units;
    for (vector<Unit *>::iterator k = playerUnitStore->getList().begin(); k != playerUnitStore->getList().end(); k++) {
        Unit &unit = *(*k);
        if (unit.getType() == FIGHTINGUNIT) {
            vector<Vect2D> possibleAttacks;
            FightingUnit &fightingUnit = *dynamic_cast<FightingUnit *>(&unit);
            int maxDistance = fightingUnit.getAttackRange();

            int minXPos = (fightingUnit.getPosition().x() - maxDistance > 0) ? fightingUnit.getPosition().x() -
                                                                               maxDistance : 0;
            int minYPos = (fightingUnit.getPosition().y() - maxDistance > 0) ? fightingUnit.getPosition().y() -
                                                                               maxDistance : 0;
            int maxXPos = (fightingUnit.getPosition().x() + maxDistance < map.getWidth() - 1) ?
                          fightingUnit.getPosition().x() + maxDistance : map.getWidth() - 1;
            int maxYPos = (fightingUnit.getPosition().y() + maxDistance < map.getHeight() - 1) ?
                          fightingUnit.getPosition().y() + maxDistance : map.getHeight() - 1;

            for (int x = minXPos; x <= maxXPos; x++) {
                for (int y = minYPos; y <= maxYPos; y++) {
                    int d = (x - unit.getPosition().x()) * (x - unit.getPosition().x()) +
                            (y - unit.getPosition().y()) * (y - unit.getPosition().y());
                    if (d <= maxDistance * maxDistance) {
                        Vect2D v(x, y);
                        possibleAttacks.push_back(v);
                    }
                }
            }
            fightingUnit.setPossibleAttacks(possibleAttacks);
        }
    }
}

void UnitManager::updatePossibleAttacks(const Map &map, BuildingManager &buildingStore) {
    updatePossibleAttacks(map, buildingStore, PLAYER1);
    updatePossibleAttacks(map, buildingStore, PLAYER2);
}

void UnitManager::buildUnits(const Player player) {
    if (player == PLAYER1) {
        for (std::vector<Unit *>::iterator it = player1Units.getList().begin();
             it != player1Units.getList().end(); ++it) {
            (*it)->build();
        }
    } else {
        for (std::vector<Unit *>::iterator it = player2Units.getList().begin();
             it != player2Units.getList().end(); ++it) {
            (*it)->build();
        }
    }
}

void UnitManager::clearFinishedTurn() {
    for (std::vector<Unit *>::iterator it = player1Units.getList().begin();
         it != player1Units.getList().end(); ++it) {
        (*it)->setFinishedTurn(false);
    }
    for (std::vector<Unit *>::iterator it = player2Units.getList().begin();
         it != player2Units.getList().end(); ++it) {
        (*it)->setFinishedTurn(false);
    }
}

void UnitManager::updateLivingEntities() {
    for (std::vector<Unit *>::iterator it = player1Units.getList().begin(); it != player1Units.getList().end();) {
        Unit *unit = (*it);
        if (unit->getHP() <= 0) {
            delete unit;
            player1Units.getList().erase(it);
        } else {
            it++;
        }
    }
    for (std::vector<Unit *>::iterator it = player2Units.getList().begin(); it != player2Units.getList().end();) {
        Unit *unit = (*it);
        if (unit->getHP() <= 0) {
            delete unit;
            player2Units.getList().erase(it);
        } else {
            it++;
        }
    }
}
