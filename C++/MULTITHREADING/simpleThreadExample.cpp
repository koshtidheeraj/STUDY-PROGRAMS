#include <iostream> 
#include <thread>
#include <unistd.h>
using namespace std;
void printNumber(int i) {
    cout << i << endl;
}

int main (){
    for (int index = 1; index <= 50; index++) {
        std::thread t1(printNumber, index);
        t1.join();
    }
    return 1;
}