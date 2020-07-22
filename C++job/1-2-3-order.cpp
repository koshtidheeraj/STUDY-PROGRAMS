#include <thread>
#include <future>
#include <iostream>
#include <unistd.h>

using namespace std;

std::promise<int> p1,p2,p3;

void return1() {
    std::future<int> f1 = p1.get_future();
    f1.get();
    cout << 1 << endl;
    p2.set_value(1);
}
void return2() {
    std::future<int> f2 = p2.get_future();
    f2.get();
    cout << 2 << endl;
    p3.set_value(1);
}
void return3() {
    std::future<int> f3 = p3.get_future();
    f3.get();
    cout << 3 << endl;
    p1.set_value(1);
}
int main() {
    std::async(return1);
    std::async(return2);
    std::async(return3);
    p1.set_value(1);
}