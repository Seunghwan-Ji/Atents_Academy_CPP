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