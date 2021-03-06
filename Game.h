#pragma once

#include <Imagine/Graphics.h>
#include "util/const.h"
#include "util/Vect2D.h"
#include "stores/BuildingManager.h"
#include "stores/UnitManager.h"
#include "map/Map.h"
#include "map/MapGen.h"
#include "ui/UIManager.h"
#include "util/ResourceManager.h"
#include "actions/ActionManager.h"

using namespace Imagine;

class Game {
private:
    Window window;
    Vect2D *viewOffset;
    Vect2D viewOffset1, viewOffset2;
    ResourceManager resourceManager;
    UIManager uiManager;
    ActionManager actionManager;
    BuildingManager buildingStore;
    UnitManager unitStore;
    Map map;
    bool playing;
    Player playerTurn = PLAYER1;
    Entity *selectedEntity = NULL;
    Action currentAction = NONE;
    std::map<Player, int> mineralQuantity;
    std::map<Player, int> gasQuantity;
    CommandCenter *commandCenter1;
    CommandCenter *commandCenter2;

    /// Move map view offset
    /// \param v deplacement vector
    void addViewOffset(const Vect2D &v);

    /// Logic handler for the game (event handling and animation)
    void logic();

    /// Handle click
    /// \param position pixel position
    void clickManager(const Vect2D &position);

    /// Draw map, ui and everything on screen
    /// \param resourceManager
    void draw(const ResourceManager &resourceManager) const;

    void testGameFinished();

public:
    Game();

    ~Game();

    /// Main function to call once
    void play();

    void endTurn();
};
