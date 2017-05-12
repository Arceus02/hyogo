#pragma once

#include "../UIComponent.h"
#include "../../util/const.h"

class BuildBridgeButton : public UIComponent{
protected:
    void draw(const ResourceManager &resourceManager) const;
public:
    BuildBridgeButton();
};
