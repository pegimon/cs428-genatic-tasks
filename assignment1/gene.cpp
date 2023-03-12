#include "gene.h"

bool Gene::getGene() {
    return gene;
}

void Gene::setGene(bool g) {
    gene = g;
}

Gene::Gene() {
    gene = false;
}

Gene::Gene(bool g) {
    gene = g;
}