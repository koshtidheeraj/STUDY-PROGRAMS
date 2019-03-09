// https://www.geeksforgeeks.org/prototype-design-pattern/
// https://refactoring.guru/design-patterns/prototype


// Here we create prototype of class which will have clone method. 
// Clone method will return copy of itself.

#include <iostream>
using namespace std;

class rectangle {
    public:
    int width, bredth;
    rectangle(int a,int b) : width(a), bredth(b){}
    rectangle(rectangle* rect){
        width = rect->width;
        bredth = rect->bredth;
    }
    rectangle* clone() {
        return new rectangle(this);
    }
}
int main() {
    rectangle rect(2,3);
    rectangle rect_cloned = rect.clone();
    return 1;
}