#pragma once

#include "../UIComponent.h"
#include "../../util/const.h"

class RecruitBalisticButton : public UIComponent{
protected:
    void draw(const ResourceManager &resourceManager) const;
public:
    RecruitBalisticButton();
};
