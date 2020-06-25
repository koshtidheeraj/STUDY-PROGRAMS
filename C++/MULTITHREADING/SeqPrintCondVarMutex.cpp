#include <iostream> 
#include <thread>
#include <unistd.h>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex m;
condition_variable c1,c2,c3;
void printOne() {
    unique_lock<mutex> lk(m);
    cout << "One lock acquired" << endl;
    while (1) {
        sleep(2);
        cout << "1" << endl;
        c2.notify_one();
        cout << "c2 notified" << endl;
        c1.wait(lk);
        cout << "c1 wait complete" << endl;
    }
}
void printTwo() {
    unique_lock<mutex> lk(m);
    cout << "Two lock acquired" << endl;
    while (1) { 
        sleep(2);
        cout << "2" << endl;
        c3.notify_one();
        cout << "c3 notified" << endl;
        c2.wait(lk);
        cout << "c2 wait complete" << endl;
    }
}
void printThree() {
    unique_lock<mutex> lk(m);
    cout << "Three lock acquired" << endl;
    while (1) {
        sleep(2);
        cout << "3" << endl;
        c1.notify_one();
        cout << "c1 notified" << endl;
        c3.wait(lk);
        cout << "c3 wait complete" << endl;
    }
}
int main (){
    thread t1(printOne);
    thread t2(printTwo);
    thread t3(printThree);
    // c1.notify_one();
    t1.join();
    t2.join();
    t3.join();
    return 1;
}