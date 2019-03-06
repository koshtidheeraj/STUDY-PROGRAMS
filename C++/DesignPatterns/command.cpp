// https://refactoring.guru/design-patterns/command
#include <iostream>
#include <string>
using namespace std;

class command {
    public:
    int val1, val2;
    command(int val1, int val2): val1(val1), val2(val2) {} 
    virtual void execute() = 0;
};
class multiplyCommand : public command {
    public:
    multiplyCommand(int val1, int val2) : command(val1, val2){}
    void execute() {
        cout << "multiplication output is: " << ( val1 * val2) << endl;
    }
};
class sumCommand : public command {
    public:
    sumCommand(int val1, int val2) : command(val1, val2){}
    void execute() {
        cout << "summation output is: " <<  (val1 + val2) << endl;
    }
};
int main() {
    command *cmd1 = new multiplyCommand(1,2);
    command *cmd2 = new sumCommand(3,4);
    cout <<"cmd1 output= " << endl;
    cmd1->execute();
    cout <<"cmd2 output= " << endl;
    cmd2->execute();
    return 1;
}