#include "Dragon.h"
#include <iostream>

using namespace std;

Dragon::Dragon(string name, int health, int attack, int defense)
	: Monster(name, health, attack, defense)
{}

int Dragon::Hit(int damage, Monster& enemy)
{
	damage -= _defense;

	if (damage < 0)
		damage = 0;

	_health -= damage;

	cout << _name << " ��(��) " << damage << " ��ŭ�� ���ظ� ����." << endl;

	return damage;
}