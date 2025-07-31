#pragma once
#include <string>

// ���� �����Լ��� �ϳ��� ������ �ִ� Ŭ������ �߻�Ŭ����(abstract class)
// �߻�Ŭ������ �ڽ��� ��ü�� �����ϴ� �ɷ��� ����� �˴ϴ�.
// �ڽſ��Լ� ��ӵ� �ڽ�Ŭ������ �ڽ��� ���������Լ��� �����ϵ��� �����ϴ� �ɷ��� ����ϴ�.

class Monster
{
protected:
	std::string _name;
	int _health;	// �����
	int _attack;	// ���ݷ�
	int _defense;	// ����

public:
	Monster(std::string name, int health, int attack, int defense);

	std::string GetName() { return _name; }

	int GetHealth() { return _health; }

	void SetHealth(int value) { _health = value; }

	int GetAttack() { return _attack; }

	int GetDefense() { return _defense; }

	virtual int Hit(int damage, Monster& enemy) = 0; // ���� �����Լ� (�����ΰ� ���� ����Լ�)
													 // �Ǵ� abstract Ű���带 ����.

	virtual void Attack(Monster& enemy);

	void Info();
};