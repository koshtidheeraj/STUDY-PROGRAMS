// https://www.geeksforgeeks.org/the-decorator-pattern-set-2-introduction-and-design/
// https://refactoring.guru/design-patterns/decorator
#include <iostream>
using namespace std;

class food {
    public:
        food *base;
        int price;
        int getprice();
        food(int price, food *base = nullptr) : price(price), base(base) {}
};
class pizza : public food {
    public:
    pizza():food(10){}
};
class sauce : public food {
    public:
    sauce(food *base):food(20, base){}
};
class topping : public food {
    public:
    topping(food *base):food(30, base){}
};
class garnish : public food {
    public:
    garnish(food *base):food(40, base){}
}; 

int food::getprice()  {
    int basePrice = base->getprice();
    return (price + basePrice);
}

int main() {
    food *pizza = new pizza();
    food *sauce = new sauce(pizza);
    food *topping = new topping(sauce);
    food *garnish = new garnish(topping);

    cout << "price offinal product" << endl;
    cout << garnish->getprice() << endl;
    return 1;
}