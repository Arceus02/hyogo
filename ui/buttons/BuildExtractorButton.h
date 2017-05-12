#pragma once

#include "../UIComponent.h"
#include "../../util/const.h"

class BuildExtractorButton : public UIComponent{
protected:
    void draw(const ResourceManager &resourceManager) const;
public:
    BuildExtractorButton();
};
