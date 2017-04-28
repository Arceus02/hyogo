#include "bridge.h"

Bridge::Bridge():
    Building("\assets\buildings\bridge","Bridge",10){}

bool Bridge::canLevelUp(){
    return false;
}
