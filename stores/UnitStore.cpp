#include "UnitStore.h"

void UnitStore::draw(int player, const ResourceManager &resourceManager, const Vect2D &viewOffset,
					 const Vect2D &minRender, const Vect2D &maxRender) const {
	if (player == 1) {
		player1Units.draw(resourceManager, viewOffset, minRender, maxRender);
	} else if (player == 2) {
		player2Units.draw(resourceManager, viewOffset, minRender, maxRender);
	}
}

void UnitStore::add(int player, Unit &unit) {
	if (player == 1) {
		player1Units.add(unit);
	} else if (player == 2) {
		player2Units.add(unit);
	}
}
