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

void Slime::Info()
{
	Monster::Info();
	cout << "물리공격저항력: " << _physicalAttackRegist << endl;
}