#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Monster
{
private:
	string _name;
	int _health;
	int _attack;
	int _defense;

public:
	Monster()
	{
		cout << "Monster 기본생성자" << endl;
		_name = "";
		_health = 0;
		_attack = 0;
		_defense = 0;
	}

	Monster(string name, int health, int attack, int defense)
		: _name(name)
		, _health(health)
		, _attack(attack)
		, _defense(defense)
	{
		cout << _name << "Monster 인자를 받는 생성자" << endl;
	}

	~Monster()
	{
		cout << _name << "소멸자" << endl;
	}

	void Init(string name, int health, int attack, int defense) {
		_name = name;
		_health = health;
		_attack = attack;
		_defense = defense;
	}

	void Attack() {
		cout << _name << "이 공격한다." << endl;
	}

	void Defense() {
		cout << _name << "이 방어한다." << endl;
	}

	void Info() {
		cout << "몬스터명: " << _name << endl;
		cout << "생명력: " << _health << endl;
		cout << "공격력: " << _attack << endl;
		cout << "방어력: " << _defense << endl << endl;
	}
};

int main()
{
	// 객체 배열
	
	// 동적 배열 생성
	int count = 0;
	char buff[30];

	cout << "만들 몬스터의 마리수를 입력하세요: ";
	cin >> count;

	Monster** ppMonsterArray = new Monster*[count]; // 몬스터형 포인터 배열을 count 사이즈 만큼 할당한다.
	// 변수 ppMonsterArray 의 데이터 타입이 이중 포인터인 이유:
	// 이 배열의 요소들은 각각 포인터들이고, 역참조 했을 때 포인터 형태로 보여지려면
	// 이 배열을 담는 변수의 데이터 타입은 이중 포인터 타입이어야 배열의 선두번지 주소값을 역참조 했을 때
	// 포인터 형태로 보여지기 때문이다.

	for (int i = 0; i < count; i++)
	{
		sprintf(buff, "DynamicArray_%d", i);

		// 인자를 받는 생성자를 호출하여 동적 객체 생성
		ppMonsterArray[i] = new Monster(buff, i * 10, i * 3, i * 2);
	}

	cout << "몬스터들 Attack" << endl;
	for (int i = 0; i < count; i++)
	{
		ppMonsterArray[i]->Attack();
	}

	cout << "몬스터들 정보 출력" << endl;
	for (int i = 0; i < count; i++)
	{
		ppMonsterArray[i]->Info();
	}

	// 각각의 동적객체 반납처리
	for (int i = 0; i < count; i++)
	{
		delete ppMonsterArray[i];
	}

	// 동적배열 반납처리
	delete[] ppMonsterArray;

	return 0;
}