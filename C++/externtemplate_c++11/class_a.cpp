#include "template_header.h"
// Below line will not instantiate class template for extern_template_example<int>
// in class_a's translation unit.
// It reuses extern_template_example<int> instantiation from class_b. 
// run below command to execute files in this folder.
// g++ -std=c++11 class_a.cpp class_b.cpp 
extern template class extern_template_example<int>;
class class_a {
    public:
        void class_a_display() {
            extern_template_example<int> obj;
            obj.display();
        }
};
int main() {
    class_a aObj;
    aObj.class_a_display();
    return 1;
}