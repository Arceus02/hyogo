#pragma once

#include "../UIComponent.h"
#include "../../util/const.h"

class AttackButton : public UIComponent{
protected:
    void draw(const ResourceManager &resourceManager) const;
public:
    AttackButton();
    Action getAction()const;
};
