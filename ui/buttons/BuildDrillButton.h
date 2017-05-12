#pragma once

#include "../UIComponent.h"
#include "../../util/const.h"

class BuildDrillButton : public UIComponent{
protected:
    void draw(const ResourceManager &resourceManager) const;
public:
    BuildDrillButton();
};
