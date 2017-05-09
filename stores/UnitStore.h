#pragma once

#include "Store.h"
#include "../entities/units/Unit.h"
#include "../entities/units/fightingUnits/FightingUnit.h"
#include "../entities/units/buildingUnits/Worker.h"

using namespace std;

class UnitStore {
private:
	Store<Unit> player1Units, player2Units;
public:
    void draw(Player player, const ResourceManager &resourceManager, const Vect2D &viewOffset, const Vect2D &minRender,
			  const Vect2D &maxRender) const;

    void add(Player player, Unit &unit);

    bool isUnit(const Vect2D &position, Player player,Entity *&selectedEntity);

	// TODO remove dead entities
	// TODO update entities' logic
};




