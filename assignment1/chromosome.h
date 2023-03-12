//
// Created by youse on 3/12/2023.
//

#ifndef ASSIGNMENT1_CHROMOSOME_H
#define ASSIGNMENT1_CHROMOSOME_H
#include <bits/stdc++.h>
#include "gene.h"

using namespace std;
class Chromosome {
    Gene *chromosome;
    int size,seed=10;
public:
    Chromosome();
    Chromosome(int size);
    Chromosome(Chromosome &c);
    Chromosome(Gene* genes,int size);
    Chromosome &operator=(const Chromosome &c);
    ~Chromosome();
    int fitness();
    void mutation();
    Chromosome *crossOver(Chromosome &c);
};
#endif //ASSIGNMENT1_CHROMOSOME_H
