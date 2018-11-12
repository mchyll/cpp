#include <iostream>
#include <string.h>

int main() {
    using namespace std;

    // Oppgave a)
    int i = 3;
    int j = 5;
    int *p = &i;
    int *q = &j;

    cout << "Adresse i: " << &i << ", verdi: " << i << endl;
    cout << "Adresse j: " << &j << ", verdi: " << j << endl;
    cout << "Adresse p: " << &p << ", verdi: " << *p << endl;
    cout << "Adresse q: " << &q << ", verdi: " << *q << endl;


    // Oppgave b)
    *p = 7;
    *q += 4;
    *q = *p + 1;
    p = q;

    cout << *p << " " << *q << endl;
}
