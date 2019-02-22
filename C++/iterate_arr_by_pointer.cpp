#include <iostream>
using namespace std;
void arraysize_function(int arr[]) {
    // int size = *(&arr + 1) - arr;
    // cout << size << endl;
    cout << sizeof(arr) << endl;
}
int main() {
    int arr[]= {1,2,3,4,5,6};
    arraysize_function(arr);
    cout << sizeof(arr)/ sizeof(int) << endl;
    return 1;
}