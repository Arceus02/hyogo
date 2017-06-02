#pragma once

#include "../ui/UIManager.h"
#include "../stores/BuildingManager.h"
#include "../stores/UnitManager.h"
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
    bool attack(const Vect2D &position, const Player player, FightingUnit *&selectedFU, UnitManager &unitStore,
                BuildingManager &buildingStore);

    bool build(const Vect2D &position, const Player player, Entity *&selectedBU, BuildingManager &buildingStore,
               Action &action, const Map &map, int &mineralQuantity, int &gasQuantity);

    bool
    move(const Vect2D &position, Unit *&unitToMove, BuildingManager &buildingStore);

    bool recruit(Player player, Action &currentAction, UnitManager &unitStore, Building*&selectedBuilding, int &mineralQuantity, int &gasQuantity);

public:
    void click(const Vect2D &coordPosition, Action &currentAction, const Player playerTurn, Entity *&selectedEntity,
               UnitManager &unitStore, BuildingManager &buildingStore, const Map &map, UIManager &uiManager,
               int &mineralQuantity, int &gasQuantity);
};
