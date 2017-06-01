#pragma once

#include "../UIComponent.h"
#include "../../util/const.h"

class RecruitScoutButton : public UIComponent{
protected:
    void draw(const ResourceManager &resourceManager) const;
public:
    RecruitScoutButton();
};
