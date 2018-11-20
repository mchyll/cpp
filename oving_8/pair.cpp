template <typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;

    Pair(T1 _first, T2 _second) : first(_first), second(_second) {}

    // Her forutsetter jeg at operatoren + er definert for type T1 og for type T2
    Pair<T1, T2> operator+(const Pair<T1, T2>& other_pair) const {
        return Pair<T1, T2>(first + other_pair.first, second + other_pair.second);
    }

    // Her forutsetter jeg at type T1 og T2 lar seg summere vha. operatoren +
    // og at denne summen lar seg sammenligne med en annen slik sum vha. operatoren >
    bool operator>(const Pair<T1, T2>& other_pair) const {
        return first + second > other_pair.first + other_pair.second;
    }
};
