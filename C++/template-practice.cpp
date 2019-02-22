#include<iostream>
using namespace std;

template <class T>
class template_practice {
    public:
    T a;
    template_practice(T atemp);
    void print_function();
    template<class U>
    void print_template_function(U btemp);
    // void print_template_function(U btemp) {
    //     cout << "fancy template template function" << endl;
    // }
};

template <class T>
template_practice<T>::template_practice(T atemp):a(atemp) {}

template <class T>
void template_practice<T>::print_function() {
    cout << a << endl;
}

template <class T>
template <class U>
void template_practice<T>::print_template_function(U btemp) {
    cout << "fancy template template function" << endl;
}

int main(){
    template_practice<int> aobj(2);
    aobj.print_function();
    aobj.print_template_function(3);
    return 1;
}