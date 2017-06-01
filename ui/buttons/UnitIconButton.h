#pragma once

#include "../UIComponent.h"
#include "../../util/const.h"
#include "../../entities/units/Unit.h"

class UnitIconButton : public UIComponent {
protected:
    void draw(const ResourceManager &resourceManager) const;

    Unit *unit = NULL;
    AssetId iconAssetId;
public:
    UnitIconButton(const Vect2D &position);

    void setUnit(Unit *unit);
};
