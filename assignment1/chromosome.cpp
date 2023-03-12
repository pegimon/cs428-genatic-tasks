#include "chromosome.h"
Chromosome::Chromosome() {
    size = 0;
    chromosome = nullptr;
}

Chromosome::Chromosome(int size) {
    this->size = size;
    chromosome = new Gene[size];
    for (int i = 0; i < size; ++i) {
        chromosome[i] = new Gene(false);
    }
}

Chromosome::Chromosome(Chromosome &c) {
    this->size = c.size;
    chromosome = new Gene[size];
    for (int i = 0; i < size; ++i) {
        this->chromosome[i] = c.chromosome[i];
    }
}

Chromosome::~Chromosome() {
    delete [] chromosome;
}