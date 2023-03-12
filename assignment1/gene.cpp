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

Gene &Gene::operator=(const Gene &g) {
    this->gene = g.gene;
}

bool Gene::operator==(const Gene &g) {
    if (this->gene == g.gene){
        return true;
    }
    return false;
}

ostream &operator<< (ostream& out, const Gene& g){
    return out << g << '/';
}

istream& operator>> (istream& in, const Gene& g){
    return in >> g >> '/';
}