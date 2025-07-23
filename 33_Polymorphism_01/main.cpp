#include <iostream>

using namespace std;

// Ŀ�Ǚ� ���� ���α׷� �����Ƿڸ� �޾ҽ��ϴ�.
// Ŀ�Ǚ��� ���ϴ�. Ŀ�Ǹ� ������ ��Ű�� �ڸ��� �ɾƼ�
// Ŀ�Ǚ��� ���� �帧�� �ľ��ؾ��մϴ�.
// Ŀ�Ǚ����� � ����(role)�� � å��(responsibility)�� �ִ� �ľ��ϼž� �մϴ�.

// Ŀ�Ǚ����� � ������ �ֳ���?
// �մ� ĳ�þ� �ٸ���Ÿ
// guest cashier barista

class Coffee {
private:
	string _name;

public:
	Coffee()
		: _name("Ŀ��") {}

	string GetName() {
		return _name;
	}
};

class Latte {
private:
	string _name;

public:
	Latte()
		: _name("��") {}

	string GetName() {
		return _name;
	}
};

class Smoothie
{
private:
	string _name;

public:
	Smoothie(string name)
		: _name(name)
	{}

	string GetName() { return _name; }
};

class Barista {
public:
	void MakeADrink(Coffee& drink) {
		cout << drink.GetName() << "�� ����ϴ�." << endl;
	}

	void MakeADrink(Latte& drink) {
		cout << drink.GetName() << "�� ����ϴ�." << endl;
	}

	void MakeADrink(Smoothie& drink) {
		cout << drink.GetName() << "�� ����ϴ�." << endl;
	}
};

class Cashier {
private:
	Barista& _refBari;	// ����(agreggation)

public:
	Cashier(Barista& ref)
		: _refBari(ref) {}

	void OrderedDrink(Coffee& drink) {
		cout << drink.GetName() << " �ֹ��� �޽��ϴ�." << endl;

		_refBari.MakeADrink(drink);
	}

	void OrderedDrink(Latte& drink) {
		cout << drink.GetName() << " �ֹ��� �޽��ϴ�." << endl;
		_refBari.MakeADrink(drink);
	}

	void OrderedDrink(Smoothie& drink) {
		cout << drink.GetName() << " �ֹ��� �޽��ϴ�." << endl;
		_refBari.MakeADrink(drink);
	}
};

class Guest {
public:
	void OrderingDrink(Cashier& ref, Coffee& drink) {	// ����������, �Ͻ�������
		cout << drink.GetName() << "�� �ֹ��մϴ�." << endl;
		ref.OrderedDrink(drink);
	}

	void OrderingDrink(Cashier& ref, Latte& drink) {
		cout << drink.GetName() << "�� �ֹ��մϴ�." << endl;
		ref.OrderedDrink(drink);
	}

	void OrderingDrink(Cashier& ref, Smoothie& drink) {
		cout << drink.GetName() << "�� �ֹ��մϴ�." << endl;
		ref.OrderedDrink(drink);
	}
};


int main() {
	Coffee coffee;
	Latte latte;
	Smoothie melonSmoothie("��� ������");

	Barista bari;
	Cashier cashier(bari);
	Guest guest;

	guest.OrderingDrink(cashier, coffee);
	cout << endl;
	guest.OrderingDrink(cashier, latte);
	
	cout << endl;
	guest.OrderingDrink(cashier, melonSmoothie);

	return 0;
}