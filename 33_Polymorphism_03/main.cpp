#include <iostream>

using namespace std;

// Fake.
// Drink Ŭ������ ��� ������� ���� ���Ѵ�.

class Drink {
private:
    string _name;

public:
    Drink()
        : _name("����") {
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
        : _name("Ŀ��") {
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
        : _name("��") {
    }
};


class Cola : public Drink {
private:
    string _name;

public:
    Cola()
        : _name("�ݶ�") {
    }
};

class Cidar : public Drink {
private:
    string _name;

public:
    Cidar()
        : _name("���̴�") {
    }
};

class Americano : public Drink {
private:
    string _name;

public:
    Americano()
        : _name("�Ƹ޸�ī��") {
    }
};

class Barista {
public:
    void MakeADrink(Drink& drink) {
        cout << drink.GetName() << "�� ����ϴ�." << endl;
    }
};

class Cashier {
private:
    Barista& _refBari;   // ����(agreggation)

public:
    Cashier(Barista& ref)
        : _refBari(ref) {
    }

    void OrderedDrink(Drink& drink) {
        cout << drink.GetName() << " �ֹ��� �޽��ϴ�." << endl;

        _refBari.MakeADrink(drink);
    }
};

class Guest {
public:
    void OrderingDrink(Cashier& ref, Drink& drink) {   // ����������, �Ͻ�������
        cout << drink.GetName() << "�� �ֹ��մϴ�." << endl;
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