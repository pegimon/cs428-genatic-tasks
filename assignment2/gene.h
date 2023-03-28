#ifndef ASSIGNMENT1_GENE_H
#define ASSIGNMENT1_GENE_H
#include <bits/stdc++.h>

using namespace std;
class Gene {
    double gene;

public:
    Gene();
    Gene(double g);
    double getGene();
    void setGene(double g);
    Gene &operator=(const Gene &g);
    double operator==(const Gene &g);
    friend ostream& operator<< (ostream& out, const Gene& g);
    friend istream& operator>> (istream& in, Gene& g);
};
#endif //ASSIGNMENT1_GENE_H
