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

	cout << _name << " ��(��) " << damage << " ��ŭ�� ���ظ� ����." << endl;

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

	cout << _name << " ��(��) " << damage << " ��ŭ�� ���ظ� ����." << endl;

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

	cout << _name << " ��(��) " << damage << " ��ŭ�� ���ظ� ����." << endl;

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

	cout << _name << " ��(��) " << damage << " ��ŭ�� ���ظ� ����." << endl;

	if (_health == 0)
		RewardForKiller(enemy);

	return damage;
}

void CrimsonRaptor::Attack(CrimsonRaptor& enemy)
{
	cout << _name << " ��(��) " << enemy.GetName() << " ���� " << _attack <<
		" ��ŭ�� �������� ������." << endl;

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

	cout << _name << "�� " << enemy.GetName() << "�� �����ؼ� ������� " << enemyOldHealth << "���� " << enemy.GetHealth() << "�� ������" << endl;
	
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

	cout << _name << "�� " << enemy.GetName() << "�� �����ؼ� ������� " << enemyOldHealth << "���� " << enemy.GetHealth() << "�� ������" << endl;
	
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

	cout << _name << "�� " << enemy.GetName() << "�� �����ؼ� ������� " << enemyOldHealth << "���� " << enemy.GetHealth() << "�� ������" << endl;
	
	BloodSucking(damage);
}

void CrimsonRaptor::BloodSucking(int damage)
{
	int suckedBlood = (int)(damage * 0.1);
	if (suckedBlood == 0)
		suckedBlood = 1;

	_health += suckedBlood;
	cout << _name << " ��(��) ������� +" << suckedBlood << " �����. " << endl;
}

void CrimsonRaptor::RewardForKiller(CrimsonRaptor& enemy)
{
	enemy._health += _reproductionSentence;

	cout << enemy.GetName() << " ��(��) " << _name << " ��(��) óġ�ϰ� ������ ȹ����. '����� ����'" << endl;
	cout << "����� " << _reproductionSentence << " ����." << endl;
}

void CrimsonRaptor::RewardForKiller(Slime& enemy)
{
	enemy.SetHealth(_reproductionSentence);

	cout << enemy.GetName() << " ��(��) " << _name << " ��(��) óġ�ϰ� ������ ȹ����. '����� ����'" << endl;
	cout << "����� " << _reproductionSentence << " ����." << endl;
}

void CrimsonRaptor::RewardForKiller(Dragon& enemy)
{
	enemy.SetHealth(_reproductionSentence);

	cout << enemy.GetName() << " ��(��) " << _name << " ��(��) óġ�ϰ� ������ ȹ����. '����� ����'" << endl;
	cout << "����� " << _reproductionSentence << " ����." << endl;
}

void CrimsonRaptor::RewardForKiller(Ogre& enemy)
{
	enemy.SetHealth(_reproductionSentence);

	cout << enemy.GetName() << " ��(��) " << _name << " ��(��) óġ�ϰ� ������ ȹ����. '����� ����'" << endl;
	cout << "����� " << _reproductionSentence << " ����." << endl;
}

void CrimsonRaptor::Info()
{
	cout << "\n�̸�: " << _name << endl;
	cout << "�����: " << _health << endl;
	cout << "���ݷ�: " << _attack << endl;
	cout << "����: " << _defense << endl;
	cout << "óġ ����: ����� ���� (����� +" << _reproductionSentence << ")" << endl;
}