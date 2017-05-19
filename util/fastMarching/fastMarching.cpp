#define _USE_MATH_DEFINES

#include <cmath>
#include "fastMarching.h"
#include "priorite.h"
#include <algorithm>

const int voisin[4][2] = {{-1, 0},
                          {+1, 0},
                          {0,  -1},
                          {0,  +1}};

// Met dans dx et dy les plus petites valeurs des voisins du pixel (x,y).
void minVoisins(const Image<float> &D, int x, int y, float &dx, float &dy) {
    dx = dy = INF;
    for (int i = 0; i < 4; i++) {
        int xv = x + voisin[i][0], yv = y + voisin[i][1];
        if (!(0 <= xv && xv < D.width() && 0 <= yv && yv < D.height()))
            continue;
        if (i < 2) dx = min(dx, D(xv, yv));
        else dy = min(dy, D(xv, yv));
    }
}

// Met a jour et renvoie la distance D(x,y) en fonction des voisins.
float calcDistance(Image<float> &D, const Image<float> &W, int x, int y) {
    float dx, dy;
    minVoisins(D, x, y, dx, dy);
    assert(!(dx == INF && dy == INF));
    float w = W(x, y);
    D(x, y) = w + min(dx, dy);
    if (dx < INF && dy < INF) {
        float delta = 2 * w * w - (dx - dy) * (dx - dy);
        if (delta >= 0)
            D(x, y) = (dx + dy + sqrt(delta)) / 2;
    }
    return D(x, y);
}

// Fast Marching: carte de distance a partir des points de niv0, qui sont a
// distance 0 par definition.
Image<float> fastMarching(const Image<float> &W, const vector<PointDist> &niv0) {
    const int w = W.width(), h = W.height();

    // Initialisation
    Image<float> D(w, h);
    D.fill(INF);
    Image<bool> E(w, h);
    E.fill(false);
    FilePriorite F;
    for (int i = 0; i < niv0.size(); i++) {
        D(niv0[i].j, niv0[i].i) = 0;
        E(niv0[i].j, niv0[i].i) = true;
        F.push(PointDist(niv0[i].i, niv0[i].j, 0));
    }

    // Propagation
    while (!F.empty()) {
        const PointDist p = F.pop();
        if (-p.dist == INF) break;
        E(p.j, p.i) = true;
        for (int i = 0; i < 4; i++) {
            PointDist q(p.i + voisin[i][1], p.j + voisin[i][0], 0);
            if (0 <= q.j && q.j < w && 0 <= q.i && q.i < h && !E(q.j, q.i)) {
                q.dist = -calcDistance(D, W, q.j, q.i);
                E(q.j, q.i) = true;
                F.push(q);
            }
        }
    }

    return D;
}