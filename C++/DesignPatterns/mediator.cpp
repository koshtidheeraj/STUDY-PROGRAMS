// https://refactoring.guru/design-patterns/mediator

// Here may nodes are scattered and they do not communicate with each other directly.
// They communicate via mediator.

#include <iostream>
#include <string>
using namespace std;
class mediator;

class component {
    public:
    mediator * mediatorInst;
    char* type;
    component(mediator *mediatorInst, char *type):mediatorInst(mediatorInst),type(type) {}
};
class textbox: public component {
    public:
        textbox(mediator *mediatorInst):component(mediatorInst, "textbox"){}
        void textEntered() {
            mediatorInst->notify(this);
        }
};
class checkbox: public component {
    public:
        checkbox(mediator *mediatorInst):component(mediatorInst, "checkbox"){}
        void optionSelected() {
            mediatorInst->notify(this);
        }
};

class mediator {
    public:
        virtual void notify(component *comp) = 0;
};
class ConcreteMediator : public mediator{
    public:
    checkbox box;
    
    void notify(component *comp) {
        if (comp->type == "textbox") {
            box->optionSelected();
        } else {
            cout << "no action needed" << endl;
        }
    }
};

int main() {
    mediator *mediatorptr = new ConcreteMediator();

    textbox *textboxptr = new textbox(mediatorptr);
    textboxptr->textEntered();
    
    return 1;
}