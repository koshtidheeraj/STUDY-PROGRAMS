#include <iostream>
using namespace std;
int* get_number() {
	int i = 3;
	return &i;
}

void get_number_2(int param) {
param = 4;
}

int main() {
//int* num = get_number(); 
//cout << *num;
int param;
get_number_2(param);
cout<<param;
}
