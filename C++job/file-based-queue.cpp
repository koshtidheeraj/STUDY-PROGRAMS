#include <iostream>
#include <fstream>

using namespace std;

class queue_interface {
public:
    virtual void push(int i) = 0;
    virtual int pop() = 0;
};
class file_queue{
public:
    ofstream write;
    ifstream read;
    file_queue() {
        // create file to store data
        string path("queue.dat"); 
        write.open(path.c_str(), ios::out | ios::trunc | ios::app | ios::binary);
        read.open(path.c_str(), ios::in | ios::binary);
    }
    ~file_queue() {
        write.close();
        read.close();
    }
    void push(int i) {
        write.write((char*)&i, sizeof(int));
    }
    int pop() {
        int value;
        read.read((char*)&value, sizeof(int));
        return value;
    }    
};
int main() {
    file_queue queue;
    queue.push(10);
    queue.push(2);
    queue.push(543);
    queue.push(12345);
    cout << queue.pop() << endl;
    cout << queue.pop() << endl;
    cout << queue.pop() << endl;
    cout << queue.pop() << endl;
    return 0;
}