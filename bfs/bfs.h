#ifndef LAB_1_BFS_H
#define LAB_1_BFS_H

#include <vector>

void bfs();
void citireDateIntrare(int &numarNoduri, int &numarMuchii, int &nodSursa, std::vector<std::vector<int>> &listeAdiacenta);
void calculDistante(const int &nodSursa, int distante[], const int &numarNoduri,
                   const std::vector<std::vector<int>> &listeAdiacenta);
void afisareDateIesire(const int &numarNoduri, const int distante[]);

#endif