#pragma once

#include "../ui/UIManager.h"
#include "../stores/BuildingStore.h"
#include "../stores/UnitStore.h"
#include "../util/const.h"
#include "../util/Vect2D.h"
#include "../entities/Entity.h"
class ActionManager{
private:
    void move(const Vect2D &position,const Player player,Entity *&unitToMove,const UnitStore &unitStore,const BuildingStore &buildingStore);

    void attack(const Vect2D &position, const Player player, Entity *&selectedFU,UnitStore &unitStore, BuildingStore &buildingStore);

    void build(const Vect2D &position,const Player player,Entity *&selectedFU,BuildingStore &buildingStore);
public:
    void clickMap(const Vect2D &position, Action &currentAction, const Player playerTurn, Entity *&selectedEntity,
                    UnitStore &unitStore, BuildingStore &buildingStore,UIManager &uiManager);

};
