#include <iostream>

using namespace std;

// 커피숖 관리 프로그램 개발의뢰를 받았습니다.
// 커피숖에 갑니다. 커피를 한잔을 시키고 자리에 앉아서
// 커피숖의 업무 흐름을 파악해야합니다.
// 커피숖에는 어떤 역활(role)과 어떤 책임(responsibility)이 있는 파악하셔야 합니다.

// 커피숖에는 어떤 역활이 있나요?
// 손님 캐시어 바리스타
// guest cashier barista

class Drink {
private:
    string _name;

public:
    Drink(string name)
        : _name(name) {
    }

    string GetName() {
        return _name;
    }
};

class Coffee : public Drink {
public:
    Coffee()
        : Drink("커피") {
    }
};

class Latte : public Drink {
public:
    Latte()
        : Drink("라떼") {
    }
};


class Cola : public Drink {
public:
    Cola()
        : Drink("콜라") {
    }
};

class Cidar : public Drink {
public:
    Cidar()
        : Drink("사이다") {
    }
};

class Americano : public Drink {
public:
    Americano()
        : Drink("아메리카노") {
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