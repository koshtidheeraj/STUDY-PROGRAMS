#include <iostream>
using namespace std;

class base {
    public:
       virtual void display() final {
           cout << "base" << endl;
       } 
};
class derieved : public base {
    public:
        virtual void display()  {
            // This code will not compile because display in base class is final and in
            // derieved class you are trying to override it.
            cout << "derived" << endl;
        }
};
int main() {
    base *baseptr = new derieved();
    baseptr->display();
    return 1;
}