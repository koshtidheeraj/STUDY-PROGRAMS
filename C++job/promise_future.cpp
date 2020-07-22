#include <iostream>
#include <thread>
#include <future>

using namespace std;

int main() {
    auto func = [](promise<int> & p){
        p.set_value(1);
    };
    promise<int> p;
    auto f = p.get_future();
    thread t(func, p);
    t.join();
    int ret_val = f.get();
    cout << "returned valu is: " << ret_val << endl;
    return 0;
}