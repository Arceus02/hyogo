#include "UIManager.h"


const Vect2D PANEL_BOTTOM_POSITION = {0, MAP_VIEW_HEIGHT + 1};
const Vect2D MOVE_BUTTON_POSITION = {MAP_VIEW_WIDTH - BUTTON_WIDTH -10, MAP_VIEW_HEIGHT + 6};
const Vect2D ATTACK_BUTTON_POSITION = {MAP_VIEW_WIDTH - BUTTON_WIDTH -10, MAP_VIEW_HEIGHT + 6 + BUTTON_HEIGHT};


UIManager::UIManager() {
    components[ATTACK] = new AttackButton();
    components[BUILD] = new BuildButton();
    components[MOVE] = new MoveButton();
    components[BUILD_BARRACK] = new BuildBarrackButton();
    components[BUILD_BRIDGE] = new BuildBridgeButton();
    components[BUILD_DEFENSE_TURRET] = new BuildDefenseTurretButton();
    components[BUILD_DRILL] = new BuildDrillButton();
    components[BUILD_EXTRACTOR] = new BuildExtractorButton();

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
        Vect2D rightCornerButton = it->second->getPosition()+ Vect2D(it->second->getWidth(),it->second->getHeight());
            if(inside(position,leftCornerButton,rightCornerButton)){
                action = it->first;
                if(action == BUILD){
                    components[MOVE]->setActivated(false);
                    components[BUILD]->setActivated(false);
                    Action buildableBuildings[5] =  {BUILD_BARRACK, BUILD_DEFENSE_TURRET, BUILD_BRIDGE, BUILD_DRILL, BUILD_EXTRACTOR};
                    for(int i=0;i<5;i++){
                        components[buildableBuildings[i]]->setActivated(true);
                    }
                }
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
