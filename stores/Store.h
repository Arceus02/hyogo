#pragma once

#include <vector>
#include "../util/Vect2D.h"
#include "../util/ResourceManager.h"

using namespace std;

template<typename T>
class Store {
private:
	vector<T> list;
public:
	void draw(const ResourceManager &resourceManager, const Vect2D &viewOffset, const Vect2D &minXRender,
			  const Vect2D &maxXRender) const;

	void add(T &a);
};

template<typename T>
void Store<T>::draw(const ResourceManager &resourceManager, const Vect2D &viewOffset, const Vect2D &minRender,
					const Vect2D &maxRender) const {
	for (typename vector<T>::const_iterator k = list.begin(); k != list.end(); k++) {
        if (inside((*k).getPosition(),minRender, maxRender)) {
			(*k).draw(resourceManager, viewOffset);
		}
	}
}

template<typename T>
void Store<T>::add(T &a) {
	list.push_back(a);
}
