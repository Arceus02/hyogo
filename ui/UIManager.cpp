#include "UIManager.h"


const Vect2D PANEL_BOTTOM_POSITION = {0, MAP_VIEW_HEIGHT + 1};
const Vect2D MOVE_BUTTON_POSITION = {MAP_VIEW_WIDTH - BUTTON_WIDTH - 10, MAP_VIEW_HEIGHT + 6};
const Vect2D ATTACK_BUTTON_POSITION = {MAP_VIEW_WIDTH - BUTTON_WIDTH - 10, MAP_VIEW_HEIGHT + 6 + BUTTON_HEIGHT};


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
    for (std::map<Action, UIComponent *>::const_iterator k = components.begin(); k != components.end(); k++) {
        if (k->second->isActivated())
            k->second->draw(resourceManager);
    }
}


void UIManager::clickActionButton(const Vect2D position, Action &action) {
    for (std::map<Action, UIComponent *>::iterator it = components.begin(); it != components.end(); ++it) {
        if (it->second->isActivated()) {
            Vect2D leftCornerButton = it->second->getPosition();
            Vect2D rightCornerButton = it->second->getPosition() + Vect2D(BUTTON_WIDTH, BUTTON_HEIGHT);
            if (inside(position, leftCornerButton, rightCornerButton)) {
                Action tempAction = it->first;
                if (tempAction == BUILD) {
                    components[MOVE]->setActivated(false);
                    components[BUILD]->setActivated(false);
                    components[BUILD_BARRACK]->setActivated(true);
                    components[BUILD_DEFENSE_TURRET]->setActivated(true);
                    components[BUILD_BRIDGE]->setActivated(true);
                    components[BUILD_DRILL]->setActivated(true);
                    components[BUILD_EXTRACTOR]->setActivated(true);
                } else if (tempAction == BUILD_BARRACK) {
                    // build barrack if possible
                    // if(success) :
                    action = tempAction;
                }
                // TODO build building buttons
                // TODO unit move
                // TODO fighting unit attack
            }
        }
    }


}

void UIManager::displayButton(EntityType type) {
    switch (type) {
        case FIGHTINGUNIT:
            components[MOVE]->setActivated(true);
            components[ATTACK]->setActivated(true);
            break;
        case BUILDINGUNIT:
            components[MOVE]->setActivated(true);
            components[BUILD]->setActivated(true);
            break;
        case BUILDING:
            break;
    }
}

void UIManager::clearUi() {
    for (std::map<Action, UIComponent *>::iterator it = components.begin(); it != components.end(); ++it) {
        it->second->setActivated(false);
    }
}
