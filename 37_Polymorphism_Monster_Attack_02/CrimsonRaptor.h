#pragma once
#include <string>

class Dragon;
class Ogre;
class Slime;

class CrimsonRaptor
{
private:
	std::string _name;
	int _health;
	int _attack;
	int _defense;
	int _reproductionSentence; // 이 몬스터를 죽인 객체에게 보상으로 생명력을 줌.

public:
	CrimsonRaptor(std::string name, int health, int attack, int defense, int reproductionSentence);

	int GetHealth() { return _health; }

	int Hit(int damage, Slime& enemy);
	int Hit(int damage, Dragon& enemy);
	int Hit(int damage, Ogre& enemy);
	int Hit(int damage, CrimsonRaptor& enemy);

	int GetDefense() { return _defense; }
	std::string GetName() { return _name; }

	void Attack(Slime& enemy);
	void Attack(Dragon& enemy);
	void Attack(Ogre& enemy);
	void Attack(CrimsonRaptor& enemy);

	void BloodSucking(int damage);

	void RewardForKiller(Slime& enemy);
	void RewardForKiller(Dragon& enemy);
	void RewardForKiller(Ogre& enemy);
	void RewardForKiller(CrimsonRaptor& enemy);

	void Info();
};

