#include <iostream>

int find_sum(const int *table, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += table[i];
    }
    return sum;
}

int main() {
    using namespace std;
    
    int tab[20];
    for (int i = 0; i < 20; i++) {
        tab[i] = i + 1;
    }
    
    cout << "Sum 10 første (1-10): " << find_sum(tab, 10) << endl;
    cout << "Sum neste 5 (11-15): " << find_sum(&tab[10], 5) << endl;
    cout << "Sum siste 5 (16-20): " << find_sum(&tab[15], 5) << endl;
}
