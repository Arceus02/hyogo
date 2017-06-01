cmake_minimum_required(VERSION 3.6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
file(TO_CMAKE_PATH "$ENV{IMAGINEPP_ROOT}/CMake" p)
find_package(Imagine REQUIRED)

project(Hyogo)
set(SOURCE_FILES main.cpp)
add_executable(Hyogo main.cpp Game.h Game.cpp
        entities/Entity.h entities/Entity.cpp
        entities/buildings/Building.h entities/buildings/Building.cpp
        entities/buildings/Barrack.h entities/buildings/Barrack.cpp entities/buildings/Bridge.h entities/buildings/Bridge.cpp
        entities/buildings/CommandCenter.h entities/buildings/CommandCenter.cpp entities/buildings/DefenseTurret.h entities/buildings/DefenseTurret.cpp
        entities/buildings/Drill.h entities/buildings/Drill.cpp entities/buildings/Extractor.h entities/buildings/Extractor.cpp
        entities/units/Unit.h entities/units/Unit.cpp
        entities/units/buildingUnits/Worker.h entities/units/buildingUnits/Worker.cpp
        entities/units/fightingUnits/FightingUnit.h entities/units/fightingUnits/FightingUnit.cpp
        map/Map.h map/Map.cpp map/MapGen.h map/MapGen.cpp
        stores/Store.h actions/ActionManager.h actions/ActionManager.cpp
        stores/BuildingManager.h stores/BuildingManager.cpp stores/UnitManager.h stores/UnitManager.cpp
        ui/UIManager.h ui/UIManager.cpp ui/UIComponent.h ui/UIComponent.cpp
        ui/buttons/MoveButton.cpp ui/buttons/MoveButton.h ui/buttons/AttackButton.cpp ui/buttons/AttackButton.h ui/buttons/BuildButton.cpp ui/buttons/BuildButton.h
        ui/buttons/BuildBarrackButton.cpp ui/buttons/BuildBarrackButton.h ui/buttons/BuildDrillButton.cpp ui/buttons/BuildDrillButton.h
        ui/buttons/BuildExtractorButton.cpp ui/buttons/BuildExtractorButton.h ui/buttons/BuildDefenseTurretButton.cpp ui/buttons/BuildDefenseTurretButton.h
        ui/buttons/BuildBridgeButton.cpp ui/buttons/BuildBridgeButton.h
        util/const.h util/Asset.h util/Asset.cpp util/Vect2D.h util/Vect2D.cpp util/ResourceManager.cpp util/ResourceManager.h
        util/fastMarching/pointDist.h util/fastMarching/priorite.h util/fastMarching/priorite.cpp
        util/fastMarching/fastMarching.h util/fastMarching/fastMarching.cpp ui/buttons/EndTurnButton.cpp ui/buttons/EndTurnButton.h
        ui/buttons/RecruitButton.h ui/buttons/RecruitButton.cpp ui/buttons/RecruitWorkerButton.h  ui/buttons/RecruitWorkerButton.cpp
        ui/buttons/RecruitScoutButton.h ui/buttons/RecruitScoutButton.cpp ui/buttons/RecruitInfantryMeleeButton.h ui/buttons/RecruitInfantryMeleeButton.cpp
        ui/buttons/RecruitInfantryDistanceButton.h ui/buttons/RecruitInfantryDistanceButton.cpp ui/buttons/RecruitCavalryButton.h ui/buttons/RecruitCavalryButton.cpp
        ui/buttons/RecruitHeavyButton.h ui/buttons/RecruitHeavyButton.cpp ui/buttons/RecruitBalisticButton.h ui/buttons/RecruitBalisticButton.cpp
        ui/buttons/UnitIconButton.h ui/buttons/UnitIconButton.cpp ui/buttons/UpgradeButton.h ui/buttons/UpgradeButton.cpp stores/UnitStore.h stores/UnitStore.cpp
        stores/BuildingStore.h stores/BuildingStore.cpp)

ImagineUseModules(Hyogo Graphics)
ImagineUseModules(Hyogo Images)
