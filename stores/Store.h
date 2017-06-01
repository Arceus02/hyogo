#pragma once

#include <vector>
#include "../util/Vect2D.h"
#include "../util/ResourceManager.h"
#include "../util/const.h"

using namespace std;

template<typename T>
class Store {
protected:
    vector<T> list;
public:
    virtual void draw(const ResourceManager &resourceManager, const Vect2D &viewOffset, const Vect2D &minRender,
                      const Vect2D &maxRender, Player currentTurn) const = 0;

    void add(T a);

    vector<T> &getList();

    ~Store();
};

template<typename T>
void Store<T>::add(T a) {
    list.push_back(a);
}

template<typename T>
vector<T> &Store<T>::getList() {
    return list;
}

template<typename T>
Store<T>::~Store() {
    for (typename vector<T>::iterator k = list.begin(); k != list.end(); k++) {
        delete (*k);
    }
}

