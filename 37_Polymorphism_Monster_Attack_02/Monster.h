#pragma once
#include <string>

// 순수 가상함수를 하나라도 가지고 있는 클래스를 추상클래스(abstract class)
// 추상클래스는 자신의 객체를 생성하는 능력이 상실이 됩니다.
// 자신에게서 상속된 자식클래스가 자신의 순수가상함수를 구현하도록 강제하는 능력이 생깁니다.

class Monster
{
protected:
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

	virtual int Hit(int damage, Monster& enemy) = 0; // 순수 가상함수 (구현부가 없는 멤버함수)
													 // 또는 abstract 키워드를 붙임.

	virtual void Attack(Monster& enemy);

	void Info();
};