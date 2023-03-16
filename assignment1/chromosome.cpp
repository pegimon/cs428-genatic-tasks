#include "chromosome.h"

Chromosome::Chromosome() {
    size = 0;
    chromosome = nullptr;
    fitness = -1;
}

Chromosome::Chromosome(int size) {
    this->size = size;
    chromosome = new Gene[size];
    for (int i = 0; i < size; ++i) {
        chromosome[i] = Gene(rand() & 1);
    }
    myfitness();
}

Chromosome::Chromosome(Chromosome &c) {
    this->size = c.size;
    chromosome = new Gene[size];
    for (int i = 0; i < size; ++i) {
        this->chromosome[i] = c.chromosome[i];
    }
    this->fitness = c.fitness;
}

Chromosome::~Chromosome() {
    delete[] chromosome;
}

Chromosome::Chromosome(Gene *genes, int size) {
    this->size = size;
    chromosome = new Gene[size];
    for (int i = 0; i < size; ++i) {
        chromosome[i] = genes[i];
    }
    myfitness();
}

void Chromosome::myfitness() {
    fitness = 0;
    for (int i = 0; i < size; ++i) {
        fitness += this->chromosome[i].getGene();
    }

}

void Chromosome::mutation() {

    int idx = rand() % size;
    if (!chromosome[idx].getGene()) {
        chromosome[idx].setGene(true);
    }
    this->myfitness();

}

Chromosome *Chromosome::crossOver(Chromosome &c) {
    int idx = rand() % min(size, c.size);
    Chromosome child1(this->size), child2(c.size);
    Chromosome *chromosomes = new Chromosome[2];
    for (int i = 0; i < idx; ++i) {
        child1.chromosome[i] = c.chromosome[i];
        child2.chromosome[i] = this->chromosome[i];
    }
    for (int i = idx; i < size; ++i) {
        child1.chromosome[i] = this->chromosome[i];
        child2.chromosome[i] = c.chromosome[i];
    }
    child1.myfitness();
    child2.myfitness();
    chromosomes[0] = child1;
    chromosomes[1] = child2;

    return chromosomes;
}

Chromosome &Chromosome::operator=(const Chromosome &c) {
    size = c.size;
    this->chromosome = new Gene[size];
    for (int i = 0; i < size; ++i) {
        this->chromosome[i] = c.chromosome[i];
    }
    this->myfitness();
    return *this;
}

bool Chromosome::operator==(const Chromosome &c) {
    size = c.size;
    this->chromosome = new Gene[size];
    if (size == c.size) {
        for (int i = 0; i < size; i++) {
            if (!(chromosome[i] == c.chromosome[i]))
                return false;
        }
        return true;
    }
    return false;
}

ostream &operator<<(ostream &out, const Chromosome &c) {
    for (int i = 0; i < c.size; ++i) {
        out << c.chromosome[i] << ' ';
    }
    return out;
}

istream &operator>>(istream &in, Chromosome &c) {
    for (int i = 0; i < c.size; ++i) {
        in >> c.chromosome[i];
    }
    return in;
}

int Chromosome::get_fitness() {
    return fitness;
}
