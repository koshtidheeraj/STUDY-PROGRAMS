#include <iostream>
using namespace std;

class abc {
    public:
     int val{5};
     auto getLLambdaByValue() {
        return [*this]{return val;}; // Here 'this' is passed by value, mean object pointer by 'this'
         // is passed to local context. So even if val is changed before lambda's
         // execution, we will get val = 5 which is passed when this lambda was returned.
         // This will be evident is main program
     }
     auto getLambdaByRef() {
        return [this] {return val;};
        // Here 'this' is passed by reference, so if val is changed before lambda's
        // execution, we will get changed value.
        // This will be evident is main program
     }
};
 int main() {
     abc obj;
     auto func1 = obj.getLLambdaByValue();
     auto func2 = obj.getLambdaByRef();
     obj.val = 6;
     cout << "lambda by value = " << func1() << endl;
     cout << "lambda by ref = " << func2() << endl;
    return 0;
 }

// FYI 
// if constexpr evaluates constexpr expression at compile time and then discards
// the code in one of the branches.