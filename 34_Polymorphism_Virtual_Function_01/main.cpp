#include <iostream>

using namespace std;

// 개선 방법 3.
// 부모 클래스에서 가상함수로 정의, 자식 클래스에서 부모의 가상함수를 오버라이딩.
// 자식쪽 오버라이딩 함수에서 override 키워드는 붙이지 않아도 오버라이딩 함수로 인식한다.
// 다만 붙이는 이유는, override 키워드를 붙인 상태에서 함수 이름에 오타가 발생하면
// 컴파일러가 이를 알려주는 장점이 있다.

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

    virtual void MakeADrink() { // 일반 멤버함수 -> 가상함수
        cout << _name << "을 만듭니다." << endl;
    }
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

    void MakeADrink() override {
        cout << _name << "을 만듭니다." << endl;
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

        _refBari.MakeADrink(소주);
    }
};

class Guest {
public:
    void OrderingDrink(Cashier& ref, Drink& drink) {   // 의존적관계, 일시적관계
        cout << drink.GetName() << "를 주문합니다." << endl;
        ref.OrderedDrink(소주);
    }
};


int main() {
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