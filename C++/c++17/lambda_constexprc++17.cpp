#include <iostream>
using namespace std;
int main() {
    constexpr auto lambdafunc = [] (int a, int b) {
        auto L = [=]{return a;}; // Here [=] give access to a,b, by value
        auto R = [=]{return b;}; // Here [=] give access to a,b, by value
        return [=] {return L() + R();};
    };
    cout << "lambda constexpr value = " << lambdafunc(2,3)()<< endl;
    return 1;
}