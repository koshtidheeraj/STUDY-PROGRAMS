#include <iostream>
#include <vector>
using namespace std;
class init_list_constructor {
    public:
        init_list_constructor(std::initializer_list<int> list) {
        for (int i : list) {
            cout << "value=" << i << endl;
        }
    }
};
int main() {
    init_list_constructor obj = {1,2,3,4};
    return 1;
}