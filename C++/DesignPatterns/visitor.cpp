// https://refactoring.guru/design-patterns/visitor
#include <iostream>
using namespace std;

class visitor;

class element {
    public:
        int id;
        void accept(visitor* v) {
            v->visit(this);
        }
};
class ConcreteElement1 : public element {
    public:
        ConcreteElement1():id(1){}
};
class ConcreteElement2 : public element {
    public:
        ConcreteElement2():id(2){}
};
class ConcreteElement3 : public element {
    public:
        ConcreteElement3():id(3){}
};

class visitor {};
class ConcreteVisitor : public visitor {
    void visit(ConcreteElement1 &el) {
        cout << "concrete element" << el.id << endl;
    }
    void visit(ConcreteElement2 &el) {
        cout << "concrete element" << el.id << endl;
    }
    void visit(ConcreteElement3 &el) {
        cout << "concrete element" << el.id << endl;
    }
};

int main() {
    ConcreteElement1 el1;
    ConcreteElement2 el2;
    ConcreteElement3 el3;

    ConcreteVisitor visitor;
    el1.accept(visitor);
    el2.accept(visitor);
    el3.accept(visitor);
    return 1;
}