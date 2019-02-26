#include <iostream>
using namespace std;

class base {
    public:
        base() {}
        base(int a) {
            cout << "int constructor" << endl;
        }
        void display(base a) {
            cout << "display function" << endl;
        }
        operator int() {
            cout << "int operator" << endl;
            
        }
};
int main() {
    base obj;
    obj.display(2); 
    // Above function call will output 
    // int constructor
    // display function
    // because display(2) will implicitly call int parameterised constructor at line 7.
    // To avoid this implicit conversion prepend explicit before line 7
    return 1;
}