#include "ActionManager.h"

bool ActionManager::move(const Vect2D &position,Unit *&unitToMove, BuildingStore &buildingStore) {
    if (unitToMove->isPossibleMove(position)) {
        if(unitToMove->getIsInGarrison()){//if the unit was in garrison in a building we get it out
            unitToMove->setInGarrison(false);
            Player unitOwner = unitToMove->getOwner();
            buildingStore.getBuilding(unitToMove->getPosition(),unitOwner).removeUnitGarrison(unitToMove->getAssetId());
        }
        unitToMove->setPosition(position);
        if(buildingStore.isBuilding(position)){
            unitToMove->setInGarrison(true);
            Player unitOwner = unitToMove->getOwner();
            buildingStore.getBuilding(unitToMove->getPosition(),unitOwner).addGarrisonUnit(unitToMove);
        }
        unitToMove->setFinishedTurn(true);
        return true;
    }
    return false;
}

void ActionManager::attack(const Vect2D &position, const Player player, FightingUnit *&selectedFU, UnitStore &unitStore,
                           BuildingStore &buildingStore) {

}


bool
ActionManager::build(const Vect2D &position, const Player player, Entity *&selectedFU, BuildingStore &buildingStore,
                     Action &action, const Map &map, int &mineralQuantity, int &gasQuantity) {
    if(!buildingStore.isBuilding(position)){ //check if the worker isn't already in a building
        Building* buildingToBuild=0;
        switch(map.getTerrainType(position.x(),position.y())){
        case RIVER://we can only build a bridge on a river
            if(action == BUILD_BRIDGE){
                Bridge* bridge = new Bridge();
                buildingToBuild = bridge;
            }
            break;
        case MEADOW:
            switch(action){
            case BUILD_BARRACK:
            {
                Barrack* barrack = new Barrack();
                buildingToBuild = barrack;
                break;
            }
            case BUILD_DEFENSE_TURRET:
            {
                DefenseTurret* defenseTurret = new DefenseTurret();
                buildingToBuild = defenseTurret;
                break;
            }
            case BUILD_DRILL:
            {
                Drill* drill = new Drill();
                buildingToBuild = drill;
                break;
            }
            case BUILD_EXTRACTOR:
            {
                Extractor* extractor = new Extractor();
                buildingToBuild = extractor;
                break;
            }
            }
        default://we can't build on a FOREST
            break;

        }
        if(buildingToBuild!=0 && mineralQuantity >= BUILDING_MINERAL_COST.at(action)
                && gasQuantity >=BUILDING_GAS_COST.at(action)){//if the construction has been possible
            buildingToBuild->addGarrisonUnit(static_cast<Worker*>(selectedFU));
            buildingToBuild->setPosition(position);
            buildingStore.add(player,*buildingToBuild);
            mineralQuantity -= BUILDING_MINERAL_COST.at(action);
            gasQuantity -= BUILDING_GAS_COST.at(action);
            return true;
        }
    }
    return false;
}

void
ActionManager::clickMap(const Vect2D &coordPos, Action &currentAction, const Player playerTurn, Entity *&selectedEntity,
                        UnitStore &unitStore, BuildingStore &buildingStore, const Map &map, UIManager &uiManager,
                        int& mineralQuantity, int& gasQuantity) {

    switch (currentAction) {
        case MOVE: {
            Unit *selectedUnit = static_cast<Unit *>(selectedEntity);
            bool successfulMove = move(coordPos,selectedUnit,buildingStore);
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
        case SELECT_UNIT_1:case SELECT_UNIT_2:case SELECT_UNIT_3:case SELECT_UNIT_4:
        {
            Building *currentBuilding = static_cast<Building*>(selectedEntity);
            int unitIndex;
            for (std::map<int, Action>::const_iterator k = selectUnit.begin(); k != selectUnit.end(); k++) {
                if (k->second == currentAction)
                    unitIndex = k->first;
            }
            selectedEntity = currentBuilding->getGarrisonUnit(unitIndex);
            uiManager.clearUi();
            uiManager.displayButton(selectedEntity);
            break;
        }
        case UPGRADE:
        {
            Building *currentBuilding = static_cast<Building*>(selectedEntity);
            currentBuilding->levelUp();
        }
        case NONE: {
            if (unitStore.selectUnit(coordPos, playerTurn, selectedEntity) ||
                buildingStore.selectBuilding(coordPos, playerTurn, selectedEntity)) {
                uiManager.clearUi();
                uiManager.displayButton(selectedEntity);
            } else {
                uiManager.clearUi();
                selectedEntity = NULL;
            }
        }
            break;
        default://build case
            bool successfulBuild = build(coordPos,playerTurn,selectedEntity,buildingStore,currentAction,map,mineralQuantity,gasQuantity);
            if(successfulBuild){
                currentAction = NONE;
                selectedEntity->setFinishedTurn(true);
                uiManager.clearUi();
            }
        break;
    }
}
