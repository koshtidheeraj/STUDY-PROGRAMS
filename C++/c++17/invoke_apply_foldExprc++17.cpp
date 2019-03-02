// Example for c++17 library features.

#include <iostream>
#include <functional>
#include <tuple>
#include <utility>
using namespace std;


void globalFunction(int i) {
    cout << "global function val = " << i << endl;
}

auto add = [](int a, int b) {cout<<"apply called result = "<< a+b <<endl;};

class abc {
    public:
        int instVar = 2;
        void displayVal(int i) {
            cout<<"member function invoked val = "<<i<<endl;
        }

        template <typename... Args>
        float sumFoldUnary(Args... args) {
            return (... + args);
        }

        template <typename... Args>
        float sumFoldMultiple(Args... args) {
            return (5.0 + ... + args);
        }
};

int main()
{
    invoke(globalFunction,1);

    // invoke lambda
    invoke([](){cout<<"lambda invoked"<<endl;});

    // invoke member function
    abc obj;
    invoke(&abc::displayVal,obj,3);

    //invoke instance variable
    cout << "invoke instance variable val= " << invoke(&abc::instVar,obj) << endl;

    apply(add,make_tuple(1,2));

    cout << "folding expression unary" << obj.sumFoldUnary(1.1,1.2,1.3) << endl;
    cout << "folding expression multiplle" << obj.sumFoldMultiple(1.1,1.2,1.3) << endl;

    // auto x1 {1, 2, 3}; // error: not a single element
    auto x2 = {1, 2, 3}; // decltype(x2) is std::initializer_list<int>
    auto x3 {3}; // decltype(x3) is int
    auto x4 {3.0}; // decltype(x4) is double

    return 0;
}

// FYI:
// std::filesystem is library provides a standard way to manipulate files,
// directories, and paths in a filesystem.

// The new std::byte type provides a standard way of representing data as a byte.
// Benefits of using std::byte over char or unsigned char is that it is not a
// character type, and is also not an arithmetic type; while the only
// operator  bitwise operations i.e. &, |.

// Nested namespaces
// Using the namespace resolution operator to create nested namespace definitions.
// namespace A {
//   namespace B {
//     namespace C {
//       int i;
//     }
//   }
// }
// // vs.
// namespace A::B::C {
//   int i;
// }