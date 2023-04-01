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
        chromosome[i] = Gene(1.0 * rand() / RAND_MAX * 21.0 - 10.0);
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
    double newGene = (rand() * 1.0/RAND_MAX) * 21 - 10;
    chromosome[idx].setGene(newGene);
    this->myfitness();
}

Chromosome *Chromosome::crossOver(Chromosome &c) {
    int idx = rand() % size;
    double B = (rand() * 1.0/RAND_MAX) * 21 - 10;
    Chromosome child1(size), child2(size);
    Chromosome *chromosomes = new Chromosome[2];
    for (int i = 0; i < size; ++i) {
        child1.chromosome[i] = c.chromosome[i];
        child2.chromosome[i] = this->chromosome[i];
    }
    child1.chromosome[idx].setGene((1 - B) * child1.chromosome[idx].getGene() + B * child2.chromosome[idx].getGene());
    child2.chromosome[idx].setGene((1 + B) * child2.chromosome[idx].getGene() - B * child1.chromosome[idx].getGene());
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
