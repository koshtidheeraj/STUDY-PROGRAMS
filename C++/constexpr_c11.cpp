#include <iostream>
#include <vector>
using namespace std;

class constexpr_cpp {
    public:
        constexpr int return2() {
            return 2;
        }
};
int main() {
   constexpr_cpp obj;
   int array[obj.return2()]; 

   constexpr double caseselect = 2.2;
   switch (caseselect)
   {
       case 2.2:
           cout << "value is 2.2" << endl;
           break;
   
       default:
           break;
   }
   return 1;
}