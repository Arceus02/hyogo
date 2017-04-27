#include "Map.h"

Map::Map(int width, int height) : width(width), height(height) {
	for (int x = 0; x < width; x++)
		for (int y = 0; y < height; y++)
			this->terrainType.push_back(TERRAIN_MEADOW);
}

void Map::setTerrainType(int x, int y, TerrainType terrainType) {
	this->terrainType[x + y * this->width] = terrainType;
}

TerrainType Map::getTerrainType(int x, int y) {
	return this->terrainType[x + y * this->width];
}

void Map::addField(Field field) {
	this->fields.push_back(field);
}

bool Map::isField(int x, int y) {
	for (std::vector<Field>::iterator field = this->fields.begin(); field != this->fields.end(); field++)
		if ((*field).getX() == x && (*field).getY() == y)
			return true;
	return false;
}

Field Map::getField(int x, int y) {
	for (std::vector<Field>::iterator field = this->fields.begin(); field != this->fields.end(); field++)
		if ((*field).getX() == x && (*field).getY() == y)
			return *field;
	throw "No field found";
}

void Map::draw(Buffer &buffer, Vect2D viewOffset, Vect2D minRender, Vect2D maxRender) {
	// draw terrain
	for (int x = minRender.x; x < maxRender.x; x++) {
		for (int y = minRender.y; y < maxRender.y; y++) {
			for (int xi = 0; xi < MAP_SQUARE_PIXEL_SIZE; xi++) {
				for (int yi = 0; yi < MAP_SQUARE_PIXEL_SIZE; yi++) {
					int rX = (x - minRender.x) * MAP_SQUARE_PIXEL_SIZE + viewOffset.x % MAP_SQUARE_PIXEL_SIZE + xi;
					int rY = (y - minRender.y) * MAP_SQUARE_PIXEL_SIZE + viewOffset.y % MAP_SQUARE_PIXEL_SIZE + yi;
					if (0 <= rX && rX < buffer.getWidth() && 0 <= rY && rY < buffer.getHeight()) {
						TerrainType tempTerrainType = getTerrainType(x, y);
						Imagine::AlphaColor tempTerrainTypeColor = getTerrainTypeColor(tempTerrainType);
						buffer.set(rX, rY, tempTerrainTypeColor);
					}
				}
			}
		}
	}
	// TODO draw fields
}

const int Map::getWidth() {
	return this->width;
}

const int Map::getHeight() {
	return this->height;
}

Imagine::AlphaColor getTerrainTypeColor(TerrainType terrainType) {
	// TODO : change to sprite
	switch (terrainType) {
		case TERRAIN_MEADOW:
			return Imagine::AGREEN;
		case TERRAIN_FOREST:
			return Imagine::ARED;
		case TERRAIN_RIVER:
			return Imagine::ABLUE;
	}
	return Imagine::ABLACK;
}
