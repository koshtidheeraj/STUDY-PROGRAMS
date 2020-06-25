#include <iostream>

using namespace std;

template <int n>
class fact {
    public:
        enum {
            val = n*(fact<n-1>::val)
        };
};
template<>
class fact<1> {
    public:
        enum {
            val = 1
        };
}; 
int main() {
    cout << fact<4>::val << endl;
    return 1;
}