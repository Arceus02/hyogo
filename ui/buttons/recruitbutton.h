#pragma once

#include "../UIComponent.h"
#include "../../util/const.h"

class RecruitButton : public UIComponent{
protected:
    void draw(const ResourceManager &resourceManager) const;
public:
    RecruitButton();
};
