#include "commandcenter.h"

CommandCenter::CommandCenter():
       Building("/assets/buildings/commandcenter.png","Command Center",50){}

bool CommandCenter::canLevelUp(){
    return false;
}

bool CommandCenter::winGame(){
	return hp <= 0;
}


