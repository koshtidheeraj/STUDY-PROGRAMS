// https://refactoring.guru/design-patterns/state

// It is finite state machine.

#include <iostream>
#include <string>
using namespace std;

class state;

class audioplayer{
    public:
        state *currentState;
        audioplayer();
        void changeState(state* state);
        void start();
        void stop();
};

class state {
    public:
        audioplayer *player;
        state(audioplayer *player) : player(player){}
        virtual void start() = 0;
        virtual void stop() = 0;
};
class ConcreteStateReady : public state {
    public:
       ConcreteStateReady(audioplayer *player) : state(player) {}
       void start();
       void stop(){}
};
class ConcreteStateStart : public state {
    public:
       ConcreteStateStart(audioplayer *player) : state(player) {}
       void start(){}
       void stop();
};
class ConcreteStateStop : public state {
    public:
       ConcreteStateStop(audioplayer *player) : state(player) {}
       void start();
       void stop() {}
};

audioplayer::audioplayer(){currentState = new ConcreteStateReady(this);}
void audioplayer::changeState(state* state) {
    delete this->currentState;
    this->currentState = state;
}
void audioplayer::start() {currentState->start();}
void audioplayer::stop() {currentState->stop();}

void ConcreteStateReady::start() {
    player->changeState(new ConcreteStateStart(player));
    cout << "ConcreteStateReady::start" << endl;
}

void ConcreteStateStart::stop() {
    player->changeState(new ConcreteStateStop(player));
    cout << "ConcreteStateStart::stop" << endl;
}

void ConcreteStateStop::start() {
    player->changeState(new ConcreteStateStart(player));
    cout << "ConcreteStateStop::start" << endl;
}

int main() {
    audioplayer player;
    player.start();
    player.stop();
    player.start();
    return 1;
}