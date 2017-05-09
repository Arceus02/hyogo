#include "UIManager.h"


const Vect2D PANEL_BOTTOM_POSITION = {0, MAP_VIEW_HEIGHT + 1};
const Vect2D MOVE_BUTTON_POSITION = {MAP_VIEW_WIDTH - BUTTON_WIDTH -10, MAP_VIEW_HEIGHT + 6};
const Vect2D ATTACK_BUTTON_POSITION = {MAP_VIEW_WIDTH - BUTTON_WIDTH -10, MAP_VIEW_HEIGHT + 6 + BUTTON_HEIGHT};


UIManager::UIManager() {
    components[ATTACK] = new AttackButton();
    components[BUILD] = new BuildButton();
    components[MOVE] = new MoveButton();
}

void UIManager::draw(const ResourceManager &resourceManager) const {
	resourceManager.getResource(UI_PANEL_BOTTOM).draw(PANEL_BOTTOM_POSITION);
    for (std::map<Action,UIComponent*>::const_iterator k = components.begin(); k != components.end(); k++) {
        if(k->second->isActivated())
            k->second->draw(resourceManager);
	}
}


void UIManager::clickActionButton(const Vect2D position, Action &action){
    for(std::map<Action,UIComponent*>::iterator it = components.begin(); it !=components.end();++it){
        if(it->second->isActivated()){
        Vect2D leftCornerButton = it->second->getPosition();
        Vect2D rightCornerButton = it->second->getPosition()+ Vect2D(BUTTON_WIDTH,BUTTON_HEIGHT);
            if(inside(position,leftCornerButton,rightCornerButton)){
                action = it->first;
            }
        }
    }


}
void UIManager::displayButton(EntityType type){
    switch (type) {
        case FIGHTINGUNIT:
            components[MOVE]->setActivated(true);
            components[ATTACK]->setActivated(true);
        break;
        case BUILDINGUNIT:
            components[MOVE]->setActivated(true);
            components[BUILD]->setActivated(true);
        break;
    }
}

void UIManager::clearUi(){
     for(std::map<Action,UIComponent*>::iterator it = components.begin(); it !=components.end();++it){
         it->second->setActivated(false);
     }
}
