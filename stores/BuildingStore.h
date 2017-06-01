#pragma once

#include "Store.h"
#include "../entities/buildings/Building.h"

class BuildingStore : public Store<Building *> {
public:
    void draw(const ResourceManager &resourceManager, const Vect2D &viewOffset, const Vect2D &minRender,
              const Vect2D &maxRender, const Player currentTurn) const;
};
