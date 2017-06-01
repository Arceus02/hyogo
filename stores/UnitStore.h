#pragma once

#include "../entities/units/Unit.h"
#include "Store.h"

class UnitStore : public Store<Unit *> {
public:
    void draw(const ResourceManager &resourceManager, const Vect2D &viewOffset, const Vect2D &minXRender,
              const Vect2D &maxXRender) const;
};