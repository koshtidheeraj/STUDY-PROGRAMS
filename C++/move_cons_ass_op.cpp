#include<utility>

class noConstruct{}NoConstruct;

class a
{
private:
    int *Array;
public:
    a();
    a(noConstruct);
    a(const a&);
    a& operator=(const a&);
    a(a&&);
    a& operator=(a&&);
    ~a();
};

a::a()
{
    Array=new int[5]{1,2,3,4,5};
}
a::a(noConstruct Parameter)
{
    Array=nullptr;
}
a::a(const a& Old): Array(Old.Array)
{

}
a& a::operator=(const a&Old)
{
    delete[] Array;
    Array=new int[5];
    for (int i=0;i!=5;i++)
    {
        Array[i]=Old.Array[i];
    }
    return *this;
}
a::a(a&&Old)
{
    Array=Old.Array;
    Old.Array=nullptr;
}
a& a::operator=(a&&Old)
{
    Array=Old.Array;
    Old.Array=nullptr;
    return *this;
}
a::~a()
{
    delete[] Array;
}

/*int main()
{
    a A(NoConstruct),B(NoConstruct),C;
    A=C;
    B=C;
}*/

// a RetByValue() {
//     a obj;
//     return obj; // Might call move ctor, or no ctor.
// }

int main() {
    a a1;
    a a2 = a1; // copy ctor
    a a3 = std::move(a1); // move ctor

    // a a4 = RetByValue(); // Might call move ctor, or no ctor.

    // a1 = RetByValue(); // Calls move assignment, a::operator=(a&&)
}
