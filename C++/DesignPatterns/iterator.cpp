// https://refactoring.guru/design-patterns/iterator
#include <iostream>
using namespace std;

class iteratorbase {
    public:
        int* arrayPtr;
        int index;
        int size;
        iteratorbase(int* ptr, int index, int size) :
        arrayPtr(ptr), index (index), size(size) {}
        virtual bool hasNext() = 0;
        virtual int getNext() = 0;
};

class ConcreteIteratorLeftRight : public iteratorbase {
    public:
    ConcreteIteratorLeftRight(int* ptr, int index, int size): iteratorbase (ptr,index,size){}
    bool hasNext() {
        if (index < size) {
            return true;
        }

        return false;
    }
    int getNext() {
        return arrayPtr[index++];
    }
};

class ConcreteIteratorRightLeft : public iteratorbase {
    public:
    ConcreteIteratorRightLeft(int* ptr, int index, int size): iteratorbase (ptr,index,size){}
    bool hasNext() {
        if (index >= 0) {
            return true;
        }
        return false;
    }
    int getNext() {
        return arrayPtr[index--];
    }
};

class iterableContainer {
    public:
        virtual iteratorbase* getLeftRightIt() = 0;
        virtual iteratorbase* getRightLeftIt() = 0;
};

class concreteContainerInt :public iterableContainer {
    public:
    int container[5] = {0,1,2,3,4};
    iteratorbase* getLeftRightIt() {
        return new ConcreteIteratorLeftRight(&container[0],0,5);
    }
    iteratorbase* getRightLeftIt() {
        return new ConcreteIteratorRightLeft(&container[0],5,0);
    }
};

int main() {
    concreteContainerInt intContainer;
    iteratorbase* it =  intContainer.getLeftRightIt();
    cout << "left to right value" << endl;
    while(it->hasNext()){
        cout << it->getNext() <<endl;
    }
    
    it =  intContainer.getRightLeftIt();
    cout << "right to left value" << endl;
    while(it->hasNext()){
        cout << it->getNext() <<endl;
    }
    return 1;
}