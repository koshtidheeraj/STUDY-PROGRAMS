// thread example
#include <iostream> 
#include <thread>
 
void foo() 
{
  // do stuff...
}

void bar(int x)
{
  // do stuff...
}

int main() 
{
  std::thread first (foo);     // spawn new thread that calls foo()
  std::thread second (bar,0);  // spawn new thread that calls bar(0)

  std::cout << "main, foo and bar now execute concurrently...\n";

  // synchronize threads:
  first.join();                // pauses until first finishes
  second.join();               // pauses until second finishes

  std::cout << "foo and bar completed.\n";

  return 0;
}

// use below command to compile and run the program.
// g++ -std=c++11 -pthread Threadc++11.cpp

// FYI
// std::chrono
// The chrono library contains a set of utility functions and types that deal with durations,
// clocks, and time points

// Tuples are a fixed-size collection of heterogeneous values. Access the elements of a std::tuple by unpacking using std::tie, or using std::get.
// // `playerProfile` has type `std::tuple<int, const char*, const char*>`.
// auto playerProfile = std::make_tuple(51, "Frans Nielsen", "NYI");
// std::get<0>(playerProfile); // 51
// std::get<1>(playerProfile); // "Frans Nielsen"
// std::get<2>(playerProfile); // "NYI"
