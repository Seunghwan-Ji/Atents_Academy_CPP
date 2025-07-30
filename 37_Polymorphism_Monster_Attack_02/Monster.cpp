#include "Monster.h"
#include <iostream>

using namespace std;

Monster::Monster(string name, int health, int attack, int defense)
	: _name(name)
	, _health(health)
	, _attack(attack)
	, _defense(defense)
{}

int Monster::Hit(int damage, Monster& enemy)
{
	damage -= _defense;

	if (damage < 0)
		damage = 0;

	_health -= damage;

	cout << _name << " ��(��) " << damage << " ��ŭ�� ���ظ� ����." << endl;

	return damage;
}

void Monster::Attack(Monster& enemy)
{
	cout << _name << " ��(��) " << enemy.GetName() << " ���� " << _attack <<
		" ��ŭ�� �������� ������." << endl;

	enemy.Hit(_attack, *this);
}

void Monster::Info() {
	cout << "�̸�: " << _name << endl;
	cout << "�����: " << _health << endl;
	cout << "���ݷ�: " << _attack << endl;
	cout << "����: " << _defense << endl;
}