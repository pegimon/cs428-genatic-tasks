#include <iostream>
#include "population.h"
int main() {
    Population p(5);
    int count=0;
    while (true){
        count++;
        p.crossOver();
        p.mutation();
        cout<<p<<endl;
    }
    cout<<p<<endl;
    return 0;
}
