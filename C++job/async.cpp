#include <thread>
#include <future>
#include <iostream>

int simplefunc(std::string a)
{ 
    return a.size();
}

int main()
{
      auto future = std::async(simplefunc, "hello world");
      int simple = future.get();
      std::cout << simple << std::endl;

      auto simplefunc2 = [](std::string a) ->int{
          return a.size();
      };
      auto future2 = std::async(simplefunc2, "hello world2");
      int simple2 = future2.get();
      std::cout << simple2 << std::endl;

      return 0;
}