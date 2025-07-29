#include "Slime.h"
#include "Dragon.h"
#include "Ogre.h"
#include <string>
#include <iostream>

using namespace std;


Slime::Slime(string name, int health, int attack, int defense, int physicalAttackRegist)
	: _name(name), _health(health), _attack(attack), _defense(defense), _physicalAttackRegist(physicalAttackRegist) {
}

string Slime::GetName() {

	return _name;
}

void Slime::SetHealth(int value) {
	_health = value;
}

int Slime::GetHealth() {
	return _health;
}

int Slime::GetDefense() {
	return _defense;
}

int Slime::GetPhysicalAttackRegist() {
	return _physicalAttackRegist;
}

void Slime::Attack(Slime& enemy) {
	int damage = _attack - enemy._defense - enemy.GetPhysicalAttackRegist();
	int enemyOldHealth = enemy._health;

	if (damage < 0) {
		damage = 0;
	}
	enemy._health -= damage;

	cout << _name << "가 " << enemy._name << "을 공격해서 생명력이 " << enemyOldHealth << "에서 " << enemy._health << "로 감소함" << endl;
}

void Slime::Attack(Dragon& enemy) {
	int damage = _attack - enemy.GetDefense();
	int enemyOldHealth = enemy.GetHealth();
	if (damage < 0) {
		damage = 0;
	}


	int health = enemy.GetHealth() - damage;

	enemy.SetHealth(health);

	cout << _name << "가 " << enemy.GetName() << "을 공격해서 생명력이 " << enemyOldHealth << "에서 " << enemy.GetHealth() << "로 감소함" << endl;

}

void Slime::Attack(Ogre& enemy) {
	int damage = _attack - enemy.GetDefense();
	int enemyOldHealth = enemy.GetHealth();
	if (damage < 0) {
		damage = 0;
	}


	int health = enemy.GetHealth() - damage;

	enemy.SetHealth(health);

	cout << _name << "가 " << enemy.GetName() << "을 공격해서 생명력이 " << enemyOldHealth << "에서 " << enemy.GetHealth() << "로 감소함" << endl;

}


void Slime::Info() {
	cout << "이름: " << _name << endl;
	cout << "생명력: " << _health << endl;
	cout << "공격력: " << _attack << endl;
	cout << "방어력: " << _defense << endl;
	cout << "물리공격저항력: " << _physicalAttackRegist << endl;
}