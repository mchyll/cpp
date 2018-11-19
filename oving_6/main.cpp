#include <iostream>

using namespace std;

class TestType {
public:
    int value;
    TestType(int v) : value(v) {}
};

class Test {
public:
    Test(TestType ty) {
        cout << "Test constuctor parameter: " << ty.value << endl;
    }
};

int main() {
    int value = 2;
    Test(TestType(value));
    std::cout << "Hello World!\n";
}
