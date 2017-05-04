#pragma once

#include "Store.h"
#include "../entities/units/Unit.h"
#include "../entities/units/fightingUnits/FightingUnit.h"

using namespace std;

class UnitStore {
private:
	Store<Unit> player1Units, player2Units;
public:
	void draw(int player, const ResourceManager &resourceManager, const Vect2D &viewOffset, const Vect2D &minRender,
			  const Vect2D &maxRender) const;

	void add(int player, Unit &unit);
	// TODO remove dead entities
	// TODO update entities' logic
};




