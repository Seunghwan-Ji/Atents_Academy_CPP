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
        cout << _name << " ���մϴ�." << endl;
    }
};

class Pig : public Animal {
public:
    Pig(string name)
        : Animal(0, "����") {
    }

    void Speak() {
        cout << _name << "�� �ܲ��մϴ�." << endl;
    }
};

class Cow : public Animal {
public:
    Cow(string name)
        : Animal(1, "��") {
    }

    void Speak() {
        cout << _name << "�� �����մϴ�." << endl;
    }
};

class Chicken : public Animal {
public:
    Chicken(string name)
        : Animal(2, "��") {
    }

    void Speak() {
        cout << _name << "�� ������ �մϴ�." << endl;
    }
};

void InvokeSpeak(Animal* panimal) {
    if (panimal->GetType() == 0) {
        ((Pig*)panimal)->Speak(); // �ٿ� ĳ����
    }
    else if (panimal->GetType() == 1) {
        ((Cow*)panimal)->Speak();   // �ٿ� ĳ����
    }
    else if (panimal->GetType() == 2) {
        ((Chicken*)panimal)->Speak();   // �ٿ� ĳ����
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
    Pig pig1("����1");
    Pig pig2("����2");
    Pig pig3("����3");

    Cow cow1("��1");
    Cow cow2("��2");
    Cow cow3("��3");

    Chicken chicken1("��1");
    Chicken chicken2("��2");
    Chicken chicken3("��3");




    return 0;
}

