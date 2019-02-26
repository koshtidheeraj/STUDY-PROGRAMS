#include <iostream>
using namespace std;

class abc {
    public:
        int a;
        abc(int a) {
            this->a = a;
        }
        abc():abc(10) {} // in c++ 11, constructor can call constructor of same class.
        // just take care that infite loopm should not get created.
};
int main() {
    abc obj;
    cout << "value is " << obj.a << endl;
    return 1;
}