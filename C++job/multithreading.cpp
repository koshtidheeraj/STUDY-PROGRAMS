#include <iostream>
#include <thread>

using namespace std;

int main() {
    auto func = [](int i)->int{
        cout << "thred with value: " << i << endl;
        return i;
    };
    thread t(func,1);
    t.join();
}