#include "gene.h"

double Gene::getGene() {
    return gene;
}

void Gene::setGene(double g) {
    gene = g;
}

Gene::Gene() {
    gene = 0.0;
}

Gene::Gene(double g) {
    gene = g;
}

Gene &Gene::operator=(const Gene &g) {
    this->gene = g.gene;
    return *this;
}

double Gene::operator==(const Gene &g) {
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
    double input;
    in >> input;
    g.setGene(input);
    return in;
}