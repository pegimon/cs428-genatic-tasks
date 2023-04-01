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
    int size,seed=10;
    double *points,*values;
public:

    Population(int popsize,int C_size,double *points,double *values);
    Population(Chromosome* chromosomes,int size,double *points,double *value );
    Population(Population &population);
    ~Population();
    int getSize();
    pair<int,int> fitness();
    double mean();
    double var();
    int maximum();
    int minimum();
    void mutation();
    void crossOver();
    int * selection();
    Population& operator=(const Population &c);
    bool operator==(const Population &c);
    friend ostream& operator<<(ostream &out,const Population& p);
    friend istream& operator>>(istream &in,const Population& p);
};
#endif //ASSIGNMENT1_POPULATION_H
