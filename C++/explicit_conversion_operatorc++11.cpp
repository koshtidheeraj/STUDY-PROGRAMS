#include <iostream>
using namespace std;

class base {
    public:
        base() {}
        void display(int a) {
            cout << "display function" << endl;
        }
        operator int() {
            cout << "int operator" << endl;
            return 1;            
        }
};
int main() {
    base obj;
    obj.display(obj); 
    // Above function call will output 
    // int operator
    // display function
    // because display(obj) will implicitly call int conversion opoerator at line 10.
    // To avoid this implicit conversion prepend explicit before line 10.
    // This explicit for conversion operator is added in c++11
    return 1;
}