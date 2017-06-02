#include "UIManager.h"


const Vect2D PANEL_BOTTOM_POSITION = {0, MAP_VIEW_HEIGHT + 1};

UIManager::UIManager() {
    components[ATTACK] = new AttackButton();
    components[BUILD] = new BuildButton();
    components[MOVE] = new MoveButton();
    components[BUILD_BARRACK] = new BuildBarrackButton();
    components[BUILD_BRIDGE] = new BuildBridgeButton();
    components[BUILD_DRILL] = new BuildDrillButton();
    components[BUILD_EXTRACTOR] = new BuildExtractorButton();

    components[SELECT_UNIT_1] = new UnitIconButton(Vect2D(385, MAP_VIEW_HEIGHT));
    components[SELECT_UNIT_2] = new UnitIconButton(Vect2D(385, MAP_VIEW_HEIGHT + 25));
    components[SELECT_UNIT_3] = new UnitIconButton(Vect2D(385, MAP_VIEW_HEIGHT + 50));
    components[SELECT_UNIT_4] = new UnitIconButton(Vect2D(385, MAP_VIEW_HEIGHT + 75));

    components[UPGRADE] = new UpgradeButton();
    components[RECRUIT] = new RecruitButton();
    components[RECRUIT_WORKER] = new RecruitWorkerButton();
    components[RECRUIT_SCOUT] = new RecruitScoutButton();
    components[RECRUIT_INFANTRY_MELEE] = new RecruitInfantryMeleeButton();
    components[RECRUIT_INFANTRY_DISTANCE] = new RecruitInfantryDistanceButton();
    components[RECRUIT_CAVALRY] = new RecruitCavalryButton();
    components[RECRUIT_HEAVY] = new RecruitHeavyButton();
    components[RECRUIT_BALISTIC] = new RecruitBalisticButton();

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


void UIManager::clickActionButton(const Vect2D position, Action &action, int level) {
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
            }
        }
    }
    if (action == BUILD) {
        components[MOVE]->setActivated(false);
        components[BUILD]->setActivated(false);
        components[BUILD_BARRACK]->setActivated(true);
        components[BUILD_BRIDGE]->setActivated(true);
        components[BUILD_DRILL]->setActivated(true);
        components[BUILD_EXTRACTOR]->setActivated(true);
    } else if (action == RECRUIT) {
        components[UPGRADE]->setActivated(false);
        components[RECRUIT]->setActivated(false);
        components[RECRUIT_SCOUT]->setActivated(true);
        components[RECRUIT_INFANTRY_MELEE]->setActivated(true);
        components[RECRUIT_INFANTRY_DISTANCE]->setActivated(true);
        if (level == 2) {
            components[RECRUIT_CAVALRY]->setActivated(true);
        }
        if (level == 3) {
            components[RECRUIT_HEAVY]->setActivated(true);
            components[RECRUIT_BALISTIC]->setActivated(true);
        }


    }


}

void UIManager::displayButton(const Entity *selectedEntity) {
    EntityType type = selectedEntity->getType();
    switch (type) {
        case FIGHTINGUNIT:
            if (selectedEntity->getTurnNumberToBeBuilt() == 0) {
                components[MOVE]->setActivated(true);
                components[ATTACK]->setActivated(true);
            }
            break;
        case BUILDINGUNIT:
            if (selectedEntity->getTurnNumberToBeBuilt() == 0) {
                components[MOVE]->setActivated(true);
                components[BUILD]->setActivated(true);
            }
            break;
        case BUILDING:
            const Building *building = dynamic_cast<const Building *>(selectedEntity);
            int garrisonSize = building->getGarrisonSize();
            for (int i = 0; i < garrisonSize; i++) {
                components[selectUnit.at(i)]->setActivated(true);
                components[selectUnit.at(i)]->setUnit(building->getGarrisonUnit(i));
            }
            if (selectedEntity->getTurnNumberToBeBuilt() == 0) {
                AssetId assetId = building->getAssetId();
                if (assetId == BUILDING_BARRACK || assetId == BUILDING_DRILL || assetId == BUILDING_EXTRACTOR
                    || assetId == BUILDING_TURRET)
                    components[UPGRADE]->setActivated(true);
                if (assetId == BUILDING_BARRACK)
                    components[RECRUIT]->setActivated(true);
                if (assetId == BUILDING_COMMAND_CENTER)
                    components[RECRUIT_WORKER]->setActivated(true);
            }
            break;
    }
}

void UIManager::displayAttributes(const Entity *selectedEntity) const {
    int currentHeight = 14;
    drawString(195, MAP_VIEW_HEIGHT + currentHeight, "Type : " + selectedEntity->getName(), BLACK, 9);
    currentHeight += 18;
    switch (selectedEntity->getType()) {
        case FIGHTINGUNIT: {
            const FightingUnit *fightingUnit = static_cast<const FightingUnit *>(selectedEntity);
            stringstream sshp, ssMovingRange, ssAttackRange, ssDamage;
            sshp << fightingUnit->getHP();
            ssMovingRange << fightingUnit->getSpeed();
            ssAttackRange << fightingUnit->getAttackRange();
            ssDamage << fightingUnit->getDamage();
            drawString(195, MAP_VIEW_HEIGHT + currentHeight, "HP  " + sshp.str(), BLACK, 9);
            currentHeight += 14;
            drawString(195, MAP_VIEW_HEIGHT + currentHeight, "MVT " + ssMovingRange.str(), BLACK, 9);
            currentHeight += 14;
            drawString(195, MAP_VIEW_HEIGHT + currentHeight, "RNG " + ssAttackRange.str(), BLACK, 9);
            currentHeight += 14;
            drawString(195, MAP_VIEW_HEIGHT + currentHeight, "DMG " + ssDamage.str(), BLACK, 9);
            currentHeight += 14;
            break;
        }
        case BUILDINGUNIT: {
            const Worker *worker = static_cast<const Worker *>(selectedEntity);
            stringstream sshp, ssMovingRange;
            sshp << worker->getHP();
            ssMovingRange << worker->getSpeed();
            drawString(195, MAP_VIEW_HEIGHT + currentHeight, "HP  " + sshp.str(), BLACK, 9);
            currentHeight += 14;
            drawString(195, MAP_VIEW_HEIGHT + currentHeight, "MVT " + ssMovingRange.str(), BLACK, 9);
            currentHeight += 14;
            break;
        }
        case BUILDING: {
            const Building *building = static_cast<const Building *>(selectedEntity);
            stringstream sshp, ssgarnison, sslevel, ssmaxlevel;
            sshp << building->getHP();
            drawString(195, MAP_VIEW_HEIGHT + currentHeight, "HP  " + sshp.str(), BLACK, 9);
            currentHeight += 14;
            ssgarnison << building->getMaxGarrison();
            drawString(195, MAP_VIEW_HEIGHT + currentHeight, "CAP " + ssgarnison.str(),
                       BLACK,
                       9);
            currentHeight += 14;
            sslevel << building->getLevel();
            ssmaxlevel << building->getMaxlevel();
            drawString(195, MAP_VIEW_HEIGHT + currentHeight, "LVL " + sslevel.str() + "/" + ssmaxlevel.str(), BLACK, 9);
            currentHeight += 14;
            if (building->getAssetId() == BUILDING_DRILL) {
                stringstream ssproduction;
                const Drill *drill = static_cast<const Drill *>(building);
                ssproduction << drill->getProduction();
                drawString(195, MAP_VIEW_HEIGHT + currentHeight,
                           "MIN PROD " + ssproduction.str(), BLACK, 9);
                currentHeight += 14;
            } else if (building->getAssetId() == BUILDING_EXTRACTOR) {
                stringstream ssproduction;
                const Extractor *extractor = static_cast<const Extractor *>(building);
                ssproduction << extractor->getProduction();
                drawString(195, MAP_VIEW_HEIGHT + currentHeight, "GAS PROD " + ssproduction.str(),
                           BLACK, 9);
                currentHeight += 14;
            }
            std::vector<Unit *> garrison = building->getGarrison();
            Vect2D position(411, MAP_VIEW_HEIGHT + 20);
            for (std::vector<Unit *>::iterator it = garrison.begin(); it != garrison.end(); ++it) {
                drawString(position, (*it)->getName(), BLACK, 10);
                position += Vect2D(0, 25);
            }
            break;
        }
    }
    if (selectedEntity->getTurnNumberToBeBuilt() > 0) {
        stringstream ssnumber;
        ssnumber << selectedEntity->getTurnNumberToBeBuilt();
        stringstream ssbuildtype;
        if (selectedEntity->getType() == BUILDING)
            ssbuildtype << "built";
        else
            ssbuildtype << "ready";
        drawString(195, MAP_VIEW_HEIGHT + currentHeight,
                   "The " + selectedEntity->getName() + " will be " + ssbuildtype.str() + " in " + ssnumber.str() +
                   " turns", BLACK, 9);
    }
}

void UIManager::clearUi() {
    for (std::map<Action, UIComponent *>::iterator it = components.begin(); it != components.end(); ++it) {
        it->second->setActivated(false);
    }
}

UIManager::~UIManager() {
    for (std::map<Action, UIComponent *>::iterator it = components.begin(); it != components.end(); it++) {
        delete (*it).second;
    }
}
