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
	// 객체가 생성될때 자동으로 호출되어지는 멤버함수가 있습니다.
	// 객체가 생성될때 무조건 호출됩니다.
	// 이 멤버함수가 호출되어야지만 온전한 객체로 생성됩니다.
	// 이 멤버함수를 생성자(constructor)라고 합니다
	// 
	// 생성자는 반드시 필요합니다.
	// 생성자를 만들지 않으면 컴파일러 자동으로 기본 생성자를 만들어서
	// 넣어줍니다.
	// 기본 생성자는 인자를 받지 않는 생성자입니다.
	// 생성자는 멤버변수의 초기화나 객체를 만들때 선행되어야 하는 작업들을 생성자에서 처리합니다.
	// * 별도의 생성자를 만들면 컴파일러는 기본 생성자를 만들어주지 않는다.
	//   객체를 초기 속성값을 부여해 생성해야만 하는 의도가 있을 수 있기 때문이다.
	SoccerSon()
	{   // 기본생성자
		cout << "\n" << "SoccerSon 기본생성자" << endl;
		_name = "없음";
		_skillMove = 0;
		_goalFinishing = 0;
		_dribbleAbility = 0;
		_physical = 0;
		_stamina = 0;
		_longShotPower = 0;
	}

	SoccerSon(string name, int skillMove, int goalFinishing, int dribbleAbility, int physical,
		int stamina, int longShotPower)
	{
		cout << "\n" << "SoccerSon 여러개의 인자를 받는 생성자" << endl;
		_name = name;
		_skillMove = skillMove;
		_goalFinishing = goalFinishing;
		_dribbleAbility = dribbleAbility;
		_physical = physical;
		_stamina = stamina;
		_longShotPower = longShotPower;
	}

	SoccerSon(string name)
	{
		cout << "\n" << "SoccerSon 한 개의 인자만 받는 생성자" << endl;
		_name = name;
		_skillMove = 0;
		_goalFinishing = 0;
		_dribbleAbility = 0;
		_physical = 0;
		_stamina = 0;
		_longShotPower = 0;
	}

	// 객체가 소멸될때 호출되어지는 멤버함수
    // 소멸자라고 합니다.
    // 소멸자 객체가 소멸되지 전에 선행되어야 하는 작업을 소멸자에서 합니다.
	~SoccerSon() { cout << "\n" << "SoccerSon 소멸자" << endl; }

	void SetName(string name) { _name = name; }

	string GetName() { return _name; }

	void SetSkilMove(int skillMove) { _skillMove = skillMove; }

	int GetSkilMove() { return _skillMove; }

	void SetGoalFinishing(int goalFinishing) {	_goalFinishing = goalFinishing; }

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



int main() {
	// 손흥민을 축구게임에서 필요한 데이타를 뽑으시고
	// 캡슐화해서 클래스형 데이타 타입을 만들고
	// 객체를 만들고 값을 저장한 후에 
	// 객체에 저장된 값을 출력해보세요..

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