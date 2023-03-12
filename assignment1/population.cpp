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

void Population::mutation(int idx) {

}

Chromosome *Population::crossOver(Chromosome &c1, Chromosome &c2) {

}