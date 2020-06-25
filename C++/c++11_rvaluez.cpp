// for header inclusion, preprocessor searches files directory then system directories in 
// case of  ""  and in case of <> it only searches in system directries.
// So for system libraries use "" and user defined header files use <>
#include <iostream>
#include <vector>
using namespace std;
int objcount = 0;
class rvalue {
    public:
    int count;
        rvalue() {
            count = objcount++;
            cout << "default cons" << endl;
        }
        rvalue(const rvalue & a) {
            count = objcount++;
            cout << "copy cons" << endl;
        }
        rvalue(rvalue && a) {
            count = objcount++;
            cout << "move cons" << endl;
        }  
        ~rvalue() {
            cout << "destructor " << count << endl;
        }
};
int main() {
    vector<rvalue> v1 ;
    rvalue r1;
    v1.push_back(std::move(r1));
    cout << r1.count << endl;
    rvalue r2 = v1.front();
    cout << r2.count;
    return 1;
}

// std::unique_ptr<int> p1 {new int{0}};
// std::unique_ptr<int> p2 = p1; // error -- cannot copy unique pointers
// std::unique_ptr<int> p3 = std::move(p1); // move `p1` into `p3`
//                                          // now unsafe to dereference object held by `p1`