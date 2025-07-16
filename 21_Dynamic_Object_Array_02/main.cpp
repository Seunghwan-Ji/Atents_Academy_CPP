#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Monster
{
private:
	string _name;
	int _health;
	int _attack;
	int _defense;

public:
	Monster()
	{
		cout << "Monster �⺻������" << endl;
		_name = "";
		_health = 0;
		_attack = 0;
		_defense = 0;
	}

	Monster(string name, int health, int attack, int defense)
		: _name(name)
		, _health(health)
		, _attack(attack)
		, _defense(defense)
	{
		cout << _name << "Monster ���ڸ� �޴� ������" << endl;
	}

	~Monster()
	{
		cout << _name << "�Ҹ���" << endl;
	}

	void Init(string name, int health, int attack, int defense) {
		_name = name;
		_health = health;
		_attack = attack;
		_defense = defense;
	}

	void Attack() {
		cout << _name << "�� �����Ѵ�." << endl;
	}

	void Defense() {
		cout << _name << "�� ����Ѵ�." << endl;
	}

	void Info() {
		cout << "���͸�: " << _name << endl;
		cout << "�����: " << _health << endl;
		cout << "���ݷ�: " << _attack << endl;
		cout << "����: " << _defense << endl << endl;
	}
};

int main()
{
	// ��ü �迭
	
	// ���� �迭 ����
	int count = 0;
	char buff[30];

	cout << "���� ������ �������� �Է��ϼ���: ";
	cin >> count;

	Monster** ppMonsterArray = new Monster*[count]; // ������ ������ �迭�� count ������ ��ŭ �Ҵ��Ѵ�.
	// ���� ppMonsterArray �� ������ Ÿ���� ���� �������� ����:
	// �� �迭�� ��ҵ��� ���� �����͵��̰�, ������ ���� �� ������ ���·� ����������
	// �� �迭�� ��� ������ ������ Ÿ���� ���� ������ Ÿ���̾�� �迭�� ���ι��� �ּҰ��� ������ ���� ��
	// ������ ���·� �������� �����̴�.

	for (int i = 0; i < count; i++)
	{
		sprintf(buff, "DynamicArray_%d", i);

		// ���ڸ� �޴� �����ڸ� ȣ���Ͽ� ���� ��ü ����
		ppMonsterArray[i] = new Monster(buff, i * 10, i * 3, i * 2);
	}

	cout << "���͵� Attack" << endl;
	for (int i = 0; i < count; i++)
	{
		ppMonsterArray[i]->Attack();
	}

	cout << "���͵� ���� ���" << endl;
	for (int i = 0; i < count; i++)
	{
		ppMonsterArray[i]->Info();
	}

	// ������ ������ü �ݳ�ó��
	for (int i = 0; i < count; i++)
	{
		delete ppMonsterArray[i];
	}

	// �����迭 �ݳ�ó��
	delete[] ppMonsterArray;

	return 0;
}