#include <iostream>
#include "population.h"
#define el '\n'
int main() {
    Population p(5);
    int count=0,fitness = p.fitness().second;
    int arr[1000];
    for (int i = 0; i < 1000; ++i) {
        arr[i] = 0;
    }
    int mnm = 1e6;
    while (fitness<32){
        p.crossOver();
        p.mutation();
        fitness = p.fitness().second;
        arr[count] = fitness;
        mnm = min(mnm , fitness);
        count++;
        cout<<p;
        cout <<"mean: " << p.mean() << ", max: " << p.maximum() << ", min: " << p.minimum() << ", variance: " << p.var() << el << el;
    }
    int sum = 0;
    for (int i : arr) {
        sum += i;
    }
    double mean = double(sum)/count;
    double variance = 0;
    for (int i : arr) {
        if(i == 0) continue;
        variance += ((i - mean) * (i - mean) * 1.0 / (count-1));
    }
    cout<<p<<endl;
    cout << "gen " << count << '\n';
    cout << "min: " << mnm << ", max: " << fitness << ", mean: " << mean << ", variance: " << variance << '\n';
    return 0;
}
