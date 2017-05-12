#pragma once

#include "../UIComponent.h"
#include "../../util/const.h"

class BuildBarrackButton : public UIComponent{
protected:
    void draw(const ResourceManager &resourceManager) const;
public:
    BuildBarrackButton();
};
