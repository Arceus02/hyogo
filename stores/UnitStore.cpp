#include "UnitStore.h"
#include "../util/fastMarching/fastMarching.h"

void UnitStore::draw(Player player, const ResourceManager &resourceManager, const Vect2D &viewOffset,
                     const Vect2D &minRender, const Vect2D &maxRender) const {
    player1Units.draw(resourceManager, viewOffset, minRender, maxRender);
    player2Units.draw(resourceManager, viewOffset, minRender, maxRender);
    Store<Unit> currentTurnPlayerUnits = (player == PLAYER1) ? player1Units : player2Units;
    for (vector<Unit>::iterator k = currentTurnPlayerUnits.getList().begin();
         k != currentTurnPlayerUnits.getList().end(); k++) {
        Unit unit = (*k);
        if (unit.isFinishedTurn()) {
            unit.drawIsFinishedTurnBox(viewOffset);
        }
    }
}

void UnitStore::add(Player player, Unit &unit) {
    if (player == PLAYER1) {
        player1Units.add(unit);
    } else if (player == PLAYER2) {
        player2Units.add(unit);
    }

}

bool UnitStore::selectUnit(const Vect2D &coordCase, Player player, Entity *&selectedEntity) {
    Store<Unit> *unitVector = (player == PLAYER1) ? &player1Units : &player2Units;
    for (std::vector<Unit>::iterator it = unitVector->getList().begin(); it != unitVector->getList().end(); ++it) {
        if ((*it).getPosition().x() == coordCase.x() && (*it).getPosition().y() == coordCase.y()) {
            if ((*it).isFinishedTurn()) {
                return false;
            }
            selectedEntity = &(*it);
            return true;
        }
    }
    return false;
}

bool UnitStore::isUnit(const Vect2D &coordCase) {
    for (std::vector<Unit>::iterator it = player1Units.getList().begin();
         it != player1Units.getList().end(); ++it) {
        if ((*it).getPosition().x() == coordCase.x() && (*it).getPosition().y() == coordCase.y()) {
            return true;
        }
    }
    for (std::vector<Unit>::iterator it = player2Units.getList().begin();
         it != player2Units.getList().end(); ++it) {
        if ((*it).getPosition().x() == coordCase.x() && (*it).getPosition().y() == coordCase.y()) {
            return true;
        }
    }
    return false;
}

Unit &UnitStore::getUnit(const Vect2D coordCase, Player &player) {
    assert(isUnit(coordCase));
    for (std::vector<Unit>::iterator it = player1Units.getList().begin();
         it != player1Units.getList().end(); ++it) {
        if ((*it).getPosition().x() == coordCase.x() && (*it).getPosition().y() == coordCase.y()) {
            player = PLAYER1;
            return (*it);
        }
    }
    for (std::vector<Unit>::iterator it = player2Units.getList().begin();
         it != player2Units.getList().end(); ++it) {
        if ((*it).getPosition().x() == coordCase.x() && (*it).getPosition().y() == coordCase.y()) {
            player = PLAYER2;
            return (*it);
        }
    }
}

void UnitStore::updatePossibleMoves(const Map &map, BuildingStore &buildingStore, Player player) {
    Store<Unit> *playerUnitStore = (player == PLAYER1) ? &player1Units : &player2Units;
    for (vector<Unit>::iterator k = playerUnitStore->getList().begin(); k != playerUnitStore->getList().end(); k++) {
        Unit &unitToMove = (*k);
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
                if (buildingStore.isBuilding(pos)) {
                    Player buildingOwner;
                    Building &building = buildingStore.getBuilding(pos, buildingOwner);
                    if (player != buildingOwner) {
                        W(x, y) = INF;
                    } else {
                        if (building.getGarnisonUnit() != NULL) {
                            W(x, y) = INF;
                        }
                    }
                } else if (isUnit(pos)) {
                    Player unitOwner;
                    Unit &unit = getUnit(pos, unitOwner);
                    if (player != unitOwner) {
                        W(x, y) = INF;
                    }
                }
                if (map.getTerrainType(pos.x(), pos.y()) == RIVER && !unitToMove.getCanWalkThroughRiver()) {
                    W(x, y) = INF;
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
