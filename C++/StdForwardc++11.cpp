#include <iostream>
#include <utility>
using namespace std;
int objcount = 0;
class forwardEx {
    public:
    
    template <typename T>
    void outer(T &&a) {
        inner(a);  // This sends a as l value even it is received as rvalue.
        inner(std::forward<T>(a)); // This checks if a is of lvalue or rvalue
        // and if it is rvalue then function at line 18 is called.
    }

    void inner(int &a) {
        cout << "L value" <<endl;
    }
    void inner(int &&a) {
        cout << "R value" <<endl;
    }

};
int main() {
    forwardEx obj;
    obj.outer(2); // Here 2 is rvalue
    cout << endl;
    int b = 3;
    obj.outer(b); // NHere b is lvalue.
    return 1;
}

//  refer : http://www.cplusplus.com/reference/utility/forward/