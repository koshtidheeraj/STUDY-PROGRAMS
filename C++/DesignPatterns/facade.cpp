https://www.geeksforgeeks.org/facade-design-pattern-introduction/
https://refactoring.guru/design-patterns/facade

// Here facade supposed to know all internal implemantation and
// we get simple interface to access internal complexities

#include <iostream>
#include <string>
using namespace std;

class menu {};
class vegMenu : public menu {};
class nonvegMenu : public menu {};

class hotel {
    public:
        virtual menu getVegMenu() = 0;
        virtual menu getNonvegMenu() = 0; 
};
class AshokaHotel : public hotel {
    public:
    menu getVegMenu() {
        return new vegMenu();
    }
    menu getNonvegMenu() {
        return new nonvegMenu();
    }  
};

class receptionFacade {
    public:
        menu getVegMenu() {
            hotel *hotelptr = new AshokaHotel();
            return hotelptr->getVegMenu();
        }
        menu getnonvegmenu() {
            hotel *hotelptr = new AshokaHotel();
            return hotelptr->getNonvegMenu();
        }
};
int main() {
    receptionFacade reception;
    reception.getVegMenu();
    reception.getnonvegmenu();
    return 1;
}