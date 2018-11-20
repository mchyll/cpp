#include <iostream>
#include <vector>
#include "set.hpp"

using namespace std;

int main() {
    // Oppgave 2)

    Set set1(vector<int>({1, 2, 3, 4}));
    // Legge til element
    set1 += 7;
    set1 += 2;
    cout << "set1: " << set1 << endl;

    Set set2(vector<int>({3, 4, 5}));
    cout << "set2: " << set2 << endl;

    // Unionen av to mengder
    Set set_union = set1 + set2;
    cout << "union: " << set_union << endl;

    set1 = set2;
    cout << "set1 etter set1=set2: " << set1 << endl;
}
