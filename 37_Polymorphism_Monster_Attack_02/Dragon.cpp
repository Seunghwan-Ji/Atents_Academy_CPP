#include "Dragon.h"
#include "Ogre.h"
#include <iostream>

using namespace std;

Dragon::Dragon(string name, int health, int attack, int defense)
	: _name(name), _health(health), _attack(attack), _defense(defense) {
}

string Dragon::GetName() {
	return _name;
}

int Dragon::GetHealth() {
	return _health;
}

void Dragon::SetHealth(int value) {
	_health = value;
}

int Dragon::GetDefense() {
	return _defense;
}


void Dragon::Attack(Dragon& enemy) {
	int damage = _attack - enemy._defense;
	int enemyOldHealth = enemy._health;
	enemy._health -= damage;

	cout << _name << "가 " << enemy._name << "을 공격해서 생명력이 " << enemyOldHealth << "에서 " << enemy._health << "로 감소함" << endl;
}

void Dragon::Attack(Ogre& enemy) {
	int damage = _attack - enemy.GetDefense();
	int enemyOldHealth = enemy.GetHealth();

	if (damage < 0) {
		damage = 0;
	}

	int health = enemy.GetHealth() - damage;

	enemy.SetHealth(health);

	cout << _name << "가 " << enemy.GetName() << "을 공격해서 생명력이 " << enemyOldHealth << "에서 " << enemy.GetHealth() << "로 감소함" << endl;

}


void Dragon::Info() {
	cout << "이름: " << _name << endl;
	cout << "생명력: " << _health << endl;
	cout << "공격력: " << _attack << endl;
	cout << "방어력: " << _defense << endl;
}