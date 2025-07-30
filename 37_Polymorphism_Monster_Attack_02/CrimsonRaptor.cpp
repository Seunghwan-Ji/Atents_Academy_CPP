#include "CrimsonRaptor.h"
#include <iostream>

using namespace std;

CrimsonRaptor::CrimsonRaptor(std::string name, int health, int attack, int defense, int reproductionSentence)
	: Monster(name, health, attack, defense)
	, _reproductionSentence(reproductionSentence)
{}

int CrimsonRaptor::Hit(int damage, Monster& enemy)
{
	damage -= GetDefense();

	if (damage < 0)
		damage = 0;

	SetHealth(GetHealth() - damage);

	cout << GetName() << " 이(가) " << damage << " 만큼의 피해를 입음." << endl;

	if (GetHealth() == 0)
		RewardForKiller(enemy);

	return damage;
}

void CrimsonRaptor::Attack(Monster& enemy)
{
	cout << GetName() << " 이(가) " << enemy.GetName() << " 에게 " << GetAttack() <<
		" 만큼의 데미지로 공격함." << endl;

	int damage = enemy.Hit(GetAttack(), *this);

	BloodSucking(damage);
}

void CrimsonRaptor::BloodSucking(int damage)
{
	int suckedBlood = (int)(damage * 0.1);
	if (suckedBlood == 0)
		suckedBlood = 1;

	SetHealth(GetHealth() + suckedBlood);
	
	cout << GetName() << " 이(가) 생명력을 +" << suckedBlood << " 흡수함. " << endl;
}

void CrimsonRaptor::RewardForKiller(Monster& enemy)
{
	enemy.SetHealth(enemy.GetHealth() + _reproductionSentence);

	cout << enemy.GetName() << " 이(가) " << GetName() << " 을(를) 처치하고 보상을 획득함. '재생의 문장'" << endl;
	cout << "생명력 " << _reproductionSentence << " 증가." << endl;
}

void CrimsonRaptor::Info()
{
	Monster::Info();
	cout << "처치 보상: 재생의 문장 (생명력 +" << _reproductionSentence << ")" << endl;
}