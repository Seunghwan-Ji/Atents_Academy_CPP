#include <iostream>

using namespace std;

// Fake.
// Drink 클래스는 사실 음료들을 알지 못한다.

class Drink {
private:
    string _name;

public:
    Drink()
        : _name("음료") {
    }

    string GetName() {
        return _name;
    }
};

class Coffee : public Drink {
private:
    string _name;

public:
    Coffee()
        : _name("커피") {
    }

    string GetName() {
        return _name;
    }
};

class Latte : public Drink {
private:
    string _name;
public:
    Latte()
        : _name("라떼") {
    }
};


class Cola : public Drink {
private:
    string _name;

public:
    Cola()
        : _name("콜라") {
    }
};

class Cidar : public Drink {
private:
    string _name;

public:
    Cidar()
        : _name("사이다") {
    }
};

class Americano : public Drink {
private:
    string _name;

public:
    Americano()
        : _name("아메리카노") {
    }
};

class Barista {
public:
    void MakeADrink(Drink& drink) {
        cout << drink.GetName() << "를 만듭니다." << endl;
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
    Coffee coffee;
    Latte latte;
    Cola cola;
    Cidar cidar;
    Americano americano;

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


    return 0;
}