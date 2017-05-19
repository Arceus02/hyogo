#pragma once

#include "../ui/UIManager.h"
#include "../stores/BuildingStore.h"
#include "../stores/UnitStore.h"
#include "../util/const.h"
#include "../util/Vect2D.h"
#include "../entities/Entity.h"

class ActionManager {
private:
    void attack(const Vect2D &position, const Player player, FightingUnit *&selectedFU, UnitStore &unitStore,
                BuildingStore &buildingStore);

    void build(const Vect2D &position, const Player player, Entity *&selectedFU, BuildingStore &buildingStore);

    bool
    move(const Vect2D &position, Player player, Unit *&unitToMove, UnitStore &unitStore, BuildingStore &buildingStore,
         const Map &map);

public:
    void clickMap(const Vect2D &pixelposition, Action &currentAction, const Player playerTurn, Entity *&selectedEntity,
                  UnitStore &unitStore, BuildingStore &buildingStore, const Map &map, UIManager &uiManager);
};
