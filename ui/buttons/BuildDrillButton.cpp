#include "BuildDrillButton.h"

BuildDrillButton::BuildDrillButton():UIComponent(96,25,
                                                 Vect2D(MAP_VIEW_WIDTH-20-2*96,MAP_VIEW_HEIGHT+10+25)){}

void BuildDrillButton::draw(const ResourceManager &resourceManager) const{
   resourceManager.getResource(UI_BUILD_DRILL).draw(position);
}

