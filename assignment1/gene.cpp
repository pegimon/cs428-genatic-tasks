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
    out << g.gene;
    return out;
}

istream& operator>> (istream& in,Gene& g){
    bool input;
    in >> input;
    g.setGene(input);
    return in;
}