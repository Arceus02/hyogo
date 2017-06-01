#pragma once

#include "../UIComponent.h"
#include "../../util/const.h"

class UpgradeButton : public UIComponent{
protected:
    void draw(const ResourceManager &resourceManager) const;
public:
    UpgradeButton();
};
