#include "RecruitScoutButton.h"

RecruitScoutButton::RecruitScoutButton():UIComponent(132,16,
                                                     Vect2D(MAP_VIEW_WIDTH-132,MAP_VIEW_HEIGHT+2)){}

void RecruitScoutButton::draw(const ResourceManager &resourceManager) const{
   resourceManager.getResource(UI_RECRUIT_SCOUT).draw(position);
}
