#include "Bridge.h"

Bridge::Bridge() : Building(BUILDING_BRIDGE, "Bridge", 10, 1) {

}
void Bridge::build(){
    isUnderConstruction = false;
    assetId = BUILDING_BRIDGE;
}
