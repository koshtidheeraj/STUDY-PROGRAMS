#include <iostream>

int main() {

    const int i = 25;
    // int *a = &i; // This will not compile as we are assigning pointer to const to non const pointer
    const int *a = &i; // this cimpiles

    int *a = (int *)&i;
    // *a = 26; // commpile error "assignment of read-only locatio"
    return 1;
}