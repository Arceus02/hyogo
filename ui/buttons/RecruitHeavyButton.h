#pragma once

#include "../UIComponent.h"
#include "../../util/const.h"

class RecruitHeavyButton : public UIComponent{
protected:
    void draw(const ResourceManager &resourceManager) const;
public:
    RecruitHeavyButton();
};
