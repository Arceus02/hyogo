#include "ActionManager.h"

bool ActionManager::move(const Vect2D &position, Unit *&unitToMove, BuildingManager &buildingStore) {
    if (unitToMove->isPossibleMove(position)) {
        if (unitToMove->getIsInGarrison()) {
            //if the unit was in garrison in a building we get it out
            unitToMove->setInGarrison(false);
            Player unitOwner = unitToMove->getOwner();
            buildingStore.getBuilding(unitToMove->getPosition(), unitOwner).removeUnitGarrison(
                    unitToMove->getAssetId());
        }
        unitToMove->setPosition(position);
        if (buildingStore.isBuilding(position)) {
            unitToMove->setInGarrison(true);
            Player unitOwner = unitToMove->getOwner();
            buildingStore.getBuilding(unitToMove->getPosition(), unitOwner).addGarrisonUnit(unitToMove);
        }
        unitToMove->setFinishedTurn(true);
        return true;
    }
    return false;
}

bool
ActionManager::attack(const Vect2D &position, const Player player, FightingUnit *&selectedFU, UnitManager &unitStore,
                      BuildingManager &buildingStore) {
    if (selectedFU->isPossibleAttack(position)) {
        if (unitStore.isUnit(position)) {
            Player targetOwner;
            Unit &target = unitStore.getUnit(position, targetOwner);
            if (targetOwner != player) {
                target.damage(selectedFU->getDamage());
                unitStore.updateLivingEntities();
                return true;
            }
        }
    }
    return false;
}

bool
ActionManager::build(const Vect2D &position, const Player player, Entity *&selectedFU, BuildingManager &buildingStore,
                     Action &action, const Map &map, int &mineralQuantity, int &gasQuantity) {
    if (!buildingStore.isBuilding(position)) { //check if the worker isn't already in a building
        Building *buildingToBuild = 0;
        switch (map.getTerrainType(position.x(), position.y())) {
            case RIVER:
                //we can only build a bridge on a river
                if (action == BUILD_BRIDGE) {
                    Bridge *bridge = new Bridge();
                    buildingToBuild = bridge;
                }
                break;
            case MEADOW:
                switch (action) {
                    case BUILD_BARRACK: {
                        Barrack *barrack = new Barrack();
                        buildingToBuild = barrack;
                        break;
                    }
                    case BUILD_DEFENSE_TURRET: {
                        DefenseTurret *defenseTurret = new DefenseTurret();
                        buildingToBuild = defenseTurret;
                        break;
                    }
                    case BUILD_DRILL: {
                        Drill *drill = new Drill();
                        buildingToBuild = drill;
                        break;
                    }
                    case BUILD_EXTRACTOR: {
                        Extractor *extractor = new Extractor();
                        buildingToBuild = extractor;
                        break;
                    }
                    default:
                        break;
                }
            default://we can't build on a FOREST
                break;

        }
        if (buildingToBuild != 0 && mineralQuantity >= BUILDING_MINERAL_COST.at(action)
            && gasQuantity >= BUILDING_GAS_COST.at(action)) {
            //if the construction has been possible
            buildingToBuild->addGarrisonUnit(dynamic_cast<Worker *>(selectedFU));
            buildingToBuild->setPosition(position);
            buildingStore.add(player, buildingToBuild);
            mineralQuantity -= BUILDING_MINERAL_COST.at(action);
            gasQuantity -= BUILDING_GAS_COST.at(action);
            return true;
        }
    }
    return false;
}

void
ActionManager::click(const Vect2D &coordPos, Action &currentAction, const Player playerTurn, Entity *&selectedEntity,
                     UnitManager &unitStore, BuildingManager &buildingStore, const Map &map, UIManager &uiManager,
                     int &mineralQuantity, int &gasQuantity) {
    if (currentAction == MOVE) {
        Unit *selectedUnit = dynamic_cast<Unit *>(selectedEntity);
        bool successfulMove = move(coordPos, selectedUnit, buildingStore);
        if (successfulMove) {
            uiManager.clearUi();
            selectedUnit->setPosition(coordPos);
            selectedUnit->setFinishedTurn(true);
            currentAction = NONE;
            uiManager.clearUi();
            selectedEntity = NULL;
            unitStore.updatePossibleMoves(map, buildingStore, playerTurn);
            unitStore.updatePossibleAttacks(map, buildingStore, playerTurn);
            return;
        }
    }
    if (currentAction == ATTACK) {
        FightingUnit *selectedFightingUnit = dynamic_cast<FightingUnit *>(selectedEntity);
        bool successfulAttack = attack(coordPos, playerTurn, selectedFightingUnit, unitStore, buildingStore);
        if (successfulAttack) {
            uiManager.clearUi();
            selectedFightingUnit->setFinishedTurn(true);
            currentAction = NONE;
            selectedEntity = NULL;
            unitStore.updatePossibleMoves(map, buildingStore, playerTurn);
            unitStore.updatePossibleAttacks(map, buildingStore, playerTurn);
            return;
        }
    }
    if (currentAction == SELECT_UNIT_1 || currentAction == SELECT_UNIT_2 || currentAction == SELECT_UNIT_3 ||
        currentAction == SELECT_UNIT_4) {
        Building *currentBuilding = dynamic_cast<Building *>(selectedEntity);
        int unitIndex = 0;
        for (std::map<int, Action>::const_iterator k = selectUnit.begin(); k != selectUnit.end(); k++) {
            if (k->second == currentAction) {
                unitIndex = k->first;
                break;
            }
        }
        selectedEntity = currentBuilding->getGarrisonUnit(unitIndex);
        if (!selectedEntity->isFinishedTurn()) {
            uiManager.clearUi();
            uiManager.displayButton(selectedEntity);
            return;
        }
    }
    if (currentAction == UPGRADE) {
        Building *currentBuilding = dynamic_cast<Building *>(selectedEntity);
        currentBuilding->levelUp();
        return;
    }
    if (currentAction == BUILD_BARRACK || currentAction == BUILD_BRIDGE || currentAction == BUILD_DEFENSE_TURRET ||
        currentAction == BUILD_DRILL || currentAction == BUILD_EXTRACTOR) {
        bool successfulBuild = build(coordPos, playerTurn, selectedEntity, buildingStore, currentAction, map,
                                     mineralQuantity, gasQuantity);
        if (successfulBuild) {
            currentAction = NONE;
            selectedEntity->setFinishedTurn(true);
            uiManager.clearUi();
            return;
        }
    }
    // if no action was done, try to select a unit
    if (unitStore.selectUnit(coordPos, playerTurn, selectedEntity) ||
        buildingStore.selectBuilding(coordPos, playerTurn, selectedEntity)) {
        uiManager.clearUi();
        uiManager.displayButton(selectedEntity);
        currentAction = NONE;
    } else {
        uiManager.clearUi();
        currentAction = NONE;
        selectedEntity = NULL;
    }
}
