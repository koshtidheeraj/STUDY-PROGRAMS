#include <iostream>
using namespace std;

class base {
    public:
       virtual void display() {
           cout << "base" << endl;
       } 
};
class derieved : public base {
    public:
        virtual void display(int a) override { 
        // this program will fail because display is asked to override base class display
        // function but due to signature difference it is not actually overriding it.
            cout << "derived" << endl;
        }
};
int main() {
    base *baseptr = new derieved();
    baseptr->display();
    return 1;
}