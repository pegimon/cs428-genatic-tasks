//
// Created by Ahmed Taha on 3/12/2023.
//

#include "population.h"

Population::Population() {
    size = rand() % 100 + 4;
    int chromosomeSize = rand() % 100 + 4;
    chromosomes = new Chromosome[size];
    for (int i = 0; i < size; ++i) {
        chromosomes[i] = Chromosome(chromosomeSize);
    }
}

Population::Population(int size) {

    this->size = size;
    int chromosomeSize = rand() % size + 4;
    chromosomes = new Chromosome[size];
    for (int i = 0; i < size; ++i) {
        chromosomes[i] = Chromosome(chromosomeSize);
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
    delete [] chromosomes;
}

int Population::getSize() {
    return size;
}

int Population::fitness() {
    int maxFitness = -1,mxidx;
    for (int i = 0; i < size; ++i) {
        int currentFitness = this->chromosomes[i].fitness();
        if (maxFitness < currentFitness) {
            maxFitness = currentFitness;
            mxidx = i;
        }
    }
    return mxidx;
}

void Population::mutation() {
    int idx = fitness();
    chromosomes[idx].mutation();
}

void Population::crossOver() {

    int idx1 = rand() % size , idx2 = rand() % size;
    while (idx1 == idx2 && size>1){
        idx2 = rand() % size;
    }
    Chromosome* c = chromosomes[idx1].crossOver(chromosomes[idx2]);
    chromosomes[idx1] = c[0];
    chromosomes[idx2] = c[1];
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
    if(p.size == this->size){
        for (int i = 0; i < size; ++i) {
            if (this->chromosomes[i] == p.chromosomes[i])continue;
            else return false;
        }
    }else return false;
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