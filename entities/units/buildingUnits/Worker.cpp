#include "Worker.h"

Worker::Worker(const Vect2D &position) : Unit(UNIT_WORKER, "Worker", BUILDINGUNIT, 2, 4, 2) {
    setPosition(position);
    setCanWalkThroughRiver(true);
}
