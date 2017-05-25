#pragma once

#include "../../util/ResourceManager.h"
#include "../UIComponent.h"

class EndTurnButton : public UIComponent {
public:
    EndTurnButton();

    void draw(const ResourceManager &resourceManager) const;
};