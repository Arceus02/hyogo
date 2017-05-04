#include "BuildingStore.h"

void BuildingStore::draw(int player, const ResourceManager &resourceManager, const Vect2D &viewOffset,
						 const Vect2D &minRender, const Vect2D &maxRender) const {
	if (player == 1) {
		player1Buildings.draw(resourceManager, viewOffset, minRender, maxRender);
	} else if (player == 2) {
		player2Buildings.draw(resourceManager, viewOffset, minRender, maxRender);
	}
}

void BuildingStore::add(int player, Building &building) {
	if (player == 1) {
		player1Buildings.add(building);
	} else if (player == 2) {
		player2Buildings.add(building);
	}
}
