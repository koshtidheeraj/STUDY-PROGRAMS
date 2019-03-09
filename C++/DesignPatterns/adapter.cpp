// https://refactoring.guru/design-patterns/adapter
// Here toy bird is adapted to behave as real bird.

#include <iostream>
#include <string>
using namespace std;

class bird {
    public:
        virtual void chirp() = 0;
};
class ConcreteBirdSparrow : public bird {
    public:
       void chirp() {
           cout << "concrete sparrow chirp" <<endl;
       } 
};

class toy {
    public:
        virtual void toysound() = 0;
};
class ConcreteToySparrow : public toy {
    public:
        void toysound() {
            cout << "toy sparrow sound" <<endl;
        }
};

class birdAdapterForToy : public toy {
    public:
        bird *birdptr;
        birdAdapterForToy(bird *b):birdptr(b) {}
        void toysound() {
            cout << "bird chirp called from birdAdapterForToy" << endl;
            birdptr->chirp();
        }
        
};
int main() {
    bird  *b = new ConcreteBirdSparrow();
    toy *t = new birdAdapterForToy(b);
    t->toysound();
    return 1;
}