#include <iostream>

template<int n>
class power {
public:
    enum {
        val = 2*power<n-1>::val
    };
    void print_power() {
        std::cout << "n value is: " << val << std::endl;
    }
};

template<>
class power<0> {
public:
    enum {
        val = 1
    };
    void print_power() {
        std::cout << "n value is: " << 0 << std::endl;
    }
};

int main() {
    power<5> p;
    p.print_power();
    return 1;
}