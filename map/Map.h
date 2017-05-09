#pragma once

#include "Field.h"
#include <vector>
#include "../util/const.h"
#include "../util/Vect2D.h"
#include "../util/Asset.h"
#include "../util/ResourceManager.h"
#include <Imagine/Graphics.h>



enum TerrainType {
	MEADOW, FOREST, RIVER
};

AssetId getTerrainTypeAssetId(TerrainType terrainType);

class Map {
private:
	int width, height;
	std::vector<TerrainType> terrainType;
	std::vector<Field> fields;
public:
	Map(int width, int height);

	void setTerrainType(int x, int y, TerrainType terrainType);

	TerrainType getTerrainType(int x, int y) const;

	void addField(Field &field);

	bool isField(int x, int y);

	Field &getField(int x, int y);

	void draw(const ResourceManager &resourceManager, const Vect2D &viewOffset, const Vect2D &minRender,
			  const Vect2D &maxRender) const;

	const int getWidth() const;

	const int getHeight() const;
};
