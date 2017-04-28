#include "Barrack.h"

Barrack::Barrack():
    Building("/assets/buildings/barrack.png","Barrack",30){}

bool Barrack::canLevelUp(){
    if(level <=2)
        return true;
    return false;
}
