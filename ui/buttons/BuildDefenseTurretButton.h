#pragma once

#include "../UIComponent.h"
#include "../../util/const.h"

class BuildDefenseTurretButton : public UIComponent{
protected:
    void draw(const ResourceManager &resourceManager) const;
public:
    BuildDefenseTurretButton();
};
