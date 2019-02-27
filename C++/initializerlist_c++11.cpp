#include <iostream>
#include <vector>
using namespace std;
class init_list_constructor {
    public:
        init_list_constructor(std::initializer_list<int> list) {
        for (int i : list) {
            cout << "value=" << i << endl;
        }
    }
};
int main() {
    init_list_constructor obj = {1,2,3,4};
    return 1;
}

// Information:
// struct A {
//   A(int) {}
//   A(int, int) {}
//   A(int, int, int) {}
// };

// A a {0, 0}; // calls A::A(int, int)
// A b(0, 0); // calls A::A(int, int)
// A c = {0, 0}; // calls A::A(int, int)
// A d {0, 0, 0}; // calls A::A(int, int, int)

// Note that the braced list syntax does not allow narrowing:

// struct A {
//   A(int) {}
// };

// A a(1.1); // OK
// A b {1.1}; // Error narrowing conversion from double to int

// Note that if a constructor accepts a std::initializer_list, it will be called instead:

// struct A {
//   A(int) {}
//   A(int, int) {}
//   A(int, int, int) {}
//   A(std::initializer_list<int>) {}
// };

// A a {0, 0}; // calls A::A(std::initializer_list<int>)
// A b(0, 0); // calls A::A(int, int)
// A c = {0, 0}; // calls A::A(std::initializer_list<int>)
// A d {0, 0, 0}; // calls A::A(std::initializer_list<int>)


// Inline namespaces
// All members of an inline namespace are treated as if they were part of its parent namespace, allowing specialization of functions and easing the process of versioning. This is a transitive property, if A contains B, which in turn contains C and both B and C are inline namespaces, C's members can be used as if they were on A.

// namespace Program {
//   namespace Version1 {
//     int getVersion() { return 1; }
//     bool isFirstVersion() { return true; }
//   }
//   inline namespace Version2 {
//     int getVersion() { return 2; }
//   }
// }

// int version {Program::getVersion()};              // Uses getVersion() from Version2
// int oldVersion {Program::Version1::getVersion()}; // Uses getVersion() from Version1
// bool firstVersion {Program::isFirstVersion()};    // Does not compile when Version2 is added