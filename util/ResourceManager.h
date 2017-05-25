#pragma once


#include <map>
#include "Asset.h"

// List of all Assets avalaible
// Do not forget to load them in initRessource !
enum AssetId {
    TERRAIN_NONE,
    TERRAIN_MEADOW,
    TERRAIN_FOREST,
    TERRAIN_RIVER,
    UNIT_WORKER,
    UNIT_SCOUT,
    UNIT_INFANTRY_MELEE,
    UNIT_INFANTRY_DISTANCE,
    UNIT_CAVALRY,
    UNIT_HEAVY,
    UNIT_BALLISTIC,
    INCONSTRUCTION_BARRACK,
    INCONSTRUCTION_BRIDGE,
    INCONSTRUCTION_TURRET,
    INCONSTRUCTION_DRILL,
    INCONSTRUCTION_EXTRACTOR,
    BUILDING_BARRACK,
    BUILDING_BRIDGE,
    BUILDING_COMMAND_CENTER,
    BUILDING_TURRET,
    BUILDING_DRILL,
    BUILDING_EXTRACTOR,
    UI_PANEL_BOTTOM,
    UI_END_TURN_BUTTON,
    UI_MOVE_BUTTON,
    UI_ATTACK_BUTTON,
    UI_BUILD_BUTTON,
    UI_BUILD_BARRACK,
    UI_BUILD_BRIDGE,
    UI_BUILD_DRILL,
    UI_BUILD_EXTRACTOR,
    UI_BUILD_DEFENSETURRET
};

class ResourceManager {
private:
    std::map<AssetId, Asset> assets;

    void loadResource(AssetId assetId, const std::string &assetPath);

public:
    /// Call once to load all assets
    void initResources();

    /// Get an asset
    /// \param assetId
    /// \return Corresponding asset to assetId
    const Asset &getResource(AssetId assetId) const;
};
