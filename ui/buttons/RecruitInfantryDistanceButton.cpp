#include "RecruitInfantryDistanceButton.h"

RecruitInfantryDistanceButton::RecruitInfantryDistanceButton():UIComponent(132,16,
                                                     Vect2D(MAP_VIEW_WIDTH-132,MAP_VIEW_HEIGHT+32+2)){}

void RecruitInfantryDistanceButton::draw(const ResourceManager &resourceManager) const{
   resourceManager.getResource(UI_RECRUIT_INFANTRYDISTANCE).draw(position);
}
