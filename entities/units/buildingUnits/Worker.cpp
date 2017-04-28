#include "Worker.h"

Worker::Worker(Vect2D position)
        : Unit("\assets\units\worker.png", "Worker", 2) {
	this->position = position;
}
