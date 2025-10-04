#include "bfs.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <queue>

void bfs() {
    int numarNoduri, numarMuchii, nodSursa;
    std::vector<std::vector<int>> listeAdiacenta;
    citireDateIntrare(numarNoduri, numarMuchii, nodSursa, listeAdiacenta);

    int distante[numarNoduri];
    calculDistante(nodSursa, distante, numarNoduri, listeAdiacenta);

    afisareDateIesire(numarNoduri, distante);
}

void citireDateIntrare(int &numarNoduri, int &numarMuchii, int &nodSursa, std::vector<std::vector<int>> &listeAdiacenta) {
    std::ifstream in("bfs/bfs.in");

    in >> numarNoduri >> numarMuchii >> nodSursa;
    nodSursa --;

    for (int i = 0; i < numarNoduri; i++) {
        listeAdiacenta.emplace_back();
    }
    for (int i = 0; i < numarMuchii; i++) {
        int x, y;
        in >> x >> y;
        x --;
        y --;
        listeAdiacenta[x].push_back(y);
    }

    in.close();
}

void calculDistante(const int &nodSursa, int distante[], const int &numarNoduri,
                    const std::vector<std::vector<int>> &listeAdiacenta) {
    for (int i = 0; i < numarNoduri; i ++) {
        distante[i] = -1;
    }
    distante[nodSursa] = 0;

    std::queue<int> coadaBfs;
    coadaBfs.push(nodSursa);
    while (!coadaBfs.empty()) {
        const int nodActual = coadaBfs.front();
        coadaBfs.pop();
        for (auto nodAdiacent: listeAdiacenta[nodActual]) {
            if (distante[nodAdiacent] == -1) {
                distante[nodAdiacent] = distante[nodActual] + 1;
                coadaBfs.push(nodAdiacent);
            }
        }
    }
}

void afisareDateIesire(const int &numarNoduri, const int distante[]) {
    std::fstream out("bfs/bfs.out");
    for (int i = 0; i < numarNoduri; i++) {
        out << distante[i] << " ";
    }
    out.close();
}