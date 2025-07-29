#include "Ogre.h"
#include "Dragon.h"
#include <iostream>

using namespace std;


Ogre::Ogre(string name, int health, int attack, int defense)
	: _name(name), _health(health), _attack(attack), _defense(defense) {
}

string Ogre::GetName() {

	return _name;
}

void Ogre::SetHealth(int value) {
	_health = value;
}

int Ogre::GetHealth() {
	return _health;
}

int Ogre::GetDefense() {
	return _defense;
}

void Ogre::Attack(Ogre& enemy) {
	int damage = _attack - enemy._defense;
	int enemyOldHealth = enemy._health;

	if (damage < 0) {
		damage = 0;
	}
	enemy._health -= damage;

	cout << _name << "가 " << enemy._name << "을 공격해서 생명력이 " << enemyOldHealth << "에서 " << enemy._health << "로 감소함" << endl;
}

void Ogre::Attack(Dragon& enemy) {
	int damage = _attack - enemy.GetDefense();
	int enemyOldHealth = enemy.GetHealth();
	if (damage < 0) {
		damage = 0;
	}


	int health = enemy.GetHealth() - damage;

	enemy.SetHealth(health);

	cout << _name << "가 " << enemy.GetName() << "을 공격해서 생명력이 " << enemyOldHealth << "에서 " << enemy.GetHealth() << "로 감소함" << endl;

}

void Ogre::Info() {
	cout << "이름: " << _name << endl;
	cout << "생명력: " << _health << endl;
	cout << "공격력: " << _attack << endl;
	cout << "방어력: " << _defense << endl;
}