//
// Created by Ahmed Taha on 3/12/2023.
//

#include "population.h"

Population::Population() {
    srand(seed);
    size = rand() % 100 + 4;
    int chromosomeSize = rand() % 100 + 4;
    chromosomes = new Chromosome[size];
    for (int i = 0; i < size; ++i) {
        chromosomes[i] = Chromosome(chromosomeSize);
    }
    fittest = fitness();
}

Population::Population(Chromosome *chromosomes, int size) {
    this->size = size;
    this->chromosomes = new Chromosome[size];
    for (int i = 0; i < size; ++i) {
         this->chromosomes[i] = chromosomes[i];
    }
}

Population::Population(Population &population) {
    this->size = population.size;
    this->chromosomes = new Chromosome[size];
    for (int i = 0; i < size; ++i) {
        this->chromosomes[i] = population.chromosomes[i];
    }
}

Population::~Population() {
    delete [] chromosomes;
}

Chromosome Population::fitness() {
    int maxFitness = -1,mxidx;
    for (int i = 0; i < size; ++i) {
        int currentFitness = this->chromosomes[i].fitness();
        if (maxFitness < currentFitness) {
            maxFitness = currentFitness;
            mxidx = i;
        }
    }
    return this->chromosomes[mxidx];
}

void Population::mutation() {
    Chromosome c = fitness();
    c.mutation();
}

void Population::crossOver() {
    srand(seed);
    int idx1 = rand() % size , idx2 = rand() % size;
    while (idx1 == idx2 && size>1){
        idx2 = rand() % size;
    }
    Chromosome* c = chromosomes[idx1].crossOver(chromosomes[idx2]);
    if (chromosomes[idx1].fitness() < c[0].fitness()) chromosomes[idx1] = c[0];
    if (chromosomes[idx2].fitness() < c[1].fitness()) chromosomes[idx2] = c[1];
}


