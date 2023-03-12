//
// Created by youse on 3/12/2023.
//

#ifndef ASSIGNMENT1_POPULATION_H
#define ASSIGNMENT1_POPULATION_H
#include <bits/stdc++.h>
#include "chromosome.h"
using namespace std;

class Population {
    Chromosome *chromosomes;
    int size;
public:
    Population();
    Population(Chromosome* chromosomes,int size);
    Population(Population &population);
    ~Population();
    void mutation(int idx);
    Chromosome *crossOver(Chromosome &c1,Chromosome &c2);
};
#endif //ASSIGNMENT1_POPULATION_H
