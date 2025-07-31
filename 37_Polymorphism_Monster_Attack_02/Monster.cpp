#include "Monster.h"
#include <iostream>

using namespace std;

Monster::Monster(string name, int health, int attack, int defense)
	: _name(name)
	, _health(health)
	, _attack(attack)
	, _defense(defense)
{}

void Monster::Attack(Monster& enemy)
{
	cout << _name << " 이(가) " << enemy.GetName() << " 에게 " << _attack <<
		" 만큼의 데미지로 공격함." << endl;

	enemy.Hit(_attack, *this);
}

void Monster::Info() {
	cout << "이름: " << _name << endl;
	cout << "생명력: " << _health << endl;
	cout << "공격력: " << _attack << endl;
	cout << "방어력: " << _defense << endl;
}