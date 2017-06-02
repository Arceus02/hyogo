#include "ResourceManager.h"

void ResourceManager::loadResource(AssetId assetId, const std::string &assetPath) {
    assets.emplace(assetId, assetPath);
}

void ResourceManager::initResources() {
    // BUILDINGS
    loadResource(BUILDING_BARRACK, srcPath("assets/buildings/barrack.png"));
    loadResource(BUILDING_COMMAND_CENTER, srcPath("assets/buildings/commandcenter.png"));
    loadResource(BUILDING_BRIDGE, srcPath("assets/buildings/bridge.png"));
    loadResource(BUILDING_DRILL, srcPath("assets/buildings/drill.png"));
    loadResource(BUILDING_EXTRACTOR, srcPath("assets/buildings/extractor.png"));
    // TERRAIN
    loadResource(TERRAIN_MEADOW, srcPath("assets/terrain/meadow.png"));
    loadResource(TERRAIN_FOREST, srcPath("assets/terrain/forest.png"));
    loadResource(TERRAIN_RIVER, srcPath("assets/terrain/river.png"));
    // UNITS
    loadResource(UNIT_SCOUT, srcPath("assets/units/scout.png"));
    loadResource(UNIT_INFANTRY_MELEE, srcPath("assets/units/infantry_melee.png"));
    loadResource(UNIT_CAVALRY, srcPath("assets/units/cavalry.png"));
    loadResource(UNIT_HEAVY, srcPath("assets/units/heavy.png"));
    loadResource(UNIT_BALLISTIC, srcPath("assets/units/ballistic.png"));
    loadResource(UNIT_WORKER, srcPath("assets/units/worker.png"));
    // UI
    loadResource(UI_PANEL_BOTTOM, srcPath("assets/ui/background_bottom_panel.png"));
    loadResource(UI_END_TURN_BUTTON, srcPath("assets/ui/buttons/endturn.png"));
    loadResource(UI_ATTACK_BUTTON, srcPath("assets/ui/buttons/attack.png"));
    loadResource(UI_MOVE_BUTTON, srcPath("assets/ui/buttons/move.png"));
    loadResource(UI_BUILD_BUTTON, srcPath("assets/ui/buttons/build.png"));
    loadResource(UI_BUILD_BARRACK, srcPath("assets/ui/buttons/buildbarrack.png"));
    loadResource(UI_BUILD_DRILL, srcPath("assets/ui/buttons/builddrill.png"));
    loadResource(UI_BUILD_EXTRACTOR, srcPath("assets/ui/buttons/buildextractor.png"));
    loadResource(UI_BUILD_BRIDGE, srcPath("assets/ui/buttons/buildbridge.png"));
    loadResource(UI_SCOUT, srcPath("assets/units/scout_icon.png"));
    loadResource(UI_INFANTRY_MELEE, srcPath("assets/units/infantry_melee_icon.png"));
    loadResource(UI_INFANTRY_DISTANCE, srcPath("assets/units/infantry_distance_icon.png"));
    loadResource(UI_CAVALRY, srcPath("assets/units/cavalry_icon.png"));
    loadResource(UI_HEAVY, srcPath("assets/units/heavy_icon.png"));
    loadResource(UI_BALLISTIC, srcPath("assets/units/ballistic_icon.png"));
    loadResource(UI_WORKER, srcPath("assets/units/worker_icon.png"));
    loadResource(UI_RECRUIT_BUTTON, srcPath("assets/ui/buttons/recruit.png"));
    loadResource(UI_UPGRADE_BUTTON, srcPath("assets/ui/buttons/upgrade.png"));
    loadResource(UI_RECRUIT_WORKER, srcPath("assets/ui/buttons/recruitworker.png"));
    loadResource(UI_RECRUIT_SCOUT, srcPath("assets/ui/buttons/recruitscout.png"));
    loadResource(UI_RECRUIT_CAVALRY, srcPath("assets/ui/buttons/recruitcavalry.png"));
    loadResource(UI_RECRUIT_HEAVY, srcPath("assets/ui/buttons/recruitheavy.png"));
    loadResource(UI_RECRUIT_BALISTIC, srcPath("assets/ui/buttons/recruitbalistic.png"));
    loadResource(UI_RECRUIT_INFANTRYDISTANCE, srcPath("assets/ui/buttons/recruitinfantrydistance.png"));
    loadResource(UI_RECRUIT_INFANTRYMELEE, srcPath("assets/ui/buttons/recruitinfantrymelee.png"));
}
AssetId ResourceManager::correspondingIcon(AssetId assetId)const{
    switch(assetId){
    case UNIT_BALLISTIC:
        return UI_BALLISTIC;
        break;
    case UNIT_CAVALRY:
        return UI_CAVALRY;
        break;
    case UNIT_HEAVY:
        return UI_HEAVY;
        break;
    case UNIT_INFANTRY_DISTANCE:
        return UI_INFANTRY_DISTANCE;
        break;
    case UNIT_INFANTRY_MELEE:
        return UI_INFANTRY_MELEE;
        break;
    case UNIT_SCOUT:
        return UI_SCOUT;
        break;
    case UNIT_WORKER:
        return UI_WORKER;
        break;
    }
}

const Asset &ResourceManager::getResource(AssetId assetId) const {
    return assets.at(assetId);
}
