#pragma once

#include "../UIComponent.h"
#include "../../util/const.h"

class UnitIconButton : public UIComponent{
protected:
    void draw(const ResourceManager &resourceManager) const;
    AssetId iconAssetId;
public:
    UnitIconButton(const Vect2D &position);
    void setIconAssetId(AssetId assetId);
};
