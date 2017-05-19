#include "ActionManager.h"

bool ActionManager::move(const Vect2D &position, Player player, Unit *&unitToMove, UnitStore &unitStore,
                         BuildingStore &buildingStore, const Map &map) {
    // Fast Marching
    double inf = 1.0 / 0.0;
    int maxDistance = unitToMove->getSpeed();
    int minXPos = (unitToMove->getPosition().x() - maxDistance > 0) ? unitToMove->getPosition().x() - maxDistance : 0;
    int minYPos = (unitToMove->getPosition().y() - maxDistance > 0) ? unitToMove->getPosition().y() - maxDistance : 0;
    int maxXPos = (unitToMove->getPosition().x() + maxDistance < map.getWidth()) ? unitToMove->getPosition().x() +
                                                                                   maxDistance : map.getWidth();
    int maxYPos = (unitToMove->getPosition().y() + maxDistance < map.getHeight()) ? unitToMove->getPosition().y() +
                                                                                    maxDistance : map.getHeight();
    double W[(maxYPos - minYPos) * (maxXPos - minXPos)] = {1};
    for (int x = minXPos; x < maxXPos; x++) {
        for (int y = minYPos; y < maxYPos; y++) {
            Vect2D pos(x, y);
            if (buildingStore.isBuilding(pos)) {
                Player buildingOwner;
                Building &building = buildingStore.getBuilding(pos, buildingOwner);
                if (player != buildingOwner) {
                    W[y * (maxXPos - minXPos) + x] = inf;
                } else {
                    if (building.getGarnisonUnit() != NULL) {
                        W[y * (maxXPos - minXPos) + x] = inf;
                    }
                }
            } else if (unitStore.isUnit(pos)) {
                Player unitOwner;
                Unit &unit = unitStore.getUnit(pos, unitOwner);
                if (player != unitOwner) {
                    W[y * (maxXPos - minXPos) + x] = inf;
                }
            }
            if (map.getTerrainType(x, y) == RIVER && !unitToMove->getCanWalkThroughRiver()) {
                W[y * (maxXPos - minXPos) + x] = inf;
            }
        }
    }
    bool costMapChanged;
    do {
        costMapChanged = false;
        // TODO file priorité
        // TODO algo de fastMarching
    } while (costMapChanged);

    return false;
}

void ActionManager::attack(const Vect2D &position, const Player player, FightingUnit *&selectedFU, UnitStore &unitStore,
                           BuildingStore &buildingStore) {
    // TODO
}

void
ActionManager::build(const Vect2D &position, const Player player, Entity *&selectedFU, BuildingStore &buildingStore) {
    // TODO
}

void
ActionManager::clickMap(const Vect2D &coordPos, Action &currentAction, const Player playerTurn, Entity *&selectedEntity,
                        UnitStore &unitStore, BuildingStore &buildingStore, const Map &map, UIManager &uiManager) {

    switch (currentAction) {
        case MOVE: {
            Unit *selectedUnit = static_cast<Unit *>(selectedEntity);
            bool successfulMove = move(coordPos, playerTurn, selectedUnit, unitStore, buildingStore, map);
            if (successfulMove) {
                uiManager.clearUi();
                selectedUnit->setFinishedTurn(true);
            }
        }
            break;
        case ATTACK: {
            FightingUnit *selectedFightingUnit = static_cast<FightingUnit *>(selectedEntity);
            attack(coordPos, playerTurn, selectedFightingUnit, unitStore, buildingStore);
        }
            break;
        case BUILD:
            break;
        case BUILD_BARRACK:
            break;
        case BUILD_DEFENSE_TURRET:
            break;
        case BUILD_BRIDGE:
            break;
        case BUILD_DRILL:
            break;
        case BUILD_EXTRACTOR:
            break;
        case NONE: {
            if (unitStore.selectUnit(coordPos, playerTurn, selectedEntity) ||
                buildingStore.selectBuilding(coordPos, playerTurn, selectedEntity)) {
                uiManager.clearUi();
                uiManager.displayButton(selectedEntity->getType());
            } else {
                uiManager.clearUi();
                selectedEntity = NULL;
            }
        }
            break;
    }

}
