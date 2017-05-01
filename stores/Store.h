#pragma once

#include <vector>
#include "../util/Buffer.h"
#include "../util/Vect2D.h"

using namespace std;

template<typename T>
class Store {
private:
	vector<T> list;
public:
	void draw(Buffer &buffer, Vect2D viewOffset, Vect2D minXRender, Vect2D maxXRender);
	// TODO add entity
	void add(T a);
	// TODO remove dead entities
	// TODO update entities' logic
};

template<typename T>
void Store<T>::draw(Buffer &buffer, Vect2D viewOffset, Vect2D minRender, Vect2D maxRender) {
	for (typename vector<T>::iterator k = list.begin(); k != list.end(); k++) {
		if ((*k).getPosition().inside(minRender, maxRender)) {
			(*k).draw(buffer, viewOffset);
		}
	}
}

template<typename T>
void Store<T>::add(T a) {
	list.push_back(a);
}