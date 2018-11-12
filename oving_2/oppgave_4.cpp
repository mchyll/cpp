int main() {
    /*
    Opprinnelig kode:
    
    int a = 5;
    int &b;
    int *c;
    c = &b;
    *a = *b + *c;
    &b = 2;
    */

    int a = 5;
    int &b = a;  // b er en referanse og må derfor initialiseres
    int *c;
    c = &b;
    a = b + *c;  // a og b er ikke pekere, vi bruker derfor ikke * for å dereferere de
    b = 2;       // Vi bruker ikke & når vi skal sette verdien til b
}
