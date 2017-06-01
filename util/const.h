#pragma once

#include <map>
#include "ResourceManager.h"

const int MAP_SQUARE_PIXEL_SIZE = 64;
const int WINDOW_WIDTH = 640, WINDOW_HEIGHT = 496;
const int ACTION_BAR_HEIGHT = 100;
const int MAP_VIEW_WIDTH = WINDOW_WIDTH, MAP_VIEW_HEIGHT = WINDOW_HEIGHT - ACTION_BAR_HEIGHT;

enum Player {
    PLAYER1, PLAYER2
};

enum Action {
    NONE,
    ENDTURN,
    MOVE,
    ATTACK,
    BUILD,
    BUILD_BARRACK,
    BUILD_DEFENSE_TURRET,
    BUILD_BRIDGE,
    BUILD_DRILL,
    BUILD_EXTRACTOR,
    RECRUIT,
    RECRUIT_SCOUT,
    RECRUIT_INFANTRY_MELEE,
    RECRUIT_INFANTRY_DISTANCE,
    RECRUIT_CAVALRY,
    RECRUIT_HEAVY,
    RECRUIT_BALISTIC,
    RECRUIT_WORKER,
    SELECT_UNIT_1,
    SELECT_UNIT_2,
    SELECT_UNIT_3,
    SELECT_UNIT_4,
    UPGRADE
};

const std::map<int, Action> selectUnit = {{0, SELECT_UNIT_1},
                                          {1, SELECT_UNIT_2},
                                          {2, SELECT_UNIT_3},
                                          {3, SELECT_UNIT_4}};

enum EntityType {
    BUILDING, FIGHTINGUNIT, BUILDINGUNIT
};

const std::map<Action, int> BUILDING_MINERAL_COST = {{BUILD_DRILL,          1000},
                                                     {BUILD_EXTRACTOR,      3000},
                                                     {BUILD_BARRACK,        2000},
                                                     {BUILD_BRIDGE,         500},
                                                     {BUILD_DEFENSE_TURRET, 1500}};
const std::map<Action, int> BUILDING_GAS_COST = {{BUILD_DRILL,          0},
                                                 {BUILD_EXTRACTOR,      0},
                                                 {BUILD_BARRACK,        0},
                                                 {BUILD_BRIDGE,         0},
                                                 {BUILD_DEFENSE_TURRET, 5}};

const std::map<AssetId, std::vector<int>> UPGRADE_MINERAL_COST = {{BUILDING_DRILL,     {2000, 3000}},
                                                                  {BUILDING_EXTRACTOR, {5000, 7000}},
                                                                  {BUILDING_BARRACK,   {3000, 4000}},
                                                                  {BUILDING_TURRET,    {3000}}};
const std::map<AssetId, std::vector<int>> UPGRADE_GAS_COST = {{BUILDING_DRILL,     {0,  20}},
                                                              {BUILDING_EXTRACTOR, {10, 50}},
                                                              {BUILDING_BARRACK,   {0,  30}},
                                                              {BUILDING_TURRET,    {20}}};

const std::map<Action, int> UNIT_MINERAL_COST = {{RECRUIT_WORKER,            20},
                                                 {RECRUIT_SCOUT,             50},
                                                 {RECRUIT_INFANTRY_MELEE,    100},
                                                 {RECRUIT_INFANTRY_DISTANCE, 150},
                                                 {RECRUIT_CAVALRY,           200},
                                                 {RECRUIT_HEAVY,             250},
                                                 {RECRUIT_BALISTIC,          300}};
const std::map<Action, int> UNIT_GAS_COST = {{RECRUIT_WORKER,            0},
                                             {RECRUIT_SCOUT,             0},
                                             {RECRUIT_INFANTRY_MELEE,    0},
                                             {RECRUIT_INFANTRY_DISTANCE, 0},
                                             {RECRUIT_CAVALRY,           0},
                                             {RECRUIT_HEAVY,             50},
                                             {RECRUIT_BALISTIC,          10}};




