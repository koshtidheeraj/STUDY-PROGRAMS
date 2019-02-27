// thread example
#include <iostream> 
#include <thread>
#include <future>
using namespace std;

int factory(int i) { return i * 10; }
int main() 
{
    int a = 0b110; // binary initialization in c++14
    cout << "binary value=" << a << endl;

    // In c++14 you can add auto as return type and paramter list type ion lambda also.
    auto lambdaFunc = [](auto a)->auto {cout << "lambdafunction" <<endl;return a;};
    cout << "value from lambda function=" << lambdaFunc(5) << endl;

    // Below is another type of lambda capture list.
    auto f = [x = factory(2)] { return x; }; // returns 20

    //  Because it is now possible to move (or forward) values into a lambda that could
    // previously be only captured by copy or reference we can now capture move-only types
    // in a lambda by value. Note that in the below example the p in the capture-list of
    // task2 on the left-hand-side of = is a new variable private to the lambda body and
    // does not refer to the original p.
    auto p = std::make_unique<int>(1);
    // auto task1 = [=] { *p = 5; }; // ERROR: std::unique_ptr cannot be copied
    auto task2 = [p1 = std::move(p)] { *p1 = 5; }; // OK: p is move-constructed into the closure object
    // the original p is empty after task2 is created
    cout << "unique pointervalue before task2 call = " << *p << endl;
    task2();
    // cout << "unique pointervalue after task2 call = " << *p << endl; // This call causes
    // segmentation fault because in task2 lambda function.

    return 1;
}

// decltype(auto) :
// The decltype(auto) type-specifier also deduces a type like auto does. However, it deduces return types while keeping their references and cv-qualifiers, while auto will not.

// const int x = 0;
// auto x1 = x; // int
// decltype(auto) x2 = x; // const int
// int y = 0;
// int& y1 = y;
// auto y2 = y1; // int
// decltype(auto) y3 = y1; // int&
// int&& z = 0;
// auto z1 = std::move(z); // int
// decltype(auto) z2 = std::move(z); // int&&
// // Note: Especially useful for generic code!

// // Return type is `int`.
// auto f(const int& i) {
//  return i;
// }

// // Return type is `const int&`.
// decltype(auto) g(const int& i) {
//  return i;
// }




// Relaxing constraints on constexpr functions
// In C++11, constexpr function bodies could only contain a very limited set of syntaxes, including (but not limited to): typedefs, usings, and a single return statement. In C++14, the set of allowable syntaxes expands greatly to include the most common syntax such as if statements, multiple returns, loops, etc.

// constexpr int factorial(int n) {
//   if (n <= 1) {
//     return 1;
//   } else {
//     return n * factorial(n - 1);
//   }
// }
// factorial(5); // == 120