
#include <iostream>
using namespace std;

class finalclass{
	private:
		finalclass(){
			cout << "finalclass constructoior" << endl;
		}
    public:
        static finalclass* get_instance() {
            return new finalclass();
        }
        void printclassname() {
            cout << "printing class name" <<endl;
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
    finalclass* ptr = finalclass::get_instance();
	cout << "hello world" << endl;
    ptr->printclassname();
}
