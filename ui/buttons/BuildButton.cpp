#include "BuildButton.h"

BuildButton::BuildButton():UIComponent(157,41,
                                       Vect2D(MAP_VIEW_WIDTH - 157 -10, MAP_VIEW_HEIGHT + 12 + 41)){}

void BuildButton::draw(const ResourceManager &resourceManager) const{
    resourceManager.getResource(UI_BUILD_BUTTON).draw(position);
}
