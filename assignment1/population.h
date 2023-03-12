//
// Created by youse on 3/12/2023.
//

#ifndef ASSIGNMENT1_POPULATION_H
#define ASSIGNMENT1_POPULATION_H
#include <bits/stdc++.h>
#include "chromosome.h"
using namespace std;

class Population {
    Chromosome *chromosomes,fittest;
    int size,seed=10;
public:
    Population();
    Population(Chromosome* chromosomes,int size);
    Population(Population &population);
    ~Population();
    Chromosome fitness();
    void mutation();
    void crossOver();
};
#endif //ASSIGNMENT1_POPULATION_H
