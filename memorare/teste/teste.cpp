#include "teste.h"
#include <iostream>
#include "../../constante.h"
#include "../memorare.h"


void ruleaza_teste() {
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
    test_6();
}


void test_1() {
    std::cout << "TEST 1\n";
    int numarNoduri, numarMuchii;
    bool matriceAdiacenta[NUMAR_MAXIM_NODURI][NUMAR_MAXIM_NODURI];
    construireMatriceAdiacenta(numarNoduri, numarMuchii, matriceAdiacenta, false);
    afisareMatriceAdiacenta(numarNoduri, matriceAdiacenta);
    std::cout << "\n\n";
}

void test_2() {
    std::cout << "TEST 2\n";
    int numarNoduri, numarMuchii;
    bool matriceAdiacenta[NUMAR_MAXIM_NODURI][NUMAR_MAXIM_NODURI];
    construireMatriceAdiacenta(numarNoduri, numarMuchii, matriceAdiacenta, true);
    afisareMatriceAdiacenta(numarNoduri, matriceAdiacenta);
    std::cout << "\n\n";
}

void test_3() {
    std::cout << "TEST 3\n";
    int numarNoduri, numarMuchii;
    std::vector<int> listeAdiacenta[NUMAR_MAXIM_NODURI];
    construireListeAdiacenta(numarNoduri, numarMuchii, listeAdiacenta, false);
    afisareListeAdiacenta(numarNoduri, listeAdiacenta);
    std::cout << "\n\n";
}

void test_4() {
    std::cout << "TEST 4\n";
    int numarNoduri, numarMuchii;
    std::vector<int> listeAdiacenta[NUMAR_MAXIM_NODURI];
    construireListeAdiacenta(numarNoduri, numarMuchii, listeAdiacenta, true);
    afisareListeAdiacenta(numarNoduri, listeAdiacenta);
    std::cout << "\n\n";
}

void test_5() {
    std::cout << "TEST 5\n";
    int numarNoduri, numarMuchii;
    bool matriceAdiacenta[NUMAR_MAXIM_NODURI][NUMAR_MAXIM_NODURI];
    construireMatriceAdiacenta(numarNoduri, numarMuchii, matriceAdiacenta, false);
    afisareMatriceAdiacenta(numarNoduri, matriceAdiacenta);
    for (int i = 0; i < numarNoduri; i++) {
        std::cout << "==";
    }
    std::cout << '\n';
    std::vector<int> listeAdiacenta[NUMAR_MAXIM_NODURI];
    transformareMatriceAdiacentaInListeAdiacenta(numarNoduri, matriceAdiacenta, listeAdiacenta);
    afisareListeAdiacenta(numarNoduri, listeAdiacenta);
    std::cout << "\n\n";
}

void test_6() {
    std::cout << "TEST 6\n";
    int numarNoduri, numarMuchii;
    std::vector<int> listeAdiacenta[NUMAR_MAXIM_NODURI];
    construireListeAdiacenta(numarNoduri, numarMuchii, listeAdiacenta, false);
    afisareListeAdiacenta(numarNoduri, listeAdiacenta);
    for (int i = 0; i < numarNoduri; i++) {
        std::cout << "==";
    }
    std::cout << '\n';
    bool matriceAdiacenta[NUMAR_MAXIM_NODURI][NUMAR_MAXIM_NODURI];
    transformareListeAdiacentaInMatriceAdiacenta(numarNoduri, listeAdiacenta, matriceAdiacenta);
    afisareMatriceAdiacenta(numarNoduri, matriceAdiacenta);
    std::cout << "\n\n";
}