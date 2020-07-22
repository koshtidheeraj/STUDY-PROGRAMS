#include <iostream>
#include <typeinfo>
#include <bits/stdc++.h>
#include <cxxabi.h>
#include <string>
#include <memory>
#include <cstdlib> 

std::string demangle(const char* mangled)
{
      int status;
      std::unique_ptr<char[], void (*)(void*)> result(
        abi::__cxa_demangle(mangled, 0, 0, &status), std::free);
      return result.get() ? std::string(result.get()) : "error occurred";
}

int main() {
    char* constptr = "dheeraj";
    std::cout << demangle(typeid(constptr).name()) << std::endl;
    // char* nonconstptr = constptr;

    // int a = 10;
    // const int* constintptr = &a;
    // int* nonconstintptr = constintptr;
    // // ptr[2] ='a';
    // std::cout << *nonconstintptr << std::endl;
    return 1;
}