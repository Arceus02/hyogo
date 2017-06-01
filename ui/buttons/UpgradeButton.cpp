#include "UpgradeButton.h"

UpgradeButton::UpgradeButton(): UIComponent(132,41,
                                      Vect2D(MAP_VIEW_WIDTH - 132 -10,MAP_VIEW_HEIGHT  + 6)){}

void UpgradeButton::draw(const ResourceManager &resourceManager) const{
    resourceManager.getResource(UI_UPGRADE_BUTTON).draw(position);
}
