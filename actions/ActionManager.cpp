#include "ActionManager.h"

bool ActionManager::move(const Vect2D &position, Player player, Unit *&unitToMove, UnitStore &unitStore,
                         BuildingStore &buildingStore, const Map &map) {
    if (unitToMove->isPossibleMove(position)) {
        unitToMove->setPosition(position);
        unitToMove->setFinishedTurn(true);
        return true;
    }
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
                selectedUnit->setPosition(coordPos);
                selectedUnit->setFinishedTurn(true);
                currentAction = NONE;
                uiManager.clearUi();
                selectedEntity = NULL;
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
