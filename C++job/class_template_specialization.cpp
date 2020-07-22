#include <iostream>

template<class T>
class template_class
{
private:
    T a;
public:
    void print_tem_type() {
        std::cout << "template class " << std::endl;
    }
};

template<>
class template_class<int>
{
private:
    int a;
public:
    void print_tem_type() {
        std::cout << "int specialize class " << std::endl;
    }
};

//  If we enable below code we get erro that
// class_template_specialization.cpp:3:10: error: template parameter ‘class T’
//  template<class T>
//           ^~~~~
// class_template_specialization.cpp:26:7: error: redeclared here as ‘int n’
//  class template_class
//        ^~~~~~~~~~~~~~
// template<int n>
// class template_class
// {
// private:
//     int a;
// public:
//     void print_tem_type() {
//         std::cout << "concrete int specialize class " << std::endl;
//     }
// };

int main() {
    template_class<char> tem1;
    tem1.print_tem_type();

    template_class<int> tem2;
    tem2.print_tem_type();

    return 1;
}