#pragma once
#include <string>
#include "Monster.h"

class CrimsonRaptor : public Monster
{
private:
	int _reproductionSentence; // 이 몬스터를 죽인 객체에게 보상으로 생명력을 줌.

public:
	CrimsonRaptor(std::string name, int health, int attack, int defense, int reproductionSentence);
	
	int Hit(int damage, Monster& enemy) override;

	void Attack(Monster& enemy) override;

	void BloodSucking(int damage);

	void RewardForKiller(Monster& enemy);

	void Info();
};

