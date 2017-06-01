#include "RecruitCavalryButton.h"

RecruitCavalryButton::RecruitCavalryButton():UIComponent(132,16,
                                                     Vect2D(MAP_VIEW_WIDTH-132,MAP_VIEW_HEIGHT+48+2)){}

void RecruitCavalryButton::draw(const ResourceManager &resourceManager) const{
   resourceManager.getResource(UI_RECRUIT_CAVALRY).draw(position);
}
