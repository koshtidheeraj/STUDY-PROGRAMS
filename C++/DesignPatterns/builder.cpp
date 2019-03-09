https://www.geeksforgeeks.org/builder-design-pattern/
https://refactoring.guru/design-patterns/builder

#include <iostream>
#include <vector>
using namespace std;

class houseplan {
    public:
        char* base;
        char* roof;
        virtual void setBase(char *base) = 0;
        virtual void setRoof(char *roof) = 0;
};
class house : public houseplan {
    public:
    void setBase(char *base) {
        this->base = base;
    }
    void setRoof(char *roof) {
        this->base - base;
    }
};

class builder {
    public:
        house *hs;
        virtual void buildBase()=0;
        virtual void buildRoof()=0;
        house* getHouse() {
            return hs;
        }
};
class Igloobuilder : public builder {
    public:
    Igloobuilder() {
        hs = new house();
    }
    void buildBase(){
        hs->setBase("ice base created");
    }
    void buildRoof() {
        hs->setRoof("ice roof created");
    }
    
};

class engineer {
    public:
    builder *bldr;
    engineer(builder *bldr):bldr(bldr){}
    void constructHouse() {
        bldr->buildBase();
        bldr->buildRoof();
    }
    house* getHouse() {
        return bldr->getHouse();
    }
};
int main() {
    engineer civilengineer(new Igloobuilder());
    house *hs = civilengineer.getHouse();
    return 1;
}