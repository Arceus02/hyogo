#include "BuildBarrackButton.h"

BuildBarrackButton::BuildBarrackButton():UIComponent(96,25,
                                                     Vect2D(MAP_VIEW_WIDTH-20-2*96,MAP_VIEW_HEIGHT+5)){}

void BuildBarrackButton::draw(const ResourceManager &resourceManager) const{
   resourceManager.getResource(UI_BUILD_BARRACK).draw(position);
}
