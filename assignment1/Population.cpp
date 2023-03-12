//
// Created by Ahmed Taha on 3/12/2023.
//

#include "population.h"

Population::Population() {
    size = 0;
    chromosomes = nullptr;
}

Population::Population(Chromosome *chromosomes, int size) {
    this->size = size;
    chromosomes = new Chromosome[size];
    for (int i = 0; i < size; ++i) {
        chromosomes[i] = this->chromosomes[i];
    }
}

Population::Population(Population &population) {
    this->size = population.size;
    population.chromosomes = new Chromosome[size];
    for (int i = 0; i < size; ++i) {
        population.chromosomes[i] = this->chromosomes[i];
    }
}

Population::~Population() {
    delete [] chromosomes;
}

void Population::mutation(int idx) {

}

Chromosome *Population::crossOver(Chromosome &c1, Chromosome &c2) {

}