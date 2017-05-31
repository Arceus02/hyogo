#pragma once

#include "../ui/UIManager.h"
#include "../stores/BuildingStore.h"
#include "../stores/UnitStore.h"
#include "../util/const.h"
#include "../util/Vect2D.h"
#include "../entities/Entity.h"
#include "../entities/buildings/Barrack.h"
#include "../entities/buildings/Bridge.h"
#include "../entities/buildings/CommandCenter.h"
#include "../entities/buildings/DefenseTurret.h"
#include "../entities/buildings/Drill.h"
#include "../entities/buildings/Extractor.h"

class ActionManager {
private:
    void attack(const Vect2D &position, const Player player, FightingUnit *&selectedFU, UnitStore &unitStore,
                BuildingStore &buildingStore);

    bool build(const Vect2D &position, const Player player, Entity *&selectedFU, BuildingStore &buildingStore,
               Action &action, const Map &map, int &mineralQuantity, int &gasQuantity);

    bool
    move(const Vect2D &position, Unit *&unitToMove, BuildingStore &buildingStore);

public:
    void clickMap(const Vect2D &pixelposition, Action &currentAction, const Player playerTurn, Entity *&selectedEntity,
                  UnitStore &unitStore, BuildingStore &buildingStore, const Map &map, UIManager &uiManager,
                  int &mineralQuantity, int &gasQuantity);
};
