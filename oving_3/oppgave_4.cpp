#include <iostream>
#include <string>

int main() {
    using namespace std;
    
    // Oppgave a)
    string word1, word2, word3;
    cin >> word1;
    cin >> word2;
    cin >> word3;
    
    // Oppgave b)
    string sentence = word1 + " " + word2 + " " + word3 + ".";
    cout << sentence << endl << endl;
    
    // Oppgave c)
    cout << "Lengde word1: " << word1.length() << endl;
    cout << "Lengde word2: " << word2.length() << endl;
    cout << "Lengde word3: " << word3.length() << endl;
    cout << "Lengde sentence: " << sentence.length() << endl << endl;
    
    // Oppgave d)
    string sentence2 = sentence;
    
    // Oppgave e)
    for (size_t i = 9; i <= 11 && i < sentence2.length(); i++) {
        sentence2[i] = 'x';
    }
    cout << "sentence: " << sentence << endl;
    cout << "sentence2: " << sentence2 << endl << endl;
    
    // Oppgave f)
    string sentence_start = sentence.substr(0, 5);
    cout << "sentence: " << sentence << endl;
    cout << "sentence_start: " << sentence_start << endl << endl;
    
    // Oppgave g)
    size_t hallo_index = sentence.find("hallo");
    if (hallo_index == string::npos) {
        cout << "Fant ikke 'hallo' i sentence" << endl << endl;
    }
    else {
        cout << "Fant 'hallo' i sentence på posisjon " << hallo_index << endl << endl;
    }
    
    // Oppgave h)
    size_t er_index = sentence.find("er");
    if (er_index == string::npos) {
        cout << "Fant ikke 'er' i sentence" << endl;
    }
    else {
        while (er_index != string::npos) {
            cout << "Fant 'er' i sentence på posisjon " << er_index << endl;
            er_index = sentence.find("er", er_index + 1);
        }
    }
}
