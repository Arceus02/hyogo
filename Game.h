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

	void addViewOffset(Vect2D v);

	void logic();

	void draw();

public:
	Game();

	// TODO main menu
	void play();
};