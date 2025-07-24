#include <iostream>

using namespace std;

// 개선 방법 2.
// 음료는 Drink 클래스가 알게하자.

enum DrinkKind {
    COFFEE,
    LATTE,
    COLA,
    CIDAR,
    AMERICANO
};

class Drink {
private:
    string _name;
    DrinkKind _type;

public:
    Drink(DrinkKind type)
        : _name("음료"), _type(type) {
    }

    string GetName() {
        return _name;
    }

    DrinkKind GetType() {
        return _type;
    }

    void MakeADrink() {
        cout << _name << "을 만듭니다." << endl;
    }
};

class Coffee : public Drink {
private:
    string _name;

public:
    Coffee()
        : Drink(COFFEE), _name("커피") {
    }

    string GetName() {
        return _name;
    }

    void MakeADrink() {
        cout << _name << "을 만듭니다." << endl;
    }
};

class Latte : public Drink {
private:
    string _name;
public:
    Latte()
        : Drink(LATTE), _name("라떼") {
    }

    string GetName() {
        return _name;
    }

    void MakeADrink() {
        cout << _name << "을 만듭니다." << endl;
    }
};


class Cola : public Drink {
private:
    string _name;

public:
    Cola()
        : Drink(COLA), _name("콜라") {
    }

    string GetName() {
        return _name;
    }

    void MakeADrink() {
        cout << _name << "을 만듭니다." << endl;
    }
};

class Cidar : public Drink {
private:
    string _name;

public:
    Cidar()
        : Drink(CIDAR), _name("사이다") {
    }

    string GetName() {
        return _name;
    }

    void MakeADrink() {
        cout << _name << "을 만듭니다." << endl;
    }
};

class Americano : public Drink {
private:
    string _name;

public:
    Americano()
        : Drink(AMERICANO), _name("아메리카노") {
    }

    string GetName() {
        return _name;
    }

    void MakeADrink() {
        cout << _name << "을 만듭니다." << endl;
    }
};

class Barista {
public:
    void MakeADrink(Drink& drink) {
        switch (drink.GetType()) {
        case COFFEE:
            ((Coffee&)drink).MakeADrink();
            break;

        case LATTE:
            ((Latte&)drink).MakeADrink();
            break;

        case COLA:
            ((Cola&)drink).MakeADrink();

            break;

        case CIDAR:
            ((Cidar&)drink).MakeADrink();
            break;

        case AMERICANO:

            ((Americano&)drink).MakeADrink();
            break;
        }
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