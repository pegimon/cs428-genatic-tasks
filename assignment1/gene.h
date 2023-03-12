#ifndef ASSIGNMENT1_GENE_H
#define ASSIGNMENT1_GENE_H
#include <bits/stdc++.h>
using namespace std;
class Gene {
    bool gene;

public:
    Gene();
    Gene(bool g);
    bool getGene();
    void setGene(bool g);
    Gene &operator=(const Gene &g);
    bool operator==(const Gene &g);
    friend ostream& operator<< (ostream& out, const Gene& g);
    friend istream& operator>> (istream& in, const Gene& g);
};
#endif //ASSIGNMENT1_GENE_H
