// https://www.geeksforgeeks.org/mutex-vs-semaphore/
#include <thread>
#include <mutex>
#include <iostream>
#include <unistd.h>

using namespace std;
std::mutex mux;
void print (int i) {
    // mux.lock();
    sleep(2);
    cout << i << endl;
    // mux.unlock();
}
int main() {
    int i = 0;
    std::thread t1(print,++i);
    t1.join();
    std::thread t2(print,++i);
    t2.join();
    return 1;
}