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
		: _name("")
		, _health(0)
		, _attack(0)
		, _defense(0)
	{
		cout << "기본 생성자" << endl;
	}

	Monster(string name, int health, int attack, int defense)
		: _name(name)
		, _health(health)
		, _attack(attack)
		, _defense(defense)
	{
		cout << "인자를 받는 생성자" << endl;
	}

	~Monster()
	{
		cout << _name << "소멸자" << endl;
	}

	void Init(string name, int health, int attack, int defense)
	{
		_name = name;
		_health = health;
		_attack = attack;
		_defense = defense;
	}

	void Attack()
	{
		cout << _name << "이 공격한다." << endl;
	}

	void Defense()
	{
		cout << _name << "이 방어한다." << endl;
	}

	void Info()
	{
		cout << "몬스터명: " << _name << endl;
		cout << "생명력: " << _health << endl;
		cout << "공격력: " << _attack << endl;
		cout << "방어력: " << _defense << endl << endl;
	}
};

// 객체 배열
int main()
{
	// 정적 객체 배열
	/*
	char buff[100];

	Monster array[10];

	for (int i = 0; i < 10; i++)
	{
		sprintf(buff, "Monster_%d", i);
		array[i].Init(buff, i * 20, i * 3, i * 2);
	}

	for (int i = 0; i < 10; i++)
	{
		array[i].Info();
	}
	*/

	// 동적 객체 배열 생성
	int count = 0;
	char buff[30];

	cout << "만들 몬스터의 마리수를 입력하세요: ";
	cin >> count;

	Monster* parray = new Monster[count]; // 동적객체 배열 생성 문법

	for (int i = 0; i < count; i++) {
		sprintf(buff, "DynamicMonster_%d", i);
		parray[i].Init(buff, i * 10, i * 4, i * 3);
	}

	for (int i = 0; i < count; i++) {
		parray[i].Attack();
	}

	cout << endl;

	for (int i = 0; i < count; i++) {
		parray[i].Info();
	}

	delete[] parray; // 동적객체 배열 반납처리 문법.

	return 0;
}