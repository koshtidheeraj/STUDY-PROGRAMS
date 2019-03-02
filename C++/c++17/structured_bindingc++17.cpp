// A proposal for de-structuring initialization, that would allow writing
// auto [ x, y, z ] = expr; where the type of expr was a tuple-like object,
// whose elements would be bound to the variables x, y, and z (which this construct
// declares). Tuple-like objects include std::tuple, std::pair, std::array,
// and aggregate structures.
#include <iostream>
#include <array>
using namespace std;

class abc {
    public:
    array<int,3> a = {1,2,3};
    auto returnThreeVals() {
         return a;
    }
};

int main() {
    abc obj;
    auto [a,b,c] = obj.returnThreeVals();
    cout << "a= " << a << " b= "<< b << " c= " << c << endl;
    return 1;
}