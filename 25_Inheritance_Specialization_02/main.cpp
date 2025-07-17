#include <iostream>
#include <string>

// 특수화
// 동물 육성 시뮬레이션 게임
// 돼지, 소, 닭

using namespace std;

enum Type {
    COW,
    PIG,
    CHICKEN,
    DOLPHIN
};

class Animal {
private:
    enum Type _type;
    string _name;
    float _weight;
    float _height;
    float _healthRate;
    bool _isFly;
    bool _isSwim;

    void Fly() {
        cout << _name << "이 납니다." << endl;
    }

    void Swim() {
        cout << _name << "이 헤엄칩니다." << endl;
    }

public:
    Animal(Type type, string name, float weight, float height, float healthRate, bool isFly, bool isSwim)
        : _type(type), _name(name), _weight(weight), _height(height), _healthRate(healthRate), _isFly(isFly), _isSwim(isSwim) {
    }

    void Speak() {
        switch (_type) {
        case COW:
            cout << _name << "가 음매합니다. " << endl;
            break;

        case PIG:
            cout << _name << "가 꿀꿀합니다." << endl;
            break;

        case CHICKEN:
            cout << _name << "이 꼬끼오합니다." << endl;
            break;

        case DOLPHIN:
            cout << _name << "가 끽끽합니다." << endl;
            break;

        default:
            cout << _name << "이 말합니다." << endl;
            break;
        }
    }

    void Run() {
        if (_isFly) {
            Fly();

        }
        else {
            if (_isSwim) {
                Swim();
            }
            else {
                cout << _name << "이 뜁니다." << endl;
            }

        }
    }

    void Info() {
        cout << "이름: " << _name << endl;
        cout << "몸무게: " << _weight << endl;
        cout << "신장: " << _height << endl;
        cout << "건강지수: " << _healthRate << endl;

        if (_type == CHICKEN) {
            if (_isFly) {
                cout << "종류: 나는 닭" << endl;
            }
            else {
                cout << "종류: 못나는 닭" << endl;
            }
        }
    }


};

int main() {

    Animal pig(PIG, "돼지", 240.0f, 160.0f, 88.0f, false, false);
    Animal cow(COW, "소", 280.0f, 200.0f, 77.0f, false, false);
    Animal flyChicken(CHICKEN, "나는 닭", 4.0f, 40.0f, 90.0f, true, false);
    Animal notFlyChicken(CHICKEN, "못나는 닭", 4.5f, 43.0f, 66.0f, false, false);
    Animal dolphin(DOLPHIN, "돌고래", 300.0f, 200.0f, 84.0f, false, true);

    pig.Speak();
    cow.Speak();
    flyChicken.Speak();
    notFlyChicken.Speak();
    dolphin.Speak();

    cout << endl;
    pig.Run();
    cow.Run();
    flyChicken.Run();
    notFlyChicken.Run();
    dolphin.Run();

    cout << endl;

    pig.Info(); cout << endl;
    cow.Info(); cout << endl;
    flyChicken.Info(); cout << endl;
    notFlyChicken.Info(); cout << endl;
    dolphin.Info(); cout << endl;





    return 0;
}