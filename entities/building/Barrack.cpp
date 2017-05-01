#include "Barrack.h"

Barrack::Barrack():
    Building("/assets/buildings/barrack.png","Barrack",30){}

bool Barrack::canLevelUp(){
	return level <= 2;
}
