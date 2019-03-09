https://www.geeksforgeeks.org/flyweight-design-pattern/
https://refactoring.guru/design-patterns/flyweight

// Here the things which are common, for those new instance is not created only
// one instance is created.
// New instances are created for variable parameters and the common instance is shared there.

#include <iostream>
#include <vector>
using namespace std;

class weapon {};
class gun : public weapon {};   // The instance of this gun will be shared with different
                                //instances of players

class player {
    public:
        weapon *wep;
        player(weapon *weapon):wep(weapon){}
};
class goodman : public player {
    public:
        goodman(weapon *weapon):player(wep) {}
};
class badman : public player {
    public:
        badman(weapon *weapon):player(wep) {}
};

int main() {
    gun gun1;
    player *good1 = new goodman(&gun1);
    player *bad1 = new badman(&gun1);
    return 1;
}