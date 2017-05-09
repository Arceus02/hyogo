#pragma once

#include "../UIComponent.h"
#include "../../util/const.h"

class MoveButton : public UIComponent{
protected:
    void draw(const ResourceManager &resourceManager) const;
public:
    MoveButton();
    Action getAction()const;
};
