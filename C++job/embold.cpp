#include <map>
#include <iostream>
#include <cstring>

// Q1
// int main() {
//   std::map<bool,int> zomb = {{11,22},{33,44},{55,0}};
//   std::cout << zomb.size();
//   std::map<int,int> zomi = {{11,22},{33,44},{55,0}};
//   std::cout << zomi.size();
//   return 0;
// }

// Q2
static void
my_malloc_wrapper(unsigned char* c, size_t n_bytes) {
    c = (unsigned char*) malloc(n_bytes);
}


int main() {
    unsigned char *c;
    my_malloc_wrapper(c, 1024);
    memcpy(c, "data", 4);
    return 0;
}