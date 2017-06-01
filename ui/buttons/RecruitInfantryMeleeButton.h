#pragma once

#include "../UIComponent.h"
#include "../../util/const.h"

class RecruitInfantryMeleeButton : public UIComponent{
protected:
    void draw(const ResourceManager &resourceManager) const;
public:
    RecruitInfantryMeleeButton();
};
