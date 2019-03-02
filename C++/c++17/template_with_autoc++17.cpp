// Example for c++17 library features.

#include <variant>
#include <iostream>
#include <string>
#include <optional>
#include <any>
using namespace std;

std::optional<std::string> create(bool b) {
    if (b) {
      return "Godzilla";
    } else {
      return {};
    }
}

int main()
{
//   The class template std::variant represents a type-safe union. An instance of std::variant at any 
//   given time holds a value of one of its alternative types (it's also possible for it to be valueless).
  std::variant<int,double> v {2};
  cout << "int value =" << std::get<0>(v)<< endl;
  v=12.0;
  cout << "double value =" << std::get<1>(v)<< endl;
  
  cout << "true value=" << create(true).value() << endl;
  cout << "false value=" << create(false).value_or("empty") << endl;

  any a = 1;
  cout << a.type().name() << any_cast<int>(a) << endl;
}