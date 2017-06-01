#include "RecruitBalisticButton.h"

RecruitBalisticButton::RecruitBalisticButton():UIComponent(132,16,
                                                     Vect2D(MAP_VIEW_WIDTH-132,MAP_VIEW_HEIGHT+80+2)){}

void RecruitBalisticButton::draw(const ResourceManager &resourceManager) const{
   resourceManager.getResource(UI_RECRUIT_BALISTIC).draw(position);
}
