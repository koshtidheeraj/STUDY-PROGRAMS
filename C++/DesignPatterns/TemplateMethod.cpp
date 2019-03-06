// https://sourcemaking.com/design_patterns/template_method
#include <iostream>

using namespace std;

class basesort {
    public:
    void sort() {
        // This is template method because in this method we can see all steps going
        // to be executed and at runtime inherited, methods steps get called.
        this->step1();
        this->step2();
        this->step3();
    }
    void step1() {
        cout << "base step1" << endl;
    }
    virtual void step2() {
        cout << "base step2" << endl;
    }
    void step3() {
        cout << "base step3" << endl << endl;
    }
};
class ascendingSort : public basesort {
    public:
    void step2() {
        cout << "ascendingSort step2" << endl;
        // Here do specialised treatment for Ascending sort
    }
};
class descendingSort : public basesort {
    public:
    void step2() {
        cout << "descendingSort step2" << endl;
        // Here do specialised treatment for descending sort
    }
};

int main() {
    basesort *ascend = new ascendingSort(); 
    ascend->sort();

    basesort *descend = new descendingSort(); 
    descend->sort();
    return 0;
}