#include "RecruitInfantryMeleeButton.h"

RecruitInfantryMeleeButton::RecruitInfantryMeleeButton():UIComponent(132,16,
                                                     Vect2D(MAP_VIEW_WIDTH-132,MAP_VIEW_HEIGHT+2+16)){}

void RecruitInfantryMeleeButton::draw(const ResourceManager &resourceManager) const{
   resourceManager.getResource(UI_RECRUIT_INFANTRYMELEE).draw(position);
}
