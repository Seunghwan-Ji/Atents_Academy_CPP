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

	cout << GetName() << " ��(��) " << damage << " ��ŭ�� ���ظ� ����." << endl;

	if (GetHealth() == 0)
		RewardForKiller(enemy);

	return damage;
}

void CrimsonRaptor::Attack(Monster& enemy)
{
	cout << GetName() << " ��(��) " << enemy.GetName() << " ���� " << GetAttack() <<
		" ��ŭ�� �������� ������." << endl;

	int damage = enemy.Hit(GetAttack(), *this);

	BloodSucking(damage);
}

void CrimsonRaptor::BloodSucking(int damage)
{
	int suckedBlood = (int)(damage * 0.1);
	if (suckedBlood == 0)
		suckedBlood = 1;

	SetHealth(GetHealth() + suckedBlood);
	
	cout << GetName() << " ��(��) ������� +" << suckedBlood << " �����. " << endl;
}

void CrimsonRaptor::RewardForKiller(Monster& enemy)
{
	enemy.SetHealth(enemy.GetHealth() + _reproductionSentence);

	cout << enemy.GetName() << " ��(��) " << GetName() << " ��(��) óġ�ϰ� ������ ȹ����. '����� ����'" << endl;
	cout << "����� " << _reproductionSentence << " ����." << endl;
}

void CrimsonRaptor::Info()
{
	Monster::Info();
	cout << "óġ ����: ����� ���� (����� +" << _reproductionSentence << ")" << endl;
}