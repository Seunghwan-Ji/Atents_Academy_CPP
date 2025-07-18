#include <iostream>
#include <string>

using namespace std;


class Animal {
protected:
    int _type;
    string _name;

public:
    Animal(int type, string name)
        : _type(type), _name(name) {
    }

    int GetType() {
        return _type;
    }

    void Speak() {
        cout << _name << " 말합니다." << endl;
    }
};

class Pig : public Animal {
public:
    Pig(string name)
        : Animal(0, "돼지") {
    }

    void Speak() {
        cout << _name << "가 꿀꿀합니다." << endl;
    }
};

class Cow : public Animal {
public:
    Cow(string name)
        : Animal(1, "소") {
    }

    void Speak() {
        cout << _name << "가 음매합니다." << endl;
    }
};

class Chicken : public Animal {
public:
    Chicken(string name)
        : Animal(2, "닭") {
    }

    void Speak() {
        cout << _name << "이 꼬끼오 합니다." << endl;
    }
};

void InvokeSpeak(Animal* panimal) {
    if (panimal->GetType() == 0) {
        ((Pig*)panimal)->Speak(); // 다운 캐스팅
    }
    else if (panimal->GetType() == 1) {
        ((Cow*)panimal)->Speak();   // 다운 캐스팅
    }
    else if (panimal->GetType() == 2) {
        ((Chicken*)panimal)->Speak();   // 다운 캐스팅
    }
}

void InvokeSpeak(Pig* panimal) {
    panimal->Speak();
}

void InvokeSpeak(Cow* panimal) {
    panimal->Speak();
}

void InvokeSpeak(Chicken* panimal) {
    panimal->Speak();
}


int main() {
    Pig pig1("돼지1");
    Pig pig2("돼지2");
    Pig pig3("돼지3");

    Cow cow1("소1");
    Cow cow2("소2");
    Cow cow3("소3");

    Chicken chicken1("닭1");
    Chicken chicken2("닭2");
    Chicken chicken3("닭3");

    // 객체를 관리하는 방법
    // 1. 각각의 객체에게 명령을 수행
    cout << "각각의 객체에게 명령을 수행" << endl;
    pig1.Speak();
    pig2.Speak();
    pig3.Speak();

    cow1.Speak();
    cow2.Speak();
    cow3.Speak();

    chicken1.Speak();
    chicken2.Speak();
    chicken3.Speak();

    // 2. 각각의 타입의 배열을 만들고 처리
    cout << endl;
    cout << "각각의 타입의 배열을 만들고 처리" << endl;

    Pig* pigArray[3] = { &pig1, &pig2, &pig3 };
    Cow* cowArray[3] = { &cow1, &cow2, &cow3 };
    Chicken* chickenArray[3] = { &chicken1, &chicken2, &chicken3 };

    for (int i = 0; i < 3; i++) {
        pigArray[i]->Speak();
        cowArray[i]->Speak();
        chickenArray[i]->Speak();
    }

    // 3. 상속에 따른 UpCasting을 사용해서 부모타입의 배열을 만들고
    // 자식들을 일괄적으로 저장해서 처리

    cout << endl;
    cout << "UpCasting을 사용" << endl;
    Animal* panimal[9] = { &pig1, &cow1, &chicken1, &pig2, &cow2, &chicken2, &pig3, &cow2, &chicken3 };

    for (int i = 0; i < 9; i++) {
        panimal[i]->Speak();
    }


    for (int i = 0; i < 9; i++) {
        InvokeSpeak(panimal[i]);
    }



    return 0;
}

