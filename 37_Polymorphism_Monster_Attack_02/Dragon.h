#pragma once
#include <string>

class Ogre;

class Dragon {
private:
	std::string _name;
	int _health;	// 생명력
	int _attack;	// 공격력
	int _defense;	// 방어력

public:
	Dragon(std::string name, int health, int attack, int defense);

	std::string GetName();

	int GetHealth();

	void SetHealth(int value);

	int GetDefense();

	void Attack(Dragon& enemy);

	void Attack(Ogre& enemy);

	void Info();

};