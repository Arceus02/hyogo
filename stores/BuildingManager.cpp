#include "BuildingManager.h"

void BuildingManager::draw(Player currentTurn, const ResourceManager &resourceManager, const Vect2D &viewOffset,
                           const Vect2D &minRender, const Vect2D &maxRender) const {
    player1Buildings.draw(resourceManager, viewOffset, minRender, maxRender, currentTurn);
    player2Buildings.draw(resourceManager, viewOffset, minRender, maxRender, currentTurn);
}

void BuildingManager::add(Player player, Building *building) {
    building->setOwner(player);
    if (player == PLAYER1) {
        player1Buildings.add(building);
    } else if (player == PLAYER2) {
        player2Buildings.add(building);
    }
}

// Position is from the mouse
bool BuildingManager::selectBuilding(const Vect2D &coordCase, Player player, Entity *&selectedEntity) {
    Store<Building *> *buildingVector = (player == PLAYER1) ? &player1Buildings : &player2Buildings;
    for (std::vector<Building *>::iterator it = buildingVector->getList().begin();
         it != buildingVector->getList().end(); ++it) {
        if ((*it)->getPosition().x() == coordCase.x() && (*it)->getPosition().y() == coordCase.y()) {
            selectedEntity = (*it);
            return true;
        }
    }
    return false;
}

// Position is from the
bool BuildingManager::isBuilding(const Vect2D &coordCase) {
    for (std::vector<Building *>::iterator it = player1Buildings.getList().begin();
         it != player1Buildings.getList().end(); ++it) {
        if ((*it)->getPosition().x() == coordCase.x() && (*it)->getPosition().y() == coordCase.y()) {
            return true;
        }
    }
    for (std::vector<Building *>::iterator it = player2Buildings.getList().begin();
         it != player2Buildings.getList().end(); ++it) {
        if ((*it)->getPosition().x() == coordCase.x() && (*it)->getPosition().y() == coordCase.y()) {
            return true;
        }
    }
    return false;
}

Building &BuildingManager::getBuilding(const Vect2D &coordCase, Player &player) {
    assert(isBuilding(coordCase));
    for (std::vector<Building *>::iterator it = player1Buildings.getList().begin();
         it != player1Buildings.getList().end(); ++it) {
        if ((*it)->getPosition().x() == coordCase.x() && (*it)->getPosition().y() == coordCase.y()) {
            player = PLAYER1;
            return *(*it);
        }
    }
    for (std::vector<Building *>::iterator it = player2Buildings.getList().begin();
         it != player2Buildings.getList().end(); ++it) {
        if ((*it)->getPosition().x() == coordCase.x() && (*it)->getPosition().y() == coordCase.y()) {
            player = PLAYER2;
            return *(*it);
        }
    }
}

void BuildingManager::buildBuildingUnderConstruction(const Player player) {
    if (player == PLAYER1) {
        for (std::vector<Building *>::iterator it = player1Buildings.getList().begin();
             it != player1Buildings.getList().end(); ++it) {
            (*it)->build();
        }
    } else {
        for (std::vector<Building *>::iterator it = player2Buildings.getList().begin();
             it != player2Buildings.getList().end(); ++it) {
            (*it)->build();
        }
    }
}

void BuildingManager::collectRessources(const Player player, int &mineralQuantity, int &gasQuantity) {
    Store<Building *> &playerBuildings = (player == PLAYER1) ? player1Buildings : player2Buildings;
    for (std::vector<Building *>::iterator it = playerBuildings.getList().begin();
         it != playerBuildings.getList().end(); ++it) {
        if ((*it)->getAssetId() == BUILDING_DRILL && (*it)->getTurnNumberToBeBuilt() == 0) {
            Drill *drill = dynamic_cast<Drill *>((*it));
            mineralQuantity += drill->getProduction();
        } else if ((*it)->getAssetId() == BUILDING_EXTRACTOR && (*it)->getTurnNumberToBeBuilt() == 0) {
            Extractor *extractor = dynamic_cast<Extractor *>((*it));
            gasQuantity += extractor->getProduction();
        }
    }
}


