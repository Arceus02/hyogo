#include "BuildBridgeButton.h"

BuildBridgeButton::BuildBridgeButton(): UIComponent(96,25,
                                      Vect2D(MAP_VIEW_WIDTH -10-96,MAP_VIEW_HEIGHT + 25 + 10 + 20)){}

void BuildBridgeButton::draw(const ResourceManager &resourceManager) const{
    resourceManager.getResource(UI_BUILD_BRIDGE).draw(position);
}
