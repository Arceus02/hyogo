#pragma once

#include "Store.h"
#include "../entities/buildings/Building.h"

class BuildingStore : public Store<Building> {
private:
	Store<Building> player1Buildings, player2Buildings;
public:
	void draw(int player, const ResourceManager &resourceManager, const Vect2D &viewOffset, const Vect2D &minRender,
			  const Vect2D &maxRender) const;

	void add(int player, Building &building);

    bool isBuilding(const Vect2D &position, Player player,Entity *&selectedEntity);
	// TODO remove dead entities
	// TODO update entities' logic
};
