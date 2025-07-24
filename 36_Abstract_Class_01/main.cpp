#include <iostream>

using namespace std;

// 순수가상함수를 하나라도 가지고 있는 클래스를 추상클래스라고 합니다.
// 추상클래스는 자신의 객체를 만드는 능력은 상실이 됩니다.
// 자신의 자식이 자신의 순수가상함수를 반드시 구현하도록 강제하는 능력이 생깁니다.

class Drink {
private:
    string _name;


public:
    Drink()
        : _name("음료") {
    }

    virtual string GetName() {
        return _name;
    }

    virtual void MakeADrink() abstract; // 순수가상함수
};

class Coffee : public Drink {
private:
    string _name;

public:
    Coffee()
        : _name("커피") {
    }

    string GetName() override {
        return _name;
    }

    void MakeADrink() override {
        cout << _name << "을 만듭니다." << endl;
    }
};

class Latte : public Drink {
private:
    string _name;
public:
    Latte()
        : _name("라떼") {
    }

    string GetName() override {
        return _name;
    }

    void MakeADrink() override {
        cout << _name << "을 만듭니다." << endl;
    }
};


class Cola : public Drink {
private:
    string _name;

public:
    Cola()
        : _name("콜라") {
    }

    string GetName() override {
        return _name;
    }

    void MakeADrink() override {
        cout << _name << "을 만듭니다." << endl;
    }
};

class Cidar : public Drink {
private:
    string _name;

public:
    Cidar()
        : _name("사이다") {
    }

    string GetName() override {
        return _name;
    }

    void MakeADrink() override {
        cout << _name << "을 만듭니다." << endl;
    }
};

class Americano : public Drink {
private:
    string _name;

public:
    Americano()
        : _name("아메리카노") {
    }

    string GetName() override {
        return _name;
    }

    void MakeADrink() override {
        cout << _name << "을 만듭니다." << endl;
    }
};

class Tea : public Drink {
private:
    string _name;

public:
    Tea()
        : _name("차") {
    }

    string GetName() override {
        return _name;
    }

};



class Barista {
public:
    void MakeADrink(Drink& drink) {
        drink.MakeADrink();
    }
};

class Cashier {
private:
    Barista& _refBari;   // 참조(agreggation)

public:
    Cashier(Barista& ref)
        : _refBari(ref) {
    }

    void OrderedDrink(Drink& drink) {
        cout << drink.GetName() << " 주문을 받습니다." << endl;

        _refBari.MakeADrink(drink);
    }
};

class Guest {
public:
    void OrderingDrink(Cashier& ref, Drink& drink) {   // 의존적관계, 일시적관계
        cout << drink.GetName() << "를 주문합니다." << endl;
        ref.OrderedDrink(drink);
    }
};


int main() {
    //Drink drink;

    Coffee coffee;
    Latte latte;
    Cola cola;
    Cidar cidar;
    Americano americano;
    Tea tea;

    Barista bari;
    Cashier cashier(bari);
    Guest guest;

    guest.OrderingDrink(cashier, coffee);
    cout << endl;
    guest.OrderingDrink(cashier, latte);
    cout << endl;
    guest.OrderingDrink(cashier, cola);
    cout << endl;
    guest.OrderingDrink(cashier, cidar);
    cout << endl;
    guest.OrderingDrink(cashier, americano);
    cout << endl;
    guest.OrderingDrink(cashier, tea);


    return 0;
}