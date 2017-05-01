#pragma once

#include "Map.h"

namespace MapGen {

	Map testMapGenerator(int width, int height);

	Map uniformRandomMapGenerator(int width, int height);

	// TODO random noised map
}