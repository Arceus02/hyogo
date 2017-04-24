#pragma once

#include <Imagine/Graphics.h>
#include "stores/BuildingStore.h"
#include "stores/UnitStore.h"
#include "map/Map.h"
#include "util/const.h"
#include "map/MapGen.h"

using namespace Imagine;

class Game {
public:
	Game();

	// void mainMenu();
	void play();
	// ~Game();
private:
	void logic();

	void draw();

	Window window;
	BuildingStore buildingStore;
	UnitStore unitStore;
	Map map;
	bool playing;
};