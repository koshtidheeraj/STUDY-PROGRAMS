#include <iostream>
using namespace std;

class independent {

};
class base1 {
    public:
    void display() {
        cout << "base_one" << endl;
    }
};

class derived1 : public base1 {
    void display() {
        cout << "derieved_one" << endl;
    }
};

class base2 {
    public:
    virtual void display() {
        cout << "base_two" << endl;
    }
};

class derived2 : public base2 {
    void display() {
        cout << "derieved_two" << endl;
    }
};

int main() {
    base1 *base1ptr, base1obj;
    derived1 *derived1ptr, derived1obj;

    base2 *base2ptr, base2obj;
    derived2 *derived2ptr, derived2obj;

    // base1ptr = static_cast<base1*> (base2ptr);  // compile error
    derived1ptr = static_cast<derived1*> (base1ptr); // works

    // derived1ptr = dynamic_cast<derived1*> (base1ptr); // compile error
    base2ptr = &derived2obj;
    derived2ptr = dynamic_cast<derived2*> (base2ptr); // works
    if (derived2ptr == NULL) {
        cout << "derieved null" <<endl;
    }
    base2ptr = &base2obj;
    derived2ptr = dynamic_cast<derived2*> (base2ptr); // runtime derived2ptr becomes null
    if (derived2ptr == NULL) {
        cout << "base null" <<endl;
    }
    
    base1ptr = dynamic_cast<base1*>(derived1ptr);
    return 1;
}