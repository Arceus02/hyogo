#pragma once

#include <sstream>
#include <vector>
#include "UIComponent.h"
#include "buttons/AttackButton.h"
#include "buttons/BuildButton.h"
#include "buttons/MoveButton.h"
#include "buttons/BuildBarrackButton.h"
#include "buttons/BuildDrillButton.h"
#include "buttons/BuildExtractorButton.h"
#include "buttons/BuildDefenseTurretButton.h"
#include "buttons/BuildBridgeButton.h"
#include "../util/const.h"
#include "../util/ResourceManager.h"
#include "../stores/BuildingManager.h"
#include "../stores/UnitManager.h"
#include "buttons/EndTurnButton.h"
#include "buttons/UnitIconButton.h"
#include "buttons/UpgradeButton.h"


class UIManager {
private:
    std::map<Action, UIComponent *> components;
    EndTurnButton endTurnButton;
public:
    UIManager();

    /// Draw UI
    /// \param resourceManager
    void draw(const ResourceManager &resourceManager, const int mineralQuantity, const int gasQuantity, Player player, const Entity *selectedEntity) const;

    /// Handle click on an action button
    /// \param position
    /// \param action
    void clickActionButton(const Vect2D position, Action &action);

    /// Activate right buttons depending on entity clicked
    /// \param type of clicked entity
    void displayButton(const Entity *selectedEntity);

    /// Display the attributes of the selected entity
    void displayAttributes(const Entity *selectedEntity) const;

    void clearUi();

};
