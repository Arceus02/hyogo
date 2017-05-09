#include "UnitStore.h"

void UnitStore::draw(Player player, const ResourceManager &resourceManager, const Vect2D &viewOffset,
                     const Vect2D &minRender, const Vect2D &maxRender) const {
    if (player == PLAYER1) {
		player1Units.draw(resourceManager, viewOffset, minRender, maxRender);
    } else if (player == PLAYER2) {
		player2Units.draw(resourceManager, viewOffset, minRender, maxRender);
	}
}

void UnitStore::add(Player player, Unit &unit) {
    if (player == PLAYER1) {
		player1Units.add(unit);
    } else if (player == PLAYER2) {
		player2Units.add(unit);
	}

}
bool UnitStore::isUnit(const Vect2D &position, Player player,Entity *&selectedEntity){
    Vect2D coordCase;
    coordCase.x() = (position.x()-position.x()%MAP_SQUARE_PIXEL_SIZE)/MAP_SQUARE_PIXEL_SIZE ;
    coordCase.y() = (position.y()-position.y()%MAP_SQUARE_PIXEL_SIZE)/MAP_SQUARE_PIXEL_SIZE;
    Store <Unit> *unitVector = (player == PLAYER1)?&player1Units:&player2Units;
    for(std::vector<Unit>::iterator it=unitVector->getList().begin();it!=unitVector->getList().end();++it){
        if((*it).getPosition().x() == coordCase.x() && (*it).getPosition().y() == coordCase.y()){

            selectedEntity = &(*it);
            return true;
        }
    }
    return false;
}
