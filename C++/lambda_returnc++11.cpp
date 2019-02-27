#include <iostream>
#include <functional>
using namespace std;

class base {
    public:
    // below function returns lambda function
    std::function<int(int)> returnlambda () {
        return [](int a)->int {
            cout << "value a inside lambda function before increment= " << a << endl;
            return ++a;
            };
    }
};

int main() {
    base obj;
    auto lambdafunction = obj.returnlambda();
    cout << lambdafunction(3) << endl;
    return 1;
}

// Below comment is just for information.
// void test() noexcept;
// This declares that test() won't be able to throw. If the exception is not dealt with
// locally inside test() — and when test() method throws — the program will get terminated,
// calling std:: terminate() method that by default calls the std:: abort().