#include "ActionManager.h"
#include "../util/fastMarching/fastMarching.h"

bool ActionManager::move(const Vect2D &position, Player player, Unit *&unitToMove, UnitStore &unitStore,
                         BuildingStore &buildingStore, const Map &map) {
    // Apply fast marching
    int maxDistance = unitToMove->getSpeed();

    int minXPos = (unitToMove->getPosition().x() - maxDistance > 0) ? unitToMove->getPosition().x() - maxDistance : 0;
    int minYPos = (unitToMove->getPosition().y() - maxDistance > 0) ? unitToMove->getPosition().y() - maxDistance : 0;
    int maxXPos = (unitToMove->getPosition().x() + maxDistance < map.getWidth()) ? unitToMove->getPosition().x() +
                                                                                   maxDistance : map.getWidth();
    int maxYPos = (unitToMove->getPosition().y() + maxDistance < map.getHeight()) ? unitToMove->getPosition().y() +
                                                                                    maxDistance : map.getHeight();

    Vect2D minPos(minXPos, minYPos), maxPos(maxXPos, maxYPos);
    if (!inside(position, minPos, maxPos))
        return false;

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
            } else if (unitStore.isUnit(pos)) {
                Player unitOwner;
                Unit &unit = unitStore.getUnit(pos, unitOwner);
                if (player != unitOwner) {
                    W(x, y) = INF;
                }
            }
            if (map.getTerrainType(x, y) == RIVER && !unitToMove->getCanWalkThroughRiver()) {
                W(x, y) = INF;
            }
        }
    }
    vector<PointDist> niv0;
    PointDist p0(unitToMove->getPosition().x() - minXPos, unitToMove->getPosition().y() - minYPos, 0);
    niv0.push_back(p0);
    Image<float> D = fastMarching(W, niv0);
    Vect2D moveVect = position - unitToMove->getPosition();
    return norm2(moveVect) <= D(position.x() - minXPos, position.y() - minYPos);
}

void ActionManager::attack(const Vect2D &position, const Player player, FightingUnit *&selectedFU, UnitStore &unitStore,
                           BuildingStore &buildingStore) {
    // TODO
}

bool
ActionManager::build(const Vect2D &position, const Player player, Entity *&selectedFU, BuildingStore &buildingStore,
                     Action &action, const Map &map, int &mineralQuantity, int &gasQuantity) {
    if(!buildingStore.isBuilding(position)){ //check if the worker isn't already in a building
        Building* buildingToBuild = 0;
        switch(map.getTerrainType(position.x(),position.y())){
        case RIVER://we can only build a bridge on a river
            if(action == BUILD_BRIDGE){
                buildingToBuild = static_cast<Bridge*>(buildingToBuild);
            }
            break;
        case MEADOW:
            switch(action){
            case BUILD_BARRACK:
                buildingToBuild = static_cast<Barrack*>(buildingToBuild);
                break;
            case BUILD_DEFENSE_TURRET:
                buildingToBuild = static_cast<DefenseTurret*>(buildingToBuild);
                break;
            case BUILD_DRILL:
                buildingToBuild = static_cast<Drill*>(buildingToBuild);
                break;
            case BUILD_EXTRACTOR:
                buildingToBuild = static_cast<Extractor*>(buildingToBuild);
                break;
            }
        default://we can't build on a FOREST
            break;

        }
        if(buildingToBuild !=0 && mineralQuantity >= BUILDING_MINERAL_COST.at(action)
                && gasQuantity >=BUILDING_GAS_COST.at(action)){//if the construction has been possible
            buildingToBuild->setGarnisonUnit(static_cast<Worker*>(selectedFU));
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
            bool successfulMove = move(coordPos, playerTurn, selectedUnit, unitStore, buildingStore, map);
            if (successfulMove) {
                uiManager.clearUi();
                selectedUnit->setPosition(coordPos);
                selectedUnit->setFinishedTurn(true);
                currentAction = NONE;
                uiManager.clearUi();
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
        default://build case
            bool successfulBuild = build(coordPos,playerTurn,selectedEntity,buildingStore,currentAction,map,mineralQuantity,gasQuantity);
            if(successfulBuild){
                currentAction = NONE;
                uiManager.clearUi();
            }
        break;
    }


}
