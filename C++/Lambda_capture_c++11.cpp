#include <iostream>
using namespace std;

class base {
    public:
       int a =25; // This non static member variable initialisation is valid only in c++11
};

int main() {
    int a = 10;
    int b = 20;
    auto lambda_func = [&a, b](int c)-> int {
      ++a;
    //   ++b; this will give compile error because here b is taken as read only. 
      return (a + b + c); // 11 + 20 + 3
    };
    cout << "lambda function output value is=" << lambda_func(3) << endl;
    cout << "after lambda function a=" << a << endl;
    return 1;
}

// [] - captures nothing.
// [=] - capture local objects (local variables, parameters) in scope by value.
// [&] - capture local objects (local variables, parameters) in scope by reference.
// [this] - capture this pointer by value.
// [a, &b] - capture objects a by value, b by reference.