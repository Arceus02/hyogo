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

// Position is from the mouse
bool BuildingStore::selectBuilding(const Vect2D &coordCase, Player player, Entity *&selectedEntity) {
    Store<Building> *buildingVector = (player == PLAYER1) ? &player1Buildings : &player2Buildings;

    for (std::vector<Building>::iterator it = buildingVector->getList().begin();
         it != buildingVector->getList().end(); ++it) {
        if ((*it).getPosition().x() == coordCase.x() && (*it).getPosition().y() == coordCase.y()) {
            selectedEntity = &(*it);
            return true;
        }
    }
    return false;
}

// Position is from the
bool BuildingStore::isBuilding(const Vect2D &coordCase) {
    for (std::vector<Building>::iterator it = player1Buildings.getList().begin();
         it != player1Buildings.getList().end(); ++it) {
        if ((*it).getPosition().x() == coordCase.x() && (*it).getPosition().y() == coordCase.y()) {
            return true;
        }
    }
    for (std::vector<Building>::iterator it = player2Buildings.getList().begin();
         it != player2Buildings.getList().end(); ++it) {
        if ((*it).getPosition().x() == coordCase.x() && (*it).getPosition().y() == coordCase.y()) {
            return true;
        }
    }
    return false;
}

Building &BuildingStore::getBuilding(const Vect2D &coordCase, Player &player) {
    assert(isBuilding(coordCase));
    for (std::vector<Building>::iterator it = player1Buildings.getList().begin();
         it != player1Buildings.getList().end(); ++it) {
        if ((*it).getPosition().x() == coordCase.x() && (*it).getPosition().y() == coordCase.y()) {
            player = PLAYER1;
            return (*it);
        }
    }
    for (std::vector<Building>::iterator it = player2Buildings.getList().begin();
         it != player2Buildings.getList().end(); ++it) {
        if ((*it).getPosition().x() == coordCase.x() && (*it).getPosition().y() == coordCase.y()) {
            player = PLAYER2;
            return (*it);
        }
    }
}
