#include "buildbutton.h"

BuildButton::BuildButton():UIComponent(BUTTON_WIDTH,BUTTON_HEIGHT,
                                       Vect2D(MAP_VIEW_WIDTH - BUTTON_WIDTH -10, MAP_VIEW_HEIGHT + 12 + BUTTON_HEIGHT)){}

void BuildButton::draw(const ResourceManager &resourceManager) const{
    resourceManager.getResource(UI_BUILD_BUTTON).draw(position);
}
Action BuildButton::getAction()const{
    return BUILD;
}
