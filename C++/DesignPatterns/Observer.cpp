// https://refactoring.guru/design-patterns/observer
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class subscriber;
class publisher;

class publisher {
    public:
        int state;
        vector<subscriber*> subscribers;
        void subscribe(subscriber *sub);
        void changeState(int state);
        int getState();
};

class subscriber {
    public:
        virtual void update(publisher *pub) = 0;
};
class ConcreteSubscriber1: public subscriber {
    public:
        void update(publisher *pub);
};
class ConcreteSubscriber2: public subscriber {
    public:
        void update(publisher *pub);
};

void publisher::subscribe(subscriber *sub) {
            subscribers.push_back(sub);
}
void publisher::changeState(int state) {
    this->state = state;
    for (subscriber* sub : subscribers) {
        sub->update(this);
    }
}
int publisher::getState() {return state;}

void ConcreteSubscriber1::update(publisher *pub) {
        cout << "update from ConcreteSubscriber one" << endl;
        pub->getState();
}
void ConcreteSubscriber2::update(publisher *pub) {
        cout << "update from ConcreteSubscriber two" << endl;
        pub->getState();
}

int main() {
    publisher publisherObj;
    publisherObj.state =1;
    subscriber *subscriber1 = new ConcreteSubscriber1();
    subscriber *subscriber2 = new ConcreteSubscriber2();
    publisherObj.subscribe(subscriber1);
    publisherObj.subscribe(subscriber2);

    publisherObj.changeState(2);

    return 1;
}