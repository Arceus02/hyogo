#include "Map.h"

AssetId getTerrainTypeAssetId(TerrainType terrainType) {
	switch (terrainType) {
		case MEADOW:
			return TERRAIN_MEADOW;
		case FOREST:
			return TERRAIN_FOREST;
		case RIVER:
			return TERRAIN_RIVER;
	}
	return TERRAIN_NONE;
}

Map::Map(int width, int height) : width(width), height(height) {
	for (int x = 0; x < width; x++)
		for (int y = 0; y < height; y++)
			this->terrainType.push_back(MEADOW);
}

void Map::setTerrainType(int x, int y, TerrainType terrainType) {
	this->terrainType[x + y * this->width] = terrainType;
}

TerrainType Map::getTerrainType(int x, int y) const {
	return this->terrainType[x + y * this->width];
}

void Map::addField(Field &field) {
	this->fields.push_back(field);
}

bool Map::isField(int x, int y) {
	for (std::vector<Field>::iterator field = this->fields.begin(); field != this->fields.end(); field++)
		if ((*field).getX() == x && (*field).getY() == y)
			return true;
	return false;
}

Field &Map::getField(int x, int y) {
	for (std::vector<Field>::iterator field = this->fields.begin(); field != this->fields.end(); field++)
		if ((*field).getX() == x && (*field).getY() == y)
			return *field;
	throw "No field found";
}

void Map::draw(const ResourceManager &resourceManager, const Vect2D &viewOffset, const Vect2D &minRender,
			   const Vect2D &maxRender) const {
	// draw terrain
    for (int x = minRender.x(); x < maxRender.x(); x++) {
        for (int y = minRender.y(); y < maxRender.y(); y++) {
            Vect2D rPos = {(x - minRender.x()) * MAP_SQUARE_PIXEL_SIZE + viewOffset.x() % MAP_SQUARE_PIXEL_SIZE,
                           (y - minRender.y()) * MAP_SQUARE_PIXEL_SIZE + viewOffset.y() % MAP_SQUARE_PIXEL_SIZE};
			TerrainType tempTerrainType = getTerrainType(x, y);
			AssetId tempAssetId = getTerrainTypeAssetId(tempTerrainType);
			resourceManager.getResource(tempAssetId).draw(rPos);
		}
	}
	// TODO draw fields
}

const int Map::getWidth() const {
	return this->width;
}

const int Map::getHeight() const {
	return this->height;
}

