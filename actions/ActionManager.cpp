#include "ActionManager.h"

void ActionManager::move(const Vect2D &position, const Player player, Entity *&unitToMove, const UnitStore &unitStore, const BuildingStore &buildingStore){

}
void ActionManager::attack(const Vect2D &position,const Player player,Entity *&selectedFU,UnitStore &unitStore, BuildingStore &buildingStore){

}
void ActionManager::build(const Vect2D &position,const Player player,Entity *&selectedFU,BuildingStore &buildingStore){

}
void ActionManager::clickMap(const Vect2D &position, Action &currentAction, const Player playerTurn, Entity *&selectedEntity,
                UnitStore &unitStore,  BuildingStore& buildingStore, UIManager &uiManager){
   switch(currentAction){
       case MOVE:
           move(position,playerTurn,selectedEntity,unitStore,buildingStore);
       break;
       case ATTACK:
           attack(position,playerTurn,selectedEntity,unitStore,buildingStore);
       break;
       case NONE:
           if(unitStore.isUnit(position,playerTurn,selectedEntity)
                   || buildingStore.isBuilding(position,playerTurn,selectedEntity))//Player clicked on a case which contains
                                                                //either a unit or a building so we change selected unit
               uiManager.displayButton(selectedEntity->getType());
           else{
               uiManager.clearUi();
           }
        break;
   }
}
