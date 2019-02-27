// thread example
#include <iostream> 
#include <thread>
#include <future>
using namespace std;
 
void foo(int a) 
{
  cout << "thread executed value = " << a << endl;
}

int main() 
{
  std::async(std::launch::async,foo,2);
  cout << "main completed" << endl;
return 0;
}

// use below command to compile and run the program.
// g++ -std=c++11 -pthread threadAsyncC++11.cpp ; ./a.out