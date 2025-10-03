#include "memorare.h"
#include <fstream>
#include <iostream>

void construireMatriceAdiacenta(int &numarNoduri, int &numarMuchii,
                                bool matriceAdiacenta[NUMAR_MAXIM_NODURI][NUMAR_MAXIM_NODURI], bool grafulEsteOrientat) {
    std::ifstream in("altele/graf.in");
    in >> numarNoduri >> numarMuchii;
    for (int i = 0; i < numarNoduri; i++) {
        for (int j = 0; j < numarNoduri; j++) {
            matriceAdiacenta[i][j] = false;
        }
    }
    for (int i = 0; i < numarMuchii; i++) {
        int x, y;
        in >> x >> y;
        x --;
        y --;
        if (grafulEsteOrientat) {
            matriceAdiacenta[x][y] = true;
        }
        else {
            matriceAdiacenta[x][y] = matriceAdiacenta[y][x] = true;
        }
    }
    in.close();
}

void afisareMatriceAdiacenta(int numarNoduri, bool matriceAdiacenta[NUMAR_MAXIM_NODURI][NUMAR_MAXIM_NODURI]) {
    for (int i = 0; i < numarNoduri; i++) {
        for (int j = 0; j < numarNoduri; j++) {
            if (matriceAdiacenta[i][j]) {
                std::cout << '1';
            }
            else {
                std::cout << '0';
            }
            std::cout << ' ';
        }
        std::cout << '\n';
    }
}

void construireListeAdiacenta(int &numarNoduri, int &numarMuchii,
                              std::vector<int> listeAdiacenta[NUMAR_MAXIM_NODURI],
                              bool grafulEsteOrientat) {
    std::ifstream in("altele/graf.in");
    in >> numarNoduri >> numarMuchii;
    for (int i = 0; i < numarNoduri; i++) {
        listeAdiacenta[i] = std::vector<int>();
    }
    for (int i = 0; i < numarMuchii; i++) {
        int x, y;
        in >> x >> y;
        x --;
        y --;
        if (grafulEsteOrientat) {
            listeAdiacenta[x].push_back(y);
        }
        else {
            listeAdiacenta[x].push_back(y);
            listeAdiacenta[y].push_back(x);
        }
    }
}

void afisareListeAdiacenta(int numarNoduri, std::vector<int> listeAdiacenta[NUMAR_MAXIM_NODURI]) {
    for (int i = 0; i < numarNoduri; i++) {
        std::cout << "Vecini nodul " << i + 1 << ": ";
        for (auto nodAdiacent: listeAdiacenta[i]) {
            std::cout << nodAdiacent + 1 << ' ';
        }
        std::cout << '\n';
    }
}

void transformareMatriceAdiacentaInListeAdiacenta(int numarNoduri,
    bool matriceAdiacenta[NUMAR_MAXIM_NODURI][NUMAR_MAXIM_NODURI], std::vector<int> listeAdiacenta[NUMAR_MAXIM_NODURI]) {
    for (int i = 0; i < numarNoduri; i ++) {
        listeAdiacenta[i] = std::vector<int>();
        for (int j = 0; j < numarNoduri; j ++) {
            if (matriceAdiacenta[i][j]) {
                listeAdiacenta[i].push_back(j);
            }
        }
    }
}

void transformareListeAdiacentaInMatriceAdiacenta(int numarNoduri,
    std::vector<int> listeAdiacenta[NUMAR_MAXIM_NODURI], bool matriceAdiacenta[NUMAR_MAXIM_NODURI][NUMAR_MAXIM_NODURI]) {
    for (int i = 0; i < numarNoduri; i++) {
        for (int j = 0; j < numarNoduri; j++) {
            matriceAdiacenta[i][j] = false;
        }
    }
    for (int i = 0; i < numarNoduri; i ++) {
        for (auto nodAdiacent: listeAdiacenta[i]) {
            matriceAdiacenta[nodAdiacent][i] = true;
        }
    }
}