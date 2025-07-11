#include <iostream>
#include <string>

using namespace std;

class SoccerSon
{
private:
	string _name; // 선수 이름
	int    _skillMove; // 개인기
	int    _goalFinishing; // 골 결정력
	int    _dribbleAbility; // 드리블
	int    _physical; // 몸싸움
	int    _stamina; // 지구력
	int    _longShotPower; // 중거리 슛

public:
	SoccerSon()
		: _name("없음")
		, _skillMove(0)
		, _goalFinishing(0)
		, _dribbleAbility(0)
		, _physical(0)
		, _stamina(0)
		, _longShotPower(0)
	{
		cout << "\n" << "SoccerSon 기본생성자" << endl;
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
		cout << "\n" << "SoccerSon 여러개의 인자를 받는 생성자" << endl;
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
		cout << "\n" << "SoccerSon 한 개의 인자만 받는 생성자" << endl;
	}

	~SoccerSon() { cout << "\n" << "SoccerSon 소멸자" << endl; }

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
		cout << "선수명: " << GetName() << endl;
		cout << "개인기: " << GetSkilMove() << endl;
		cout << "골 결정력: " << GetGoalFinishing() << endl;
		cout << "드리블: " << GetDribbleAbility() << endl;
		cout << "몸싸움: " << GetPhysical() << endl;
		cout << "지구력: " << GetStamina() << endl;
		cout << "중거리 슛: " << GetLongShotPower() << endl;
	}
};



int main()
{
	SoccerSon son;

	son.SetName("손흥민");
	son.SetSkilMove(90);
	son.SetGoalFinishing(95);
	son.SetDribbleAbility(92);
	son.SetPhysical(85);
	son.SetStamina(100);
	son.SetLongShotPower(100);

	son.Info();

	SoccerSon mbappe("음바페", 91, 94, 93, 84, 100, 100);
	mbappe.Info();

	SoccerSon player("Player01");
	player.Info();

	return 0;
}