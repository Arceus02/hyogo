#pragma once

#include <Imagine/Graphics.h>
#include "util/const.h"
#include "util/Vect2D.h"
#include "stores/BuildingStore.h"
#include "stores/UnitStore.h"
#include "map/Map.h"
#include "map/MapGen.h"

using namespace Imagine;

class Game {
private:
	Window window;
	Vect2D viewOffset;
	BuildingStore buildingStore;
	UnitStore unitStore;
	Map map;
	bool playing;
    int mineralQuantity[2];
    int gasQuantity[2];

	void addViewOffset(Vect2D v);

	void logic();

	void draw();

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
