#pragma once

#include "../UIComponent.h"
#include "../../util/const.h"

class BuildButton : public UIComponent{
protected:
    void draw(const ResourceManager &resourceManager) const;
public:
    BuildButton();
    Action getAction()const;
};
