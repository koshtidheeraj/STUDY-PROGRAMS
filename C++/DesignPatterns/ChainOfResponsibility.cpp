// https://refactoring.guru/design-patterns/chain-of-responsibility
#include <iostream>
using namespace std;

class baseHandler {
    private:
    baseHandler *nextHandler = nullptr;
    public:
    void setNextHandler(baseHandler *handler) {
        nextHandler = handler;
    }
    virtual void handle() {
        if (nextHandler != nullptr) {
            nextHandler->handle();
        } 
    };
};
class concreteHandlerOne : public baseHandler {
    public:
        void handle() {
            cout << "concreteHandlerOne invoked" << endl;
            baseHandler::handle();
        }
};
class concreteHandlerTwo : public baseHandler{
    public:
        void handle() {
            cout << "cooncreteHandlerTwo invoked" << endl;
            baseHandler::handle();
        }
};
class concreteHandlerThree : public baseHandler {
    public:
        void handle() {
            cout << "cooncreteHandlerThree invoked" << endl;
            baseHandler::handle();
        }
};
int main() {
    baseHandler *handler1 = new concreteHandlerOne();
    baseHandler *handler2 = new concreteHandlerTwo();
    baseHandler *handler3 = new concreteHandlerThree();
    handler1->setNextHandler(handler2);
    handler2->setNextHandler(handler3);

    // start chain of handling
    handler1->handle();
    return 1;
}