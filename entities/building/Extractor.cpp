#include "extractor.h"

Extractor::Extractor():
    Building("\assets\buildings\extractor.png","Extractor",20){}

bool Extractor::canLevelUp(){
    if(level <=2)
        return true;
    return false;
}
int Extractor::getProduction(){
    switch(level){
        case 1:
            return 5;
        break;
        case 2:
            return 10;
        break;
        case 3:
            return 50;
        break;
    }
}

