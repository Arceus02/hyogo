#include "Asset.h"

Asset::Asset(std::string pathToAsset)
		: pathToAsset(pathToAsset) {
	load();
}

void Asset::load() {
	if (Imagine::loadAlphaColorImage(pathToAsset, map, w, h)) {
		std::cout << "Loaded : " << pathToAsset << std::endl;
	} else {
		std::cout << "Error can't load : " << pathToAsset << std::endl;
	}
}

void Asset::draw(Buffer &buffer, Vect2D position) const {
	for (int x = 0; x < w; x++) {
		for (int y = 0; y < h; y++) {
			int rX = position.x + x;
			int rY = position.y + y;
			if (0 <= rX && rX < buffer.getWidth() && 0 <= rY && rY < buffer.getHeight()) {
				Imagine::AlphaColor c = map[x + y * w];
				buffer.set(rX, rY, c);
			}
		}
	}
}

Asset::~Asset() {
	delete[] map;
}

std::string Asset::getPathToAsset() {
	return pathToAsset;
}