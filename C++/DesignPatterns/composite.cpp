// https://www.geeksforgeeks.org/composite-design-pattern/
// https://refactoring.guru/design-patterns/composite

// execute some action accross tree irrespective node being accessed is subtree or leaf.

#include <iostream>
#include <vector>
using namespace std;

class employee {
    public:
        virtual void getEmpDetails() = 0;
        virtual void addEmployee(employee *emp) = 0;
};
class Dev : public employee {
    public:
        void getEmpDetails() {
            cout << "I am DEVEOPER" << endl;
        }
        void addEmployee(employee *emp) {}

};
class QA : public employee {
    public:
        void getEmpDetails() {
            cout << "I am QA" << endl;
        }
        void addEmployee(employee *emp) {}
};
class team : public employee {
    vector<employee*> employees;
    public:
        void getEmpDetails() {
            cout << "It is team" << endl;
            for (employee *emp : employees) {
                emp->getEmpDetails();
            }
        }
        void addEmployee(employee *emp) {
            employees.push_back(emp);
        }
};
int main() {
    employee *emp2 = new team();
    emp2->addEmployee(new Dev());
    emp2->addEmployee(new Dev());

    employee *emp1 = new team();
    emp1->addEmployee(new QA());
    emp1->addEmployee(new Dev());
    emp1->addEmployee(emp2);

    emp1->getEmpDetails();
    return 1;
}