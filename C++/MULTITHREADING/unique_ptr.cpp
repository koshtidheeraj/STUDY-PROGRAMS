#include <iostream>
#include <memory>
using namespace std;
class sample {
public:
    sample() {
        cout << "constructor" << endl;
    }
    ~sample() {
        cout << "destructor" << endl;
    }
};
int main() {
    unique_ptr<sample> uptr1(new sample()); 
    // unique_ptr<sample> uptr2 = uptr1; // this line will cause compile error
    unique_ptr<sample> uptr2 = move(uptr1); // wew can transfer ownership using
    // move semantics
    return 1;
}