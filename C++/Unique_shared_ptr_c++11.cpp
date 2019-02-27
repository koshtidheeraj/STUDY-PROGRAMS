#include <iostream>
#include <memory>
using namespace std;
int objcount = 0;
class PtrEx {
    public:
        PtrEx() {
            cout << "default constructor" << endl;
        }
        PtrEx(PtrEx& ref) {
            cout << "copy constructor" << endl;
        }
        PtrEx(PtrEx&& ref) {
            cout << "move constructor" << endl;
        }
        int a;
};
int main() {
    unique_ptr<PtrEx> pu1(new PtrEx);
    pu1->a = 2;
    // unique_ptr<PtrEx> p2 = p1; // you cannot copy unique pointer, so this will give compile
    // error but as per below line you can move ownership.

    unique_ptr<PtrEx> pu2 = move(pu1); // This will not call move constructor of PtrEx.
    //Above line will call move constructor of uniqur_ptr class.

    // Below line will not give compile error but at runtime it gives segmentation fault.
    // cout << p1->a << endl; 

    cout << pu2->a << endl; // this is OK because ownership is transferred to pu2.

    shared_ptr<PtrEx> ps1(new PtrEx);
    ps1->a = 3;
    shared_ptr<PtrEx> ps2 = ps1; // shared pointer allows copy
    // Above line will not call copy constructor of PtrEx.
    // It might be calling copy constructor of uniqur_ptr class.

    cout << ps2->a << endl;
    return 1;
}