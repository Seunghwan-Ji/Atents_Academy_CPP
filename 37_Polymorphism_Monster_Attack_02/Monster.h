#pragma once
#include <string>

class Monster
{
private:
	std::string _name;
	int _health;	// 생명력
	int _attack;	// 공격력
	int _defense;	// 방어력

public:
	Monster(std::string name, int health, int attack, int defense);

	std::string GetName() { return _name; }

	int GetHealth() { return _health; }

	void SetHealth(int value) { _health = value; }

	int GetAttack() { return _attack; }

	int GetDefense() { return _defense; }

	virtual int Hit(int damage, Monster& enemy);

	virtual void Attack(Monster& enemy);

	void Info();
};