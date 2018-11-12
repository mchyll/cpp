#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  using namespace std;

  vector<double> numbers = {10, -13.4, 3.14, 44, 0.8};

  cout << "Front: " << numbers.front() << endl;
  cout << "Back: " << numbers.back() << endl;

  numbers.emplace(numbers.begin() + 1, 999);
  cout << "Front etter emplace: " << numbers.front() << endl;

  auto found_iterator = find(numbers.begin(), numbers.end(), 44);
  if (found_iterator == numbers.end()) {
    cout << "Fant ikke tallet" << endl;
  } else {
    cout << "Fant tallet " << *found_iterator << " i numbers" << endl;
  }
}
