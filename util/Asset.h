#pragma once

#include<Imagine/Graphics.h>
#include<string>
#include "Vect2D.h"

class Asset {
private:
	std::string pathToAsset;
	int w, h;
	Imagine::AlphaColor *map;
public:
	Asset();

	Asset(const std::string &pathToAsset);

	void draw(const Vect2D &position) const;

	~Asset();
};