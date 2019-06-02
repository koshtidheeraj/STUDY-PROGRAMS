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
    shared_ptr<sample> sptr1(new sample()); 
    // unique_ptr<sample> uptr2 = uptr1; // this line will cause compile error
    cout << "count before " << sptr1.use_count() << endl;
    shared_ptr<sample> sptr2 = sptr1;
    cout << "count after " << sptr1.use_count() << endl;
    weak_ptr<sample> wptr1 = sptr2;
    // Below line indicates that weak pointer does not increases reference counter
    cout << "count after weak ptr" << sptr1.use_count() << endl;
    return 1;
}