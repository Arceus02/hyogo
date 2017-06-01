#pragma once

#include "../UIComponent.h"
#include "../../util/const.h"

class RecruitCavalryButton : public UIComponent{
protected:
    void draw(const ResourceManager &resourceManager) const;
public:
    RecruitCavalryButton();
};
