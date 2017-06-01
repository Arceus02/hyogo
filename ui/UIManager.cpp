#include "UIManager.h"


const Vect2D PANEL_BOTTOM_POSITION = {0, MAP_VIEW_HEIGHT + 1};

UIManager::UIManager() {
    components[ATTACK] = new AttackButton();
    components[BUILD] = new BuildButton();
    components[MOVE] = new MoveButton();
    components[BUILD_BARRACK] = new BuildBarrackButton();
    components[BUILD_BRIDGE] = new BuildBridgeButton();
    components[BUILD_DEFENSE_TURRET] = new BuildDefenseTurretButton();
    components[BUILD_DRILL] = new BuildDrillButton();
    components[BUILD_EXTRACTOR] = new BuildExtractorButton();
    components[SELECT_UNIT_1] = new UnitIconButton(Vect2D(400, MAP_VIEW_HEIGHT));
    components[SELECT_UNIT_2] = new UnitIconButton(Vect2D(400, MAP_VIEW_HEIGHT + 25));
    components[SELECT_UNIT_3] = new UnitIconButton(Vect2D(400, MAP_VIEW_HEIGHT + 50));
    components[SELECT_UNIT_4] = new UnitIconButton(Vect2D(400, MAP_VIEW_HEIGHT + 75));
    components[UPGRADE] = new UpgradeButton();


}

void
UIManager::draw(const ResourceManager &resourceManager, const int mineralQuantity, const int gasQuantity, Player player,
                const Entity *selectedEntity) const {
    resourceManager.getResource(UI_PANEL_BOTTOM).draw(PANEL_BOTTOM_POSITION);
    string playerNumber = (player == PLAYER1) ? "1" : "2";
    string playerString = "Turn of player " + playerNumber;
    drawString(10, MAP_VIEW_HEIGHT + 7 + 10, playerString, BLACK, 10);
    stringstream ss1, ss2;
    ss1 << mineralQuantity;
    ss2 << gasQuantity;
    string mineral = "Mineral quantity : " + ss1.str();
    string gas = "Gas quantity : " + ss2.str();
    drawString(10, MAP_VIEW_HEIGHT + 14 + 20, mineral, BLACK, 10);
    drawString(10, MAP_VIEW_HEIGHT + 21 + 30, gas, BLACK, 10);
    if (selectedEntity != NULL) {
        displayAttributes(selectedEntity);
    }

    endTurnButton.draw(resourceManager);

    for (std::map<Action, UIComponent *>::const_iterator k = components.begin(); k != components.end(); k++) {
        if (k->second->isActivated())
            k->second->draw(resourceManager);
    }
}


void UIManager::clickActionButton(const Vect2D position, Action &action) {
    // End turn button
    if (inside(position, endTurnButton.getPosition(), endTurnButton.getPosition() + endTurnButton.getSize())) {
        action = ENDTURN;
    }
    // Other components
    for (std::map<Action, UIComponent *>::iterator it = components.begin(); it != components.end(); ++it) {
        if (it->second->isActivated()) {
            Vect2D leftCornerButton = it->second->getPosition();
            Vect2D rightCornerButton = it->second->getPosition() + it->second->getSize();
            if (inside(position, leftCornerButton, rightCornerButton)) {
                action = it->first;
                if (action == BUILD) {
                    components[MOVE]->setActivated(false);
                    components[BUILD]->setActivated(false);
                    components[BUILD_BARRACK]->setActivated(true);
                    components[BUILD_DEFENSE_TURRET]->setActivated(true);
                    components[BUILD_BRIDGE]->setActivated(true);
                    components[BUILD_DRILL]->setActivated(true);
                    components[BUILD_EXTRACTOR]->setActivated(true);
                }

                // TODO build building buttons
                // TODO fighting unit attack
                return;
            }
        }
    }


}

void UIManager::displayButton(const Entity *selectedEntity) {
    EntityType type = selectedEntity->getType();
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
            const Building *building = dynamic_cast<const Building *>(selectedEntity);
            int garrisonSize = building->getGarrisonSize();
            for (int i = 0; i < garrisonSize; i++) {
                components[selectUnit.at(i)]->setActivated(true);
                components[selectUnit.at(i)]->setIconAssetId(building->getGarrisonUnit(i)->getAssetId());
            }
            if (building->canLevelUp()) {
                components[UPGRADE]->setActivated(true);
            }
            break;
    }
}

void UIManager::displayAttributes(const Entity *selectedEntity) const {
    drawString(195, MAP_VIEW_HEIGHT + 15, "Selected entity : " + selectedEntity->getName(), BLACK, 10);
    switch (selectedEntity->getType()) {
        case FIGHTINGUNIT: {
            const FightingUnit *fightingUnit = dynamic_cast<const FightingUnit *>(selectedEntity);
            if (fightingUnit == 0) {
                std::cout << "erreur" << std::endl;
            }
            stringstream sshp, ssMovingRange, ssAttackRange, ssDamage;
            sshp << fightingUnit->getHP();
            ssMovingRange << fightingUnit->getSpeed();
            ssAttackRange << fightingUnit->getAttackRange();
            ssDamage << fightingUnit->getDamage();

            drawString(195, MAP_VIEW_HEIGHT + 30, "HP : " + sshp.str(), BLACK, 10);
            drawString(195, MAP_VIEW_HEIGHT + 45, "Moving range : " + ssMovingRange.str(), BLACK, 10);
            drawString(195, MAP_VIEW_HEIGHT + 60, "Attack range : " + ssAttackRange.str(), BLACK, 10);
            drawString(195, MAP_VIEW_HEIGHT + 75, "Damage : " + ssDamage.str(), BLACK, 10);
            break;
        }
        case BUILDINGUNIT: {
            const Worker *worker = dynamic_cast<const Worker *>(selectedEntity);
            stringstream sshp, ssMovingRange;
            sshp << worker->getHP();
            ssMovingRange << worker->getSpeed();
            drawString(195, MAP_VIEW_HEIGHT + 30, "HP : " + sshp.str(), BLACK, 10);
            drawString(195, MAP_VIEW_HEIGHT + 45, "Moving range : " + ssMovingRange.str(), BLACK, 10);
            break;
        }
        case BUILDING: {
            const Building *building = dynamic_cast<const Building *>(selectedEntity);
            stringstream sshp, ssgarnison, sslevel, ssmaxlevel;
            sshp << building->getHP();
            drawString(195, MAP_VIEW_HEIGHT + 30, "HP : " + sshp.str(), BLACK, 10);
            ssgarnison << building->getMaxGarrison();
            drawString(195, MAP_VIEW_HEIGHT + 45, "Number max of unit in garrison : " + ssgarnison.str(), BLACK, 10);
            sslevel << building->getLevel();
            drawString(195, MAP_VIEW_HEIGHT + 60, "Level : " + sslevel.str(), BLACK, 10);
            ssmaxlevel << building->getMaxlevel();
            drawString(195, MAP_VIEW_HEIGHT + 75, "Max level : " + ssmaxlevel.str(), BLACK, 10);
            int height = 90;
            if (building->getAssetId() == BUILDING_DRILL) {
                stringstream ssproduction;
                const Drill *drill = dynamic_cast<const Drill *>(building);
                ssproduction << drill->getProduction();
                drawString(195, MAP_VIEW_HEIGHT + height, "Production of mineral by turn : " + ssproduction.str(),
                           BLACK, 10);
                height += 15;
            } else if (building->getAssetId() == BUILDING_EXTRACTOR) {
                stringstream ssproduction;
                const Extractor *extractor = dynamic_cast<const Extractor *>(building);
                ssproduction << extractor->getProduction();
                drawString(195, MAP_VIEW_HEIGHT + height, "Production of gas by turn : " + ssproduction.str(), BLACK,
                           10);
                height += 15;
            }

            if (building->getTurnNumberToBeBuilt() > 0) {
                stringstream ssnumber;
                ssnumber << building->getTurnNumberToBeBuilt();
                drawString(195, MAP_VIEW_HEIGHT + height,
                           "The " + selectedEntity->getName() + " will be built in " + ssnumber.str() + " turn(s)",
                           BLACK, 10);
                height += 15;
            }
            std::vector<Unit *> garrison = building->getGarrison();
            Vect2D position(426, MAP_VIEW_HEIGHT + 20);
            for (std::vector<Unit *>::iterator it = garrison.begin(); it != garrison.end(); ++it) {
                drawString(position, (*it)->getName(), BLACK, 10);
                position += Vect2D(0, 25);
            }
            break;
        }
    }
}

void UIManager::clearUi() {
    for (std::map<Action, UIComponent *>::iterator it = components.begin(); it != components.end(); ++it) {
        it->second->setActivated(false);
    }
}
