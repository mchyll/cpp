#include <vector>
#include <iostream>
#include "set.hpp"

Set::Set() : elements(std::vector<int>()) {}

Set::Set(const std::vector<int>& _elements) : elements(_elements) {}

Set& Set::operator+=(int new_element) {
    bool exists = false;
    for (int my_elem : elements) {
        if (my_elem == new_element) {
            exists = true;
            break;
        }
    }

    if (!exists) {
        elements.emplace_back(new_element);
    }

    return *this;
}

Set& Set::operator+=(const Set& other_set) {
    for (int other_set_elem : other_set.elements) {
        bool exists = false;
        for (int my_elem : elements) {
            if (my_elem == other_set_elem) {
                exists = true;
                break;
            }
        }

        if (!exists) {
            elements.emplace_back(other_set_elem);
        }
    }

    return *this;
}

Set Set::operator+(int new_element) const {
    Set new_set(elements);
    new_set += new_element;
    return new_set;
}

Set Set::operator+(const Set &other_set) const {
    Set new_set(elements);
    new_set += other_set;
    return new_set;
}

Set& Set::operator=(const Set &other_set) {
    elements = other_set.elements;
    return *this;
}

std::ostream& operator<<(std::ostream &out, const Set &set) {
    out << "{";
    size_t num_elems = set.elements.size();
    for (size_t i = 0; i < num_elems; i++) {
        out << set.elements.at(i);
        if (i != num_elems - 1) {
            out << ", ";
        }
    }
    out << "}";
    return out;
}
