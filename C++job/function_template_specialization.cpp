#include <iostream>

template<class T>
void template_func(T a) {
    std::cout << "generic template" << std::endl;
}

template<>
void template_func(int a) {
    std::cout << "int specialized template" << std::endl;
}

int main() {
    template_func(3);
    template_func(1.1);
    return 1;
}