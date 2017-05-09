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
bool BuildingStore::isBuilding(const Vect2D &position, Player player,Entity *&selectedEntity){
    Vect2D coordCase;
    coordCase.x() = (position.x()-position.x()%MAP_SQUARE_PIXEL_SIZE)/MAP_SQUARE_PIXEL_SIZE;
    coordCase.y() = (position.y()-position.y()%MAP_SQUARE_PIXEL_SIZE)/MAP_SQUARE_PIXEL_SIZE;

    Store <Building> *buildingVector = (player == PLAYER1)?&player1Buildings:&player2Buildings;

    for(std::vector<Building>::iterator it=buildingVector->getList().begin();it!=buildingVector->getList().end();++it){
        if((*it).getPosition().x() == coordCase.x() && (*it).getPosition().y() == coordCase.y())
            selectedEntity = &(*it);
            return true;
    }
    return false;
}
