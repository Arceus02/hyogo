#pragma once

#include "Store.h"
#include "../entities/units/Unit.h"
#include "../entities/units/fightingUnits/FightingUnit.h"
#include "../entities/units/buildingUnits/Worker.h"
#include "BuildingStore.h"

using namespace std;

class UnitStore {
private:
    Store<Unit> player1Units, player2Units;
public:
    /// Draw map on screen
    /// \param player player whom it is the turn
    /// \param resourceManager ressource manager
    /// \param viewOffset map view render offset
    /// \param minRender min point to render
    /// \param maxRender max point to render
    void draw(Player player, const ResourceManager &resourceManager, const Vect2D &viewOffset, const Vect2D &minRender,
              const Vect2D &maxRender) const;

    /// Add a unit to a player
    /// \param player owner id
    /// \param unit unit to give to specified player
    void add(Player player, Unit &unit);

    /// Select a unit at specified coordinates
    /// \param coordCase case coordinates on map
    /// \param player player to select from
    /// \param selectedEntity reference to the pointer in Game instance to the currently selected entity
    /// \return if a unit has been successfully selected
    bool selectUnit(const Vect2D &coordCase, Player player, Entity *&selectedEntity);

    /// Get if there is a unit on the map at specified coordinates
    /// \param coordCase case coordinates on map
    /// \return wether or not there is a unit
    bool isUnit(const Vect2D &coordCase);

    /// Get a unit on the map
    /// \param coordCase case coordinates on map
    /// \param player modified to the selected unit owner id
    /// \return reference to unit at specified coordinates
    Unit &getUnit(const Vect2D coordCase, Player &player);

    void updatePossibleMoves(const Map &map, BuildingStore &buildingStore, Player player);

    void clearFinishedTurn();

    // TODO remove dead entities
    // TODO update entities' logic
};




