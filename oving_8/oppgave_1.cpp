#include <iostream>
#include <cmath>

using namespace std;

template <typename Type>
bool equal(const Type& type1, const Type& type2) {
    cout << "Bruker template-versjon av equal" << endl;
    return type1 == type2;
}

bool equal(double d1, double d2) {
    cout << "Bruker double-spesialisering av equal" << endl;
    return fabs(d1 - d2) < 0.00001;
}

int main() {
    string s1 = "Hei verden";
    string s2 = "Hei verden!";
    bool is_equal = equal(s1, s2);
    cout << s1 << " og " << s2 << " like: " << boolalpha << is_equal << endl << endl;

    double d1 = 1;
    double d2 = 0.999999;
    is_equal = equal(d1, d2);
    cout << d1 << " og " << d2 << " like: " << boolalpha << is_equal << endl << endl;

    double d3 = 10;
    double d4 = -10;
    is_equal = equal(d3, d4);
    cout << d3 << " og " << d4 << " like: " << boolalpha << is_equal << endl;
}
