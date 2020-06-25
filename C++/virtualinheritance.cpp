// https://www.geeksforgeeks.org/simulating-final-class-in-c/
// This article will make finalclass non inheritable but you can instantiate it.
#include <iostream>
using namespace std;

class make_final{
	private:
		make_final(){
			cout << "makefinal constructoior" << endl;
		}
	friend class finalclass;
};

class finalclass:virtual make_final{
	public:
		finalclass(){
			cout << "finalclass constructoior" << endl;
		}
};
// If we uncomment below class, it will create compilation error.
// class derieved : public finalclass {
// 	public:
// 		derieved(){
// 			cout << "make derieved constructoior" << endl;
// 		}
// };
int main() {
	cout << "hello world" << endl;
}
