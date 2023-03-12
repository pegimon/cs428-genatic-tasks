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
    int size;
public:
    Chromosome();
    Chromosome(int size);
    Chromosome(Chromosome &c);
    ~Chromosome();
    void mutation(int idx);
    Chromosome *crossOver(Chromosome &c1,Chromosome &c2);
};
#endif //ASSIGNMENT1_CHROMOSOME_H
