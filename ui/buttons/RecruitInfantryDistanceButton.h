#pragma once

#include "../UIComponent.h"
#include "../../util/const.h"

class RecruitInfantryDistanceButton : public UIComponent{
protected:
    void draw(const ResourceManager &resourceManager) const;
public:
    RecruitInfantryDistanceButton();
};

