#include "Ogre.h"
#include <iostream>

using namespace std;

Ogre::Ogre(string name, int health, int attack, int defense)
	: Monster(name, health, attack, defense)
{}

int Ogre::Hit(int damage, Monster& enemy)
{
	damage -= _defense;

	if (damage < 0)
		damage = 0;

	_health -= damage;

	cout << _name << " ��(��) " << damage << " ��ŭ�� ���ظ� ����." << endl;

	return damage;
}