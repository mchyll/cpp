#include <iostream>

int main() {
    using namespace std;

    const int length = 5;

    int low = 0;  // Number of temperatures below 10
    int mid = 0;  // Num temp between 10 and 20
    int high = 0; // Num temp over 20

    cout << "Du skal skrive inn " << length << " temperaturer." << endl;
    for (int i = 0; i < length; i++) {
        cout << "Temperatur nr " << (i + 1) << ": ";

        double temp;
        cin >> temp;

        if (temp < 10) {
            low++;
        } else if (temp <= 20) {
            mid++;
        } else {
            high++;
        }
    }

    cout << "Antall under 10 er " << low << endl;
    cout << "Antall mellom 10 og 20 er " << mid << endl;
    cout << "Antall over 20 er " << high << endl;
}
