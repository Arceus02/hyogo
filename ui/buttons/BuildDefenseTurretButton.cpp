#include "BuildDefenseTurretButton.h"

BuildDefenseTurretButton::BuildDefenseTurretButton():UIComponent(96,25,
                                                                 Vect2D(MAP_VIEW_WIDTH-10-96,MAP_VIEW_HEIGHT+20)){}

void BuildDefenseTurretButton::draw(const ResourceManager &resourceManager) const{
   resourceManager.getResource(UI_BUILD_DEFENSETURRET).draw(position);
}

