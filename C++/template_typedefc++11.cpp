#include <iostream>
using namespace std;

template <typename T, typename U>
class abc {
    public:
        T a;
        U b;
        void display() {
            cout << "template print" << endl;
        }
};

template <typename Z>
using intSpecializedTemtypedef = abc<int,Z>;

int main() {
    intSpecializedTemtypedef<float> obj;
    obj.display();
    return 1;
}

// The using syntax can also be used as type aliasing in C++11:

// typedef void (*FunctionType)(double);       // Old style
// using FunctionType = void (*)(double); // New introduced syntax