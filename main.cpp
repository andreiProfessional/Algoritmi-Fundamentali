#include <iostream>
#include <fstream>
#include <vector>

const int NUMAR_MAXIM_NODURI = 1000;

void construireMatriceAdiacenta(int &numarNoduri, int &numarMuchii,
                                int matriceAdiacenta[NUMAR_MAXIM_NODURI][NUMAR_MAXIM_NODURI], bool grafulEsteOrientat) {
    std::ifstream in("graf.in");
    in >> numarNoduri >> numarMuchii;
    for (int i = 0; i < numarNoduri; i++) {
        for (int j = 0; j < numarNoduri; j++) {
            matriceAdiacenta[i][j] = 0;
        }
    }
    for (int i = 0; i < numarMuchii; i++) {
        int x, y;
        in >> x >> y;
        x --;
        y --;
        if (grafulEsteOrientat) {
            matriceAdiacenta[x][y] = 1;
        }
        else {
            matriceAdiacenta[x][y] = matriceAdiacenta[y][x] = 1;
        }
    }
    in.close();
}

void afisareMatriceAdiacenta(int numarNoduri, int numarMuchii, int matriceAdiacenta[NUMAR_MAXIM_NODURI][NUMAR_MAXIM_NODURI]) {
    for (int i = 0; i < numarNoduri; i++) {
        for (int j = 0; j < numarNoduri; j++) {
            std::cout << matriceAdiacenta[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

void construireListeAdiacenta(int &numarNoduri, int &numarMuchii,
                              std::vector<int> listeAdiacenta[NUMAR_MAXIM_NODURI],
                              bool grafulEsteOrientat) {
    std::ifstream in("graf.in");
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
        for (auto element: listeAdiacenta[i]) {
            std::cout << element + 1 << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    // int numarNoduri, numarMuchii;
    // int matriceAdiacenta[NUMAR_MAXIM_NODURI][NUMAR_MAXIM_NODURI];
    // construireMatriceAdiacenta(numarNoduri, numarMuchii, matriceAdiacenta, true);
    // afisareMatriceAdiacenta(numarNoduri, numarMuchii, matriceAdiacenta);

    int numarNoduri, numarMuchii;
    std::vector<int> listeAdiacenta[NUMAR_MAXIM_NODURI];
    construireListeAdiacenta(numarNoduri, numarMuchii, listeAdiacenta, true);
    afisareListeAdiacenta(numarNoduri, listeAdiacenta);

    return 0;
}