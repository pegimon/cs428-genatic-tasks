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
};
#endif //ASSIGNMENT1_GENE_H
