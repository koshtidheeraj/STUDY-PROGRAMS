#include <iostream>
using namespace std;

class A {
    public:
        int n;
        A() {
            cout << "A's default constructor " << endl;
            n = 0;
        }
        A(int i) {
            cout << "A constructed with: " << i << endl;
            n = i;
        }
        void functioninvoke() {
            cout << "Function invoked with n= " << n<< endl;
        }
};
int main() {
    // A* aptr = new A(2);
    // aptr->functioninvoke();

    A* aptr2 = new A[3];
    // for (int i = 0; i < 3; i++)
    // {
    //     aptr2[i] = new A(i);
    // }
    for ( int i = 0; i < 3; i++)
    {
        aptr2[i].functioninvoke();
    }
    delete[] aptr2;
    return 1;
}