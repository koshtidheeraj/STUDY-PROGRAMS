#include <iostream> 
#include <thread>
#include <unistd.h>

using namespace std;

void printNumber(int index) {
    sleep(2);
    cout << index << endl;
    index++;
    if (index > 3) {
        index = 1;
    }
    std::thread t(printNumber, index);
    t.join();
}
int main (){
    int index = 1;
    std::thread t(printNumber, index);
    t.join();
    return 1;
}