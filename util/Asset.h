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
    /// Load asset from path
    Asset(const std::string &pathToAsset);

    /// Draw asset to position
    void draw(const Vect2D &position) const;

    ~Asset();
};