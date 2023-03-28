//
// Created by Ahmed Taha on 3/12/2023.
//

#include "population.h"

Population::Population() {
    size = 10;
    int chromosomeSize = 32;
    chromosomes = new Chromosome[size];
    for (int i = 0; i < size; ++i) {
        chromosomes[i] = Chromosome(chromosomeSize);
    }
}

Population::Population(int size) {
    srand(::time(NULL));
    this->size = size;
    int chromosomeSize = rand() % size + 4;
    chromosomes = new Chromosome[size];
    for (int i = 0; i < size; ++i) {
        chromosomes[i] = Chromosome(32);
    }
}

Population::Population(int popsize, int C_size) {
    srand(::time(NULL));
    this->size = popsize;
    int chromosomeSize = rand() % size + 4;
    chromosomes = new Chromosome[size];
    for (int i = 0; i < size; ++i) {
        chromosomes[i] = Chromosome(C_size);
    }
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
    delete[] chromosomes;
}

int Population::getSize() {
    return size;
}

pair<int, int> Population::fitness() {
    int maxFitness = -1, mxidx;
    for (int i = 0; i < size; ++i) {
        int currentFitness = this->chromosomes[i].get_fitness();
        if (maxFitness < currentFitness) {
            maxFitness = currentFitness;
            mxidx = i;
        }
    }
    return {mxidx, maxFitness};
}

void Population::mutation() {
    for (int i = 0; i < size; ++i) {
        ////1% probability for mutation
        if (rand() % 100 >= 80) {
            chromosomes[i].mutation();
        }
    }
}

void Population::crossOver() {

    int idx1 = rand() % size, idx2 = rand() % size;
    while (idx1 == idx2 && size > 1) {
        idx2 = rand() % size;
    }
    Chromosome *c = chromosomes[idx1].crossOver(chromosomes[idx2]);
    map<int, int> fitnesses;
    for (int i = 0; i < size; ++i) {
        fitnesses[chromosomes[i].get_fitness()] = i;
    }
    auto it = fitnesses.begin();
    if (c[0].get_fitness() > chromosomes[it->second].get_fitness())chromosomes[it->second] = c[0];
    it++;
    if (c[1].get_fitness() > chromosomes[it->second].get_fitness())chromosomes[it->second] = c[1];
}

Population &Population::operator=(const Population &c) {
    this->size = c.size;
    this->chromosomes = new Chromosome[size];
    for (int i = 0; i < size; ++i) {
        this->chromosomes[i] = c.chromosomes[i];
    }
    return *this;
}

bool Population::operator==(const Population &p) {
    if (p.size == this->size) {
        for (int i = 0; i < size; ++i) {
            if (this->chromosomes[i] == p.chromosomes[i])continue;
            else return false;
        }
    } else return false;
    return true;
}

ostream &operator<<(ostream &out, const Population &p) {
    for (int i = 0; i < p.size; ++i) {
        out << p.chromosomes[i] << '\n';
    }
    return out;
}

istream &operator>>(istream &in, const Population &p) {
    for (int i = 0; i < p.size; ++i) {
        in >> p.chromosomes[i];
    }
    return in;
}

double Population::mean() {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += this->chromosomes[i].get_fitness();
    }
    return (sum * 1.0) / size;
}

double Population::var() {
    double variance = 0, mean = this->mean();
    for (int i = 0; i < size; ++i) {
        variance += ((this->chromosomes[i].get_fitness() - mean) * (this->chromosomes[i].get_fitness() - mean) * 1.0 /
                     (size - 1));
    }
    return variance;
}

int Population::maximum() {
    return this->fitness().second;
}

int Population::minimum() {
    int mnm = 1e9;
    for (int i = 0; i < size; ++i) {
        mnm = min(mnm, this->chromosomes[i].get_fitness());
    }
    return mnm;
}




