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

bool UnitStore::selectUnit(const Vect2D &coordCase, Player player, Entity *&selectedEntity) {
    Store <Unit> *unitVector = (player == PLAYER1)?&player1Units:&player2Units;
    for(std::vector<Unit>::iterator it=unitVector->getList().begin();it!=unitVector->getList().end();++it){
        if((*it).getPosition().x() == coordCase.x() && (*it).getPosition().y() == coordCase.y()){
            selectedEntity = &(*it);
            return true;
        }
    }
    return false;
}

bool UnitStore::isUnit(const Vect2D &coordCase) {
    for (std::vector<Unit>::iterator it = player1Units.getList().begin();
         it != player1Units.getList().end(); ++it) {
        if ((*it).getPosition().x() == coordCase.x() && (*it).getPosition().y() == coordCase.y()) {
            return true;
        }
    }
    for (std::vector<Unit>::iterator it = player2Units.getList().begin();
         it != player2Units.getList().end(); ++it) {
        if ((*it).getPosition().x() == coordCase.x() && (*it).getPosition().y() == coordCase.y()) {
            return true;
        }
    }
    return false;
}

Unit &UnitStore::getUnit(const Vect2D coordCase, Player &player) {
    assert(isUnit(coordCase));
    for (std::vector<Unit>::iterator it = player1Units.getList().begin();
         it != player1Units.getList().end(); ++it) {
        if ((*it).getPosition().x() == coordCase.x() && (*it).getPosition().y() == coordCase.y()) {
            player = PLAYER1;
            return (*it);
        }
    }
    for (std::vector<Unit>::iterator it = player2Units.getList().begin();
         it != player2Units.getList().end(); ++it) {
        if ((*it).getPosition().x() == coordCase.x() && (*it).getPosition().y() == coordCase.y()) {
            player = PLAYER2;
            return (*it);
        }
    }
}
