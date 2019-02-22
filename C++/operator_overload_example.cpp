#include<iostream>
using namespace std;

class op_overload_ex {
    private:
        int i;
    public:
    op_overload_ex(int itemp) {
        i = itemp;
    }
    int operator + (int j) {
        return i + j;
    }
};

int main() {
    op_overload_ex one(1);
    cout << one + 2 << endl;
    return 1;
}