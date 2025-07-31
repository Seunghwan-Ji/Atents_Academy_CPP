#include "Slime.h"
#include <iostream>

using namespace std;

Slime::Slime(string name, int health, int attack, int defense, int physicalAttackRegist)
	: Monster(name, health, attack, defense)
	, _physicalAttackRegist(physicalAttackRegist)
{}

int Slime::GetPhysicalAttackRegist()
{
	return _physicalAttackRegist;
}

int Slime::Hit(int damage, Monster& enemy)
{
	damage -= _defense;

	if (damage < 0)
		damage = 0;

	_health -= damage;

	cout << _name << " 이(가) " << damage << " 만큼의 피해를 입음." << endl;

	return damage;
}

void Slime::Info()
{
	Monster::Info();
	cout << "물리공격저항력: " << _physicalAttackRegist << endl;
}