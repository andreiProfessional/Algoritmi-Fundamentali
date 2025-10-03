#ifndef LAB_1_MEMORARE_H
#define LAB_1_MEMORARE_H

#include "../constante.h"
#include <vector>

void construireMatriceAdiacenta(int &numarNoduri, int &numarMuchii,
                                bool matriceAdiacenta[NUMAR_MAXIM_NODURI][NUMAR_MAXIM_NODURI], bool grafulEsteOrientat);

void afisareMatriceAdiacenta(int numarNoduri, bool matriceAdiacenta[NUMAR_MAXIM_NODURI][NUMAR_MAXIM_NODURI]);

void construireListeAdiacenta(int &numarNoduri, int &numarMuchii,
                              std::vector<int> listeAdiacenta[NUMAR_MAXIM_NODURI],
                              bool grafulEsteOrientat);

void afisareListeAdiacenta(int numarNoduri, std::vector<int> listeAdiacenta[NUMAR_MAXIM_NODURI]);

void transformareMatriceAdiacentaInListeAdiacenta(int numarNoduri,
    bool matriceAdiacenta[NUMAR_MAXIM_NODURI][NUMAR_MAXIM_NODURI], std::vector<int> listeAdiacenta[NUMAR_MAXIM_NODURI]);

void transformareListeAdiacentaInMatriceAdiacenta(int numarNoduri,
    std::vector<int> listeAdiacenta[NUMAR_MAXIM_NODURI], bool matriceAdiacenta[NUMAR_MAXIM_NODURI][NUMAR_MAXIM_NODURI]);

#endif