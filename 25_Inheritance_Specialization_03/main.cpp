#include <iostream>
#include <string>

// 특수화
// 동물 육성 시뮬레이션 게임
// 돼지, 소, 닭

using namespace std;

class Animal {
protected:
    string _name;
    float _weight;
    float _height;
    float _healthRate;

public:
    Animal(string name, float weight, float height, float healthRate)
        : _name(name), _weight(weight), _height(height), _healthRate(healthRate) {
    }

    void Speak() {
        cout << _name << "이 말합니다." << endl;
    }

    void Run() {
        cout << _name << "이 뜁니다." << endl;
    }

    void Info() {
        cout << "이름: " << _name << endl;
        cout << "몸무게: " << _weight << endl;
        cout << "신장: " << _height << endl;
        cout << "건강지수: " << _healthRate << endl;
    }
};

class Cow : public Animal {
public:
    Cow(string name, float weight, float height, float healthRate)
        : Animal(name, weight, height, healthRate) {
    }

    void Speak() {
        cout << _name << "이 음매합니다." << endl;
    }

};

class Pig : public Animal {
public:
    Pig(string name, float weight, float height, float healthRate)
        : Animal(name, weight, height, healthRate) {
    }

    void Speak() {
        cout << _name << "이 꿀꿀합니다." << endl;
    }

};

class Chicken : public Animal {
private:
    bool _isFly;

    void Fly() {
        cout << _name << "이 납니다." << endl;
    }

public:
    Chicken(string name, float weight, float height, float healthRate, bool isFly)
        : Animal(name, weight, height, healthRate), _isFly(isFly) {
    }

    void Speak() {
        cout << _name << "이 꼬끼오합니다." << endl;
    }

    void Run() {
        if (_isFly) {
            Fly();
        }
        else {
            Animal::Run();
        }
    }

    void Info() {
        Animal::Info();

        if (_isFly) {
            cout << "종류: 나는 닭" << endl;
        }
        else {
            cout << "종류: 못나는 닭" << endl;
        }
    }

};

class Dolphin : public Animal {
private:

    void Swim() {
        cout << _name << "이 헤엄칩니다." << endl;
    }

public:
    Dolphin(string name, float weight, float height, float healthRate)
        : Animal(name, weight, height, healthRate) {
    }

    void Speak() {
        cout << _name << "가 끽끽합니다. " << endl;
    }

};

int main() {

    Pig pig("돼지", 240.0f, 160.0f, 88.0f);
    Cow cow("소", 280.0f, 200.0f, 77.0f);
    Chicken flyChicken("나는 닭", 4.0f, 40.0f, 90.0f, true);
    Chicken notFlyChicken("못나는 닭", 4.5f, 43.0f, 66.0f, false);
    Dolphin dolphin("돌고래", 300.0f, 200.0f, 84.0f);

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