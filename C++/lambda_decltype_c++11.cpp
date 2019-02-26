#include <iostream>
using namespace std;

int main() {
    auto lambda = [](int a)->int { cout << "value = " << ++a << endl;};
    lambda(2);

    int a;
    decltype(a) b; // this will take type of variable 'a' and declare variable b of same type.
    return 1;
}