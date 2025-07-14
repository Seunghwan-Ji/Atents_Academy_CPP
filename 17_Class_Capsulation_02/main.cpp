#include <iostream>
#include <string>

using namespace std;

// �ǽ�
// ���� �ִ� ������ǰ 3������ Ŭ������ ���� �����
// �� Ŭ���� Ÿ���� ��ü ������ �Ŀ� ��ü�� ���� �����ϰ� 
// ��ü�� ���� ����غ�����.

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
        cout << _specialAttack << "���� �����Ͽ� elecPower�� " << oldElecPower << " ���� " << _elecPower << "�� �پ��." << endl;
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
        cout << _specialAttack << "���� �����Ͽ� elecPower�� " << oldElecPower << " ���� " << _elecPower << "�� �پ��." << endl;
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
        cout << _specialAttack << "���� �����Ͽ� elecPower�� " << oldElecPower << " ���� " << _elecPower << "�� �پ��." << endl;
    }


};

int main() {

    Television tv(100, "��������");
    Refrigerator refrige(120, "�ð�����");
    AirConditioner airCon(100, "�ٶ�����");

    tv.Attack();
    refrige.Attack();
    airCon.Attack();


    return 0;
}