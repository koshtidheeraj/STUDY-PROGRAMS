#include<iostream>
using namespace std;

class second;

class first {
    public:
        void display(second instance);

};
class second {
    private:
        int a;
    public:
        friend class first;
        second():a(2) {}
};

void first::display(second instance) {
            cout << "value is " << instance.a << endl;
        }
int main() {
    first firstobj;
    second secondobj;
    firstobj.display(secondobj);
    return 1;
}