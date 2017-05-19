#pragma once

#include "Store.h"
#include "../entities/buildings/Building.h"

class BuildingStore : public Store<Building> {
private:
    Store<Building> player1Buildings, player2Buildings;
public:
    /// Draw map on screen
    /// \param player player whom it is the turn
    /// \param resourceManager ressource manager
    /// \param viewOffset map view render offset
    /// \param minRender min point to render
    /// \param maxRender max point to render
    void draw(int player, const ResourceManager &resourceManager, const Vect2D &viewOffset, const Vect2D &minRender,
              const Vect2D &maxRender) const;

    /// Add a building to a player
    /// \param player
    /// \param building
    void add(int player, Building &building);

    /// Select a building at specified coordinates
    /// \param coordCase
    /// \param player
    /// \param selectedEntity
    /// \return
    bool selectBuilding(const Vect2D &coordCase, Player player, Entity *&selectedEntity);

    /// Get if there is a building on the map at specified coordinates
    /// \param coordCase
    /// \return
    bool isBuilding(const Vect2D &coordCase);

    /// Get a unit on the map
    /// \param coordCase
    /// \param player
    /// \return
    Building &getBuilding(const Vect2D &coordCase, Player &player);
    // TODO remove dead entities
    // TODO update entities' logic;
};