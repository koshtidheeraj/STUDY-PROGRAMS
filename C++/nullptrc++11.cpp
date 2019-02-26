#include <iostream>
using namespace std;

class base {
    public:
        void display(char*) {
            cout << "char* display" << endl;
        }
        void display(int) {
            cout << "int display" << endl;
        }
};
int main() {
    base obj;
    obj.display(nullptr);
    obj.display(0);
     // nullptr is 0 but it is for pointer type in c++11. so output of program is
     // char* display
     // int display
    return 1;
}