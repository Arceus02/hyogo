#pragma once

#include <Imagine/Graphics.h>
#include "util/const.h"
#include "util/Vect2D.h"
#include "stores/BuildingStore.h"
#include "stores/UnitStore.h"
#include "map/Map.h"
#include "map/MapGen.h"
#include "ui/UIManager.h"
#include "util/ResourceManager.h"
#include "actions/ActionManager.h"

using namespace Imagine;

class Game {
private:
    Window window;
    Vect2D viewOffset;
    ResourceManager resourceManager;
    UIManager uiManager;
    ActionManager actionManager;
    BuildingStore buildingStore;
    UnitStore unitStore;
    Map map;
    bool playing;
    Player playerTurn = PLAYER1;
    bool isEntitySelected = false;
    Entity *selectedEntity = NULL;
    Action currentAction = NONE;
    int mineralQuantity[2];
    int gasQuantity[2];

    /// Move map view offset
    /// \param v deplacement vector
    void addViewOffset(const Vect2D &v);

    /// Logic handler for the game (event handling and animation)
    void logic();
    // TODO update fog of war

    /// Handle click
    /// \param position pixel position
    void clickManager(const Vect2D &position);

    /// Draw map, ui and everything on screen
    /// \param resourceManager
    void draw(const ResourceManager &resourceManager) const;

public:
    Game();

    /// Main function to call once
    void play();
};
