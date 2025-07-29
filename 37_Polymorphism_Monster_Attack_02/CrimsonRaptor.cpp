#include "CrimsonRaptor.h"
#include "Slime.h"
#include "Dragon.h"
#include "Ogre.h"
#include <string>
#include <iostream>

using namespace std;

CrimsonRaptor::CrimsonRaptor(std::string name, int health, int attack, int defense, int reproductionSentence)
	: _name(name)
	, _health(health)
	, _attack(attack)
	, _defense(defense)
	, _reproductionSentence(reproductionSentence)
{}

int CrimsonRaptor::Hit(int damage, CrimsonRaptor& enemy)
{
	damage -= _defense;

	if (damage < 0)
		damage = 0;

	_health -= damage;

	cout << _name << " 이(가) " << damage << " 만큼의 피해를 입음." << endl;

	if (_health == 0)
		RewardForKiller(enemy);

	return damage;
}

int CrimsonRaptor::Hit(int damage, Dragon& enemy)
{
	damage -= _defense;

	if (damage < 0)
		damage = 0;

	_health -= damage;

	cout << _name << " 이(가) " << damage << " 만큼의 피해를 입음." << endl;

	if (_health == 0)
		RewardForKiller(enemy);

	return damage;
}

int CrimsonRaptor::Hit(int damage, Ogre& enemy)
{
	damage -= _defense;

	if (damage < 0)
		damage = 0;

	_health -= damage;

	cout << _name << " 이(가) " << damage << " 만큼의 피해를 입음." << endl;

	if (_health == 0)
		RewardForKiller(enemy);

	return damage;
}

int CrimsonRaptor::Hit(int damage, Slime& enemy)
{
	damage -= _defense;

	if (damage < 0)
		damage = 0;

	_health -= damage;

	cout << _name << " 이(가) " << damage << " 만큼의 피해를 입음." << endl;

	if (_health == 0)
		RewardForKiller(enemy);

	return damage;
}

void CrimsonRaptor::Attack(CrimsonRaptor& enemy)
{
	cout << _name << " 이(가) " << enemy.GetName() << " 에게 " << _attack <<
		" 만큼의 데미지로 공격함." << endl;

	int damage = enemy.Hit(_attack, *this);

	BloodSucking(damage);
}

void CrimsonRaptor::Attack(Slime& enemy)
{
	int damage = _attack - enemy.GetDefense();
	int enemyOldHealth = enemy.GetHealth();

	if (damage < 0)
	{
		damage = 0;
	}

	int health = enemy.GetHealth() - damage;
	enemy.SetHealth(health);

	cout << _name << "가 " << enemy.GetName() << "을 공격해서 생명력이 " << enemyOldHealth << "에서 " << enemy.GetHealth() << "로 감소함" << endl;
	
	BloodSucking(damage);
}

void CrimsonRaptor::Attack(Dragon& enemy)
{
	int damage = _attack - enemy.GetDefense();
	int enemyOldHealth = enemy.GetHealth();

	if (damage < 0)
	{
		damage = 0;
	}

	int health = enemy.GetHealth() - damage;
	enemy.SetHealth(health);

	cout << _name << "가 " << enemy.GetName() << "을 공격해서 생명력이 " << enemyOldHealth << "에서 " << enemy.GetHealth() << "로 감소함" << endl;
	
	BloodSucking(damage);
}

void CrimsonRaptor::Attack(Ogre& enemy)
{
	int damage = _attack - enemy.GetDefense();
	int enemyOldHealth = enemy.GetHealth();

	if (damage < 0)
	{
		damage = 0;
	}

	int health = enemy.GetHealth() - damage;
	enemy.SetHealth(health);

	cout << _name << "가 " << enemy.GetName() << "을 공격해서 생명력이 " << enemyOldHealth << "에서 " << enemy.GetHealth() << "로 감소함" << endl;
	
	BloodSucking(damage);
}

void CrimsonRaptor::BloodSucking(int damage)
{
	int suckedBlood = (int)(damage * 0.1);
	if (suckedBlood == 0)
		suckedBlood = 1;

	_health += suckedBlood;
	cout << _name << " 이(가) 생명력을 +" << suckedBlood << " 흡수함. " << endl;
}

void CrimsonRaptor::RewardForKiller(CrimsonRaptor& enemy)
{
	enemy._health += _reproductionSentence;

	cout << enemy.GetName() << " 이(가) " << _name << " 을(를) 처치하고 보상을 획득함. '재생의 문장'" << endl;
	cout << "생명력 " << _reproductionSentence << " 증가." << endl;
}

void CrimsonRaptor::RewardForKiller(Slime& enemy)
{
	enemy.SetHealth(_reproductionSentence);

	cout << enemy.GetName() << " 이(가) " << _name << " 을(를) 처치하고 보상을 획득함. '재생의 문장'" << endl;
	cout << "생명력 " << _reproductionSentence << " 증가." << endl;
}

void CrimsonRaptor::RewardForKiller(Dragon& enemy)
{
	enemy.SetHealth(_reproductionSentence);

	cout << enemy.GetName() << " 이(가) " << _name << " 을(를) 처치하고 보상을 획득함. '재생의 문장'" << endl;
	cout << "생명력 " << _reproductionSentence << " 증가." << endl;
}

void CrimsonRaptor::RewardForKiller(Ogre& enemy)
{
	enemy.SetHealth(_reproductionSentence);

	cout << enemy.GetName() << " 이(가) " << _name << " 을(를) 처치하고 보상을 획득함. '재생의 문장'" << endl;
	cout << "생명력 " << _reproductionSentence << " 증가." << endl;
}

void CrimsonRaptor::Info()
{
	cout << "\n이름: " << _name << endl;
	cout << "생명력: " << _health << endl;
	cout << "공격력: " << _attack << endl;
	cout << "방어력: " << _defense << endl;
	cout << "처치 보상: 재생의 문장 (생명력 +" << _reproductionSentence << ")" << endl;
}