#include "chromosome.h"
Chromosome::Chromosome() {
    size = 0;
    chromosome = nullptr;
}

Chromosome::Chromosome(int size) {
    srand(seed);
    this->size = size;
    chromosome = new Gene[size];
    for (int i = 0; i < size; ++i) {
        chromosome[i] = new Gene(rand()&1);
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

Chromosome::Chromosome(Gene *genes, int size) {
    this->size = size;
    chromosome = new Gene[size];
    for (int i = 0; i < size; ++i) {
        chromosome[i] = genes[i];
    }
}

int Chromosome::fitness() {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += this->chromosome[i].getGene();
    }
    return sum;
}

void Chromosome::mutation() {
    srand(seed);
    int idx = rand() % size;
    if (chromosome[idx].getGene()){
        chromosome[idx].setGene(false);
    }else {
        chromosome[idx].setGene(true);
    }
}

Chromosome *Chromosome::crossOver(Chromosome &c) {
    srand(seed);
    int idx = rand() % min(size,c.size);
    Chromosome *chromosomes = new Chromosome[2];
    for (int i = 0; i < idx; ++i) {
        Gene tmp = c.chromosome[i];
        c.chromosome[i] = this->chromosome[i];
        this->chromosome[i] = tmp;
    }
    for (int i = idx; i < min(this->size, c.size); ++i) {
        Gene tmp = c.chromosome[i];
        c.chromosome[i] = this->chromosome[i];
        this->chromosome[i] = tmp;
    }
    chromosomes[0] = *this;
    chromosomes[1] = c;
    return chromosomes;
}

Chromosome &Chromosome::operator=(const Chromosome &c) {
    size = c.size;
    this->chromosome = new Gene[size];
    for (int i = 0; i < size; ++i) {
        this->chromosome[i] = c.chromosome[i];
    }
    return *this;
}
