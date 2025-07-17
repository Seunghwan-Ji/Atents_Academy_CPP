// 새로운 가축 추가해보기.

#include <iostream>
#include <string>

using namespace std;

// 상속
// 일반화, 특수화

// 동물 육성 시뮬레이션 게임
// 소, 돼지, 닭

// 1. 재사용성
// 2. 유지보수성
// 3. 확장성
// 4. 다형성에 기반구조를 제공한다.

class Stock {
private:
    string _name;   // 이름
    float _weight;   // 몸무게
    float _height; // 키
    float _health;   // 건강지수

public:
    Stock(string name, float weight, float height, float health)
        : _name(name), _weight(weight), _height(height), _health(health) {
    }

    string GetName() {
        return _name;
    }

    void Speak() {
        cout << _name << "이 말합니다." << endl;
    }

    void Run() {
        cout << _name << "이 뜁니다. " << endl;
    }

    void Eat() {
        cout << _name << "이 먹는다." << endl;
    }

    string GetHealth() {
        if (_health > 80) {
            return "매우건강";
        }
        else if (_health > 60 && _health <= 80) {
            return "건강";
        }
        else if (_health > 40 && _health <= 60) {
            return "부실";
        }
        else {
            return "치료요망";
        }
    }

    void Info() {
        cout << "이름: " << _name << endl;
        cout << "몸무게: " << _weight << endl;
        cout << "신장: " << _height << endl;
        cout << "건강지수: " << GetHealth() << endl;
    }

};

class Cow : public Stock {
public:
    Cow(string name, float weight, float height, float health)
        : Stock(name, weight, height, health) {
    }

    void Speak() {
        cout << GetName() << "가 음매합니다." << endl;
    }

};

class Pig : public Stock {
public:
    Pig(string name, float weight, float height, float health)
        : Stock(name, weight, height, health) {
    }

    void Speak() {
        cout << GetName() << "가 꿀꿀합니다." << endl;
    }

};

class Chicken : public Stock {
private:
    bool _isFly;

    void Fly() {
        cout << GetName() << "이 납니다." << endl;
    }

public:
    Chicken(string name, float weight, float height, float health, bool isFly)
        : Stock(name, weight, height, health), _isFly(isFly) {
    }

    void Speak() {
        cout << GetName() << "이 꼬끼오 합니다." << endl;
    }

    void Run() {
        if (_isFly) {
            Fly();
        }
        else {
            Stock::Run();
        }
    }


    void Info() {
        Stock::Info();

        if (_isFly) {
            cout << "종류: 나는 닭" << endl;
        }
        else {
            cout << "종류: 못나는 닭" << endl;
        }
        cout << endl;
    }

};

class Sheep : public Stock {
private:
    int _type;   // 0: 털을 제공하는 양, 1: 고기를 제공하는 양

public:
    Sheep(string name, float weight, float height, float health, int type)
        : Stock(name, weight, height, health), _type(type)
    {
    }

    void Speak() {
        cout << GetName() << "이 음메에에합니다." << endl;
    }

    void Info() {
        Stock::Info();

        switch (_type) {
        case 0:
            cout << "종류: 털양" << endl;
            break;

        case 1:
            cout << "종류: 고기양" << endl;
            break;

        default:
            cout << "종류: 미확인" << endl;
            break;
        }
    }
};

class Duck : public Stock
{
private:
    int _type; // 0: 고기용 오리, 1: 관상용 오리

public:
    Duck(string name, float weight, float height, float health, int type)
        : Stock(name, weight, height, health)
        , _type(type)
    {
    }

    void Speak()
    {
        cout << GetName() << "가 꽥꽥합니다." << endl;
    }

    void Run()
    {
        cout << GetName() << "가 헤엄칩니다." << endl;
    }

    void Info() {
        Stock::Info();

        switch (_type) {
        case 0:
            cout << "종류: 고기용 오리" << endl;
            break;

        case 1:
            cout << "종류: 관상용 오리" << endl;
            break;

        default:
            cout << "종류: 미확인" << endl;
            break;
        }
    }
};

int main() {

    Cow cow("소", 230.0f, 200.0f, 81.0f);
    Pig pig("돼지", 190.0f, 160.0f, 75.0f);
    Chicken flyChicken("나는 닭", 4.0f, 40.0f, 60.0f, true);
    Chicken notFlyChicken("못나는 닭", 3.8f, 40.0f, 60.0f, false);
    Sheep purSheep("털 양", 100.0f, 110.0f, 80.0f, 0);
    Sheep beefSheep("고기 양", 120.0f, 120.0f, 70.0f, 1);
    Duck meatDuck("고기 오리", 5.0f, 50.0f, 80.0f, 0);
    Duck ornamentalDuck("관상 오리", 2.5f, 25.0f, 70.0f, 1);

    cow.Speak();
    pig.Speak();
    flyChicken.Speak();
    notFlyChicken.Speak();
    purSheep.Speak();
    beefSheep.Speak();
    meatDuck.Speak();
    ornamentalDuck.Speak();

    cout << endl;
    cow.Run();
    pig.Run();
    flyChicken.Run();
    notFlyChicken.Run();
    purSheep.Run();
    beefSheep.Run();
    meatDuck.Run();
    ornamentalDuck.Run();

    cout << endl;
    cow.Info();
    cout << endl;
    pig.Info();
    cout << endl;
    flyChicken.Info();
    cout << endl;
    notFlyChicken.Info();
    cout << endl;
    purSheep.Info();
    cout << endl;
    beefSheep.Info();
    cout << endl;
    meatDuck.Info();
    cout << endl;
    ornamentalDuck.Info();



    return 0;
}