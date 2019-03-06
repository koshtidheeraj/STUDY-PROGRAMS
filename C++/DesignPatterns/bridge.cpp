// https://refactoring.guru/design-patterns/bridge
// https://www.geeksforgeeks.org/bridge-design-pattern/

#include <iostream>
using namespace std;

class workshop;

class vehicle {
    public:
        workshop *repairWorkshop;
        workshop *cleaningWorkshop;
        vehicle(workshop* ptr1, workshop* ptr2):repairWorkshop(ptr1), cleaningWorkshop(ptr2) {}
        virtual void servicing () = 0;
};
class car : public vehicle {
    public:
        car(workshop* ptr1, workshop* ptr2):vehicle(ptr1, ptr2){}
        void servicing ();
};
class bike : public vehicle {
    public:
        bike(workshop* ptr1, workshop* ptr2):vehicle(ptr1, ptr2){}
        void servicing ();
};

class workshop {
    public:
        virtual void work() = 0;
};
class RepairWorkshop : public workshop {
    public:
        void work() {
            cout<<"repair in progress"<<endl;
        }
};
class CleaningWorkshop : public workshop {
    public:
        void work() {
            cout<<"Cleaning in progress"<<endl;
        }
};

void car::servicing() {
    cout<< "car servicing ";
    repairWorkshop->work();
    cleaningWorkshop->work();
}
void bike::servicing() {
    cout<< "bike servicing ";
    repairWorkshop->work();
    cleaningWorkshop->work();
}

int main() {
    workshop *repairShop = new RepairWorkshop();
    workshop *cleaningShop = new CleaningWorkshop();

    vehicle *veh1 = new car(repairShop, cleaningShop);
    vehicle *veh2 = new bike(repairShop, cleaningShop);

    veh1->servicing();
    veh2->servicing();
    return 1;
}