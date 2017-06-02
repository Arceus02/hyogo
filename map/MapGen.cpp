#include "MapGen.h"

Map MapGen::testMapGenerator(int width, int height) {
	Map map = Map(width, height);
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			TerrainType terrainType;
			if (y < height / 3)
				terrainType = MEADOW;
			else if (y < height / 2)
				terrainType = FOREST;
			else
				terrainType = RIVER;
			map.setTerrainType(x, y, terrainType);
		}
	}
	return map;
}

Map MapGen::uniformRandomMapGenerator(int width, int height) {
	Map map = Map(width, height);
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
            int rNum = rand() % 100;
			TerrainType terrainType;
            if (rNum < 70)
				terrainType = MEADOW;
            else if (rNum < 90)
				terrainType = FOREST;
			else
				terrainType = RIVER;
			map.setTerrainType(x, y, terrainType);
		}
	}
	return map;
}