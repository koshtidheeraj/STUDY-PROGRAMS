#include <thread>
#include <condition_variable>
#include <mutex>
#include <iostream>

using namespace std;

mutex mux;
condition_variable c1,c2,c3;

void print1(){
    while(true) {
        unique_lock<mutex> lk(mux);
        c1.wait(lk);
        cout << "1" << endl;
        lk.unlock();
        c2.notify_one();
    }
}
void print2(){
    while(true) {
        unique_lock<mutex> lk(mux);
        c2.wait(lk);
        cout << "2" << endl;
        lk.unlock();
        c3.notify_one();
    }
}
void print3(){
    while(true) {
        unique_lock<mutex> lk(mux);
        c3.wait(lk);
        cout << "3" << endl;
        lk.unlock();
        c1.notify_one();
    }
}
int main() {
    std::thread t1(print1);
    std::thread t2(print2);
    std::thread t3(print3);
    c1.notify_one();
    t1.join();
    t2.join();
    t3.join();
}