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
    v1.push_back(r1);
    return 1;
}