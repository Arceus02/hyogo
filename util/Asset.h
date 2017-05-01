#pragma once

#include<Imagine/Graphics.h>
#include<string>
#include "Buffer.h"
#include "Vect2D.h"

class Asset {
private:
	std::string pathToAsset;
	int w, h;
	Imagine::AlphaColor *map;
public:
	Asset(std::string pathToAsset);

	void load();

	void draw(Buffer &buffer, Vect2D position) const;

	std::string getPathToAsset();

	~Asset();
};