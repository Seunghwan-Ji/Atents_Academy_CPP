#pragma once
#include <string>

class Dragon;
class Ogre;

class Slime
{
private:
	std::string _name;
	int _health;
	int _attack;
	int _defense;
	int _physicalAttackRegist;	// 물리 공격저항력

public:
	Slime(std::string name, int health, int attack, int defense, int physicalAttackRegist);

	int GetHealth();
	void SetHealth(int value);

	int GetDefense();
	int GetPhysicalAttackRegist();

	std::string GetName();

	void Attack(Slime& enemy);
	void Attack(Dragon& enemy);
	void Attack(Ogre& enemy);

	void Info();

};

