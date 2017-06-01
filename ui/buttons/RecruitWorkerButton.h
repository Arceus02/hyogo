#pragma once

#include "../UIComponent.h"
#include "../../util/const.h"

class RecruitWorkerButton : public UIComponent{
protected:
    void draw(const ResourceManager &resourceManager) const;
public:
    RecruitWorkerButton();
};

