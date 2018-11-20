#pragma once
#include <iostream>
#include <vector>

class Set {
private:
    std::vector<int> elements;

public:
    Set();
    Set(const std::vector<int>& _elements);
    Set& operator+=(int new_element);
    Set& operator+=(const Set& other_set);
    Set operator+(int new_element) const;
    Set operator+(const Set& other_set) const;
    Set& operator=(const Set& other_set);
    friend std::ostream& operator<<(std::ostream& out, const Set& set);
};
