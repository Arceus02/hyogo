#include "priorite.h"

// Constructeur
FilePriorite::FilePriorite() {
    v.push_back(PointDist(-1, -1, -1));
}

// Zero element dans la file?
bool FilePriorite::empty() const {
    return (v.size() == 1);
}

// Ajoute un element
void FilePriorite::push(PointDist d) {
    unsigned long i = v.size();
    v.push_back(d);
    while (i > 1 && v[i / 2] < v[i]) {
        std::swap(v[i], v[i / 2]);
        i /= 2;
    }
}

// Retire un element
PointDist FilePriorite::pop() {
    PointDist d = v[1];
    v[1] = v.back();
    v.pop_back();
    int i = 1;
    while (2 * i < v.size()) {
        int j = i; // On cherche le max des enfants
        if (v[j] < v[2 * i]) // Gauche
            j = 2 * i;
        if (2 * i + 1 < v.size() && v[j] < v[2 * i + 1]) // Droite
            j = 2 * i + 1;
        if (i == j) break;
        std::swap(v[i], v[j]);
        i = j;
    }
    return d;
}
