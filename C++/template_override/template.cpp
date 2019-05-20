#include <iostream>
using namespace std;

class sample {
    public:
        template <typename type>
        void print(type t) {
            cout <<"generic called"<< endl;
        }
};

template<> void sample::print(int t){
            cout <<"specialization called"<< endl;
}

int main () {
    sample obj;
    obj.print(2);
    obj.print(1.1);
}
