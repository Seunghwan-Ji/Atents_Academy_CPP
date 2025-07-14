#include <iostream>
#include <string>

using namespace std;

// 실습
// 집에 있는 전자제품 3종류의 클래스를 각각 만들고
// 각 클래스 타입의 객체 생성한 후에 객체에 값을 저장하고 
// 객체의 값을 출력해보세요.

class Television {
private:
    float _elecPower;
    string _specialAttack;

public:
    Television(float elecPower, string specialAttack)
        : _elecPower(elecPower), _specialAttack(specialAttack) {
    }

    void Attack() {
        float oldElecPower = _elecPower;
        _elecPower -= 10;
        cout << _specialAttack << "으로 공격하여 elecPower가 " << oldElecPower << " 에서 " << _elecPower << "로 줄어듦." << endl;
    }

};

class Refrigerator {
private:
    float _elecPower;
    string _specialAttack;

public:
    Refrigerator(float elecPower, string specialAttack)
        : _elecPower(elecPower), _specialAttack(specialAttack) {
    }

    void Attack() {
        float oldElecPower = _elecPower;
        _elecPower -= 10;
        cout << _specialAttack << "으로 공격하여 elecPower가 " << oldElecPower << " 에서 " << _elecPower << "로 줄어듦." << endl;
    }

};

class AirConditioner {
private:
    float _elecPower;
    string _specialAttack;

public:
    AirConditioner(float elecPower, string specialAttack)
        : _elecPower(elecPower), _specialAttack(specialAttack) {
    }

    void Attack() {
        float oldElecPower = _elecPower;
        _elecPower -= 10;
        cout << _specialAttack << "으로 공격하여 elecPower가 " << oldElecPower << " 에서 " << _elecPower << "로 줄어듦." << endl;
    }


};

int main() {

    Television tv(100, "광선공격");
    Refrigerator refrige(120, "냉각공격");
    AirConditioner airCon(100, "바람공격");

    tv.Attack();
    refrige.Attack();
    airCon.Attack();


    return 0;
}