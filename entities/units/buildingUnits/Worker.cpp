#include "Worker.h"

namespace WorkerData {
	const Asset ASSET(srcPath("assets/units/worker.png"));
	const std::string name = "Worker";
	const int maxHp = 2, viewRange = 4, speed = 2;
}

Worker::Worker(Vect2D position)
		: Unit(WorkerData::ASSET, "Worker", maxHp, viewRange, speed) {
	this->position = position;
}