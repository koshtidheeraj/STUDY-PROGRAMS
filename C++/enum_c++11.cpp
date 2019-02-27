#include <iostream>
using namespace std;

class base {
    public:
        enum class color { red, green};
        enum class signal { red, green};

        // Below enums will give conflicts among same enum names e.g. red in c++98.
        // enum color { red, green};
        // enum signal { red, green};
};
int main() {
    
    return 1;
}