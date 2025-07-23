#include <iostream>

using namespace std;

// 커피숖 관리 프로그램 개발의뢰를 받았습니다.
// 커피숖에 갑니다. 커피를 한잔을 시키고 자리에 앉아서
// 커피숖의 업무 흐름을 파악해야합니다.
// 커피숖에는 어떤 역할(role)과 어떤 책임(responsibility)이 있는 파악하셔야 합니다.

// 커피숖에는 어떤 역할이 있나요?
// 손님 캐시어 바리스타
// guest cashier barista

class Coffee {
private:
	string _name;

public:
	Coffee()
		: _name("커피") {}

	string GetName() {
		return _name;
	}
};

class Latte {
private:
	string _name;

public:
	Latte()
		: _name("라떼") {}

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
		cout << drink.GetName() << "를 만듭니다." << endl;
	}

	void MakeADrink(Latte& drink) {
		cout << drink.GetName() << "를 만듭니다." << endl;
	}

	void MakeADrink(Smoothie& drink) {
		cout << drink.GetName() << "를 만듭니다." << endl;
	}
};

class Cashier {
private:
	Barista& _refBari;	// 참조(agreggation)

public:
	Cashier(Barista& ref)
		: _refBari(ref) {}

	void OrderedDrink(Coffee& drink) {
		cout << drink.GetName() << " 주문을 받습니다." << endl;

		_refBari.MakeADrink(drink);
	}

	void OrderedDrink(Latte& drink) {
		cout << drink.GetName() << " 주문을 받습니다." << endl;
		_refBari.MakeADrink(drink);
	}

	void OrderedDrink(Smoothie& drink) {
		cout << drink.GetName() << " 주문을 받습니다." << endl;
		_refBari.MakeADrink(drink);
	}
};

class Guest {
public:
	void OrderingDrink(Cashier& ref, Coffee& drink) {	// 의존적관계, 일시적관계
		cout << drink.GetName() << "를 주문합니다." << endl;
		ref.OrderedDrink(drink);
	}

	void OrderingDrink(Cashier& ref, Latte& drink) {
		cout << drink.GetName() << "을 주문합니다." << endl;
		ref.OrderedDrink(drink);
	}

	void OrderingDrink(Cashier& ref, Smoothie& drink) {
		cout << drink.GetName() << "을 주문합니다." << endl;
		ref.OrderedDrink(drink);
	}
};


int main() {
	Coffee coffee;
	Latte latte;
	Smoothie melonSmoothie("멜론 스무디");

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