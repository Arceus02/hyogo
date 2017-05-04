#include "Asset.h"

Asset::Asset() : pathToAsset("NONE") {}

Asset::Asset(const std::string &pathToAsset) : pathToAsset(pathToAsset) {
	if (Imagine::loadAlphaColorImage(pathToAsset, map, w, h)) {
		std::cout << "Loaded : " << pathToAsset << std::endl;
	} else {
		std::cout << "Error can't load : " << pathToAsset << std::endl;
	}
}

void Asset::draw(const Vect2D &position) const {
    Imagine::putAlphaColorImage(position.x(), position.y(), map, w, h);
}

Asset::~Asset() {
	delete[] map;
}
