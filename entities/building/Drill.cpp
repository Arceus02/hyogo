#include "drill.h"

Drill::Drill():
    Building("\assets\buildings\drill.png","Drill",20){}

bool Drill::canLevelUp(){
    if(level <=2)
        return true;
    return false;
}
int Drill::getProduction(){
    switch(level){
        case 1:
            return 350;
        break;
        case 2:
            return 700;
        break;
        case 3:
            return 1000;
        break;
    }
}

