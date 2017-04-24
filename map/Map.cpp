#include "Map.h"

Map::Map(int width, int height) : width(width), height(height), viewOffsetX(0), viewOffsetY(0) {
	for (int x = 0; x < width; x++)
		for (int y = 0; y < height; y++)
			this->terrainType.push_back(TERRAIN_MEADOW);
}

void Map::addViewOffset(int x, int y) {
	this->viewOffsetX += x;
	this->viewOffsetY += y;
	if (this->viewOffsetX > 0)
		this->viewOffsetX = 0;
	if (this->viewOffsetY > 0)
		this->viewOffsetY = 0;
	if (this->viewOffsetX + width * MAP_SQUARE_PIXEL_SIZE < WINDOW_WIDTH)
		this->viewOffsetX = -width * MAP_SQUARE_PIXEL_SIZE + WINDOW_WIDTH;
	if (this->viewOffsetY + height * MAP_SQUARE_PIXEL_SIZE < WINDOW_HEIGHT)
		this->viewOffsetY = -height * MAP_SQUARE_PIXEL_SIZE + WINDOW_HEIGHT;
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

void Map::draw(Buffer &buffer) {
	// draw terrain
	int minXRender = -viewOffsetX / MAP_SQUARE_PIXEL_SIZE;
	int maxXRender = WINDOW_WIDTH / MAP_SQUARE_PIXEL_SIZE + minXRender + 2;
	int minYRender = -viewOffsetY / MAP_SQUARE_PIXEL_SIZE;
	int maxYRender = WINDOW_HEIGHT / MAP_SQUARE_PIXEL_SIZE + minYRender + 2;
	minXRender = (minXRender < 0) ? 0 : minXRender;
	minYRender = (minYRender < 0) ? 0 : minYRender;
	maxXRender = (maxXRender > width) ? width : maxXRender;
	maxYRender = (maxYRender > height) ? height : maxYRender;
	for (int x = minXRender; x < maxXRender; x++) {
		for (int y = minYRender; y < maxYRender; y++) {
			for (int xi = 0; xi < MAP_SQUARE_PIXEL_SIZE; xi++) {
				for (int yi = 0; yi < MAP_SQUARE_PIXEL_SIZE; yi++) {
					int rX = (x - minXRender) * MAP_SQUARE_PIXEL_SIZE + viewOffsetX % MAP_SQUARE_PIXEL_SIZE + xi;
					int rY = (y - minYRender) * MAP_SQUARE_PIXEL_SIZE + viewOffsetY % MAP_SQUARE_PIXEL_SIZE + yi;
					if (0 <= rX && rX < buffer.getWidth() && 0 <= rY && rY < buffer.getHeight()) {
						TerrainType tempTerrainType = getTerrainType(x, y);
						Imagine::AlphaColor tempTerrainTypeColor = getTerrainTypeColor(tempTerrainType);
						buffer.set(rX, rY, tempTerrainTypeColor);
					}
				}
			}
		}
	}
	// TODO draw field
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
