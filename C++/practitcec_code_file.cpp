#include <iostream>
#include <string>

using namespace std;

class Fctor{
    public:
    Fctor(int a) {
        cout << "constructor" << endl;
    }
    void operator()() {
        cout << "operator called" << endl;
    }
    void simple_function() {
        cout << "simple function called" << endl;
    }
};

int main() {
    cout << typeid(Fctor()).name() << endl;
    cout << typeid(Fctor()).name() << endl;
    Fctor().simple_function();
    return 0;
}