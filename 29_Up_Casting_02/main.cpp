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
        cout << _name << " ¸»ÇÕ´Ï´Ù." << endl;
    }
};

class Pig : public Animal {
public:
    Pig(string name)
        : Animal(0, "µÅÁö") {
    }

    void Speak() {
        cout << _name << "°¡ ²Ü²ÜÇÕ´Ï´Ù." << endl;
    }
};

class Cow : public Animal {
public:
    Cow(string name)
        : Animal(1, "¼Ò") {
    }

    void Speak() {
        cout << _name << "°¡ À½¸ÅÇÕ´Ï´Ù." << endl;
    }
};

class Chicken : public Animal {
public:
    Chicken(string name)
        : Animal(2, "´ß") {
    }

    void Speak() {
        cout << _name << "ÀÌ ²¿³¢¿À ÇÕ´Ï´Ù." << endl;
    }
};

void InvokeSpeak(Animal* panimal) {
    if (panimal->GetType() == 0) {
        ((Pig*)panimal)->Speak(); // ´Ù¿î Ä³½ºÆÃ
    }
    else if (panimal->GetType() == 1) {
        ((Cow*)panimal)->Speak();   // ´Ù¿î Ä³½ºÆÃ
    }
    else if (panimal->GetType() == 2) {
        ((Chicken*)panimal)->Speak();   // ´Ù¿î Ä³½ºÆÃ
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
    Pig pig1("µÅÁö1");
    Pig pig2("µÅÁö2");
    Pig pig3("µÅÁö3");

    Cow cow1("¼Ò1");
    Cow cow2("¼Ò2");
    Cow cow3("¼Ò3");

    Chicken chicken1("´ß1");
    Chicken chicken2("´ß2");
    Chicken chicken3("´ß3");




    return 0;
}

