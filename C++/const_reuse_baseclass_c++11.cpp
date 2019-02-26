#include <iostream>
using namespace std;

class base {
    public:
        base() {
            cout << "default constructor" << endl;
        }
        base(int a) {
            cout << "int parameterised constructor" << endl;
        }
};
class derieved : public base {
    using base::base; // This moves all constructors of base class to derieved class and
    // make them as derieved class constructors.
    // IT is all or nothing constructor inheritance. 
};
int main() {
    derieved(2);
    return 1;
}