#include <iostream>
#include <string>

using namespace std;

class SoccerSon
{
private:
	string _name; // ���� �̸�
	int    _skillMove; // ���α�
	int    _goalFinishing; // �� ������
	int    _dribbleAbility; // �帮��
	int    _physical; // ���ο�
	int    _stamina; // ������
	int    _longShotPower; // �߰Ÿ� ��

public:
	SoccerSon()
		: _name("����")
		, _skillMove(0)
		, _goalFinishing(0)
		, _dribbleAbility(0)
		, _physical(0)
		, _stamina(0)
		, _longShotPower(0)
	{
		cout << "\n" << "SoccerSon �⺻������" << endl;
	}

	SoccerSon(string name, int skillMove, int goalFinishing, int dribbleAbility, int physical,
		int stamina, int longShotPower)
		: _name(name)
		, _skillMove(skillMove)
		, _goalFinishing(goalFinishing)
		, _dribbleAbility(dribbleAbility)
		, _physical(physical)
		, _stamina(stamina)
		, _longShotPower(longShotPower)
	{
		cout << "\n" << "SoccerSon �������� ���ڸ� �޴� ������" << endl;
	}

	SoccerSon(string name)
		: _name(name)
		, _skillMove(0)
		, _goalFinishing(0)
		, _dribbleAbility(0)
		, _physical(0)
		, _stamina(0)
		, _longShotPower(0)
	{
		cout << "\n" << "SoccerSon �� ���� ���ڸ� �޴� ������" << endl;
	}

	~SoccerSon() { cout << "\n" << "SoccerSon �Ҹ���" << endl; }

	void SetName(string name) { _name = name; }

	string GetName() { return _name; }

	void SetSkilMove(int skillMove) { _skillMove = skillMove; }

	int GetSkilMove() { return _skillMove; }

	void SetGoalFinishing(int goalFinishing) { _goalFinishing = goalFinishing; }

	int GetGoalFinishing() { return _goalFinishing; }

	void SetDribbleAbility(int dribbleAbility) { _dribbleAbility = dribbleAbility; }

	int GetDribbleAbility() { return _dribbleAbility; }

	void SetPhysical(int physical) { _physical = physical; }

	int GetPhysical() { return _physical; }

	void SetStamina(int stamina) { _stamina = stamina; }

	int GetStamina() { return _stamina; }

	void SetLongShotPower(int longShotPower) { _longShotPower = longShotPower; }

	int GetLongShotPower() { return _longShotPower; }

	void Info()
	{
		cout << "������: " << GetName() << endl;
		cout << "���α�: " << GetSkilMove() << endl;
		cout << "�� ������: " << GetGoalFinishing() << endl;
		cout << "�帮��: " << GetDribbleAbility() << endl;
		cout << "���ο�: " << GetPhysical() << endl;
		cout << "������: " << GetStamina() << endl;
		cout << "�߰Ÿ� ��: " << GetLongShotPower() << endl;
	}
};



int main()
{
	SoccerSon son;

	son.SetName("�����");
	son.SetSkilMove(90);
	son.SetGoalFinishing(95);
	son.SetDribbleAbility(92);
	son.SetPhysical(85);
	son.SetStamina(100);
	son.SetLongShotPower(100);

	son.Info();

	SoccerSon mbappe("������", 91, 94, 93, 84, 100, 100);
	mbappe.Info();

	SoccerSon player("Player01");
	player.Info();

	return 0;
}