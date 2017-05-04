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

using namespace Imagine;

class Game {
private:
	Window window;
    Vect2D viewOffset;
	ResourceManager resourceManager;
	UIManager uiManager;
	BuildingStore buildingStore;
	UnitStore unitStore;
	Map map;
	bool playing;
	int playerTurn = 1;
    int mineralQuantity[2];
    int gasQuantity[2];

	void addViewOffset(const Vect2D &v);

	void logic();

	void draw(const ResourceManager &resourceManager) const;

	// TODO manage click
	// TODO click on UI
	// TODO click on Unit
	// TODO click on Map
	// TODO click on Building
	// TODO end turn
	// TODO update fog of war

public:
	Game();

	void play();
};
