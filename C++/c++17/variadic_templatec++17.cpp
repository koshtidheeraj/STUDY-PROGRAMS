// variable argument template call example
// thread example
#include <iostream> 
#include <thread>
#include <future>
#include <typeinfo>

using namespace std;

template <typename T = int>
class abc {
    T a;
    public:
        abc():a(){}
        abc(T val):a(val){}
        void display () {cout<<"value type= "<<a<<endl;}
};

void foo() 
{
  cout << "last call" << endl;
}

template <typename T, typename... Types> 
void foo(T a, Types... args) 
{
  cout << "template concrete value = " << a << endl;
  foo(args...);
}

int main()
{
  foo(1,2,3,4,5);
  abc obj1(1.5); // abc template for T float
  abc obj2; // abc template for T int
  obj1.display();
  obj2.display();
  return 0;
}

// Commented code above is for testing "Template argument deduction for class templates"
// from https://github.com/AnthonyCalandra/modern-cpp-features/blob/master/CPP17.md
// but due to compiler non support issues I could not test it. 