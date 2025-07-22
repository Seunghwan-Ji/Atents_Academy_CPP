#include <iostream>

using namespace std;

class CannonArm {
private:
    string _name;

public:
    CannonArm()
        : _name("Ä³³í¾Ï") {
    }

    void Info() {
        cout << _name;
    }
};

class BombArm {
private:
    string _name;

public:
    BombArm()
        : _name("ÆøÅº¾Ï") {
    }

    void Info() {
        cout << _name;
    }
};

class LazerArm {
private:
    string _name;

public:
    LazerArm()
        : _name("·¹ÀÌÀú¾Ï") {
    }

    void Info() {
        cout << _name;
    }
};


class CannonArmRobot {
private:
    CannonArm _leftArm, _rightArm;

public:
    CannonArmRobot() {}

    void Info() {
        cout << "-- Ä³³í¾Ï ·Îº¿ --" << endl;
        cout << "¿ÞÂÊÆÈ: ";
        _leftArm.Info();
        cout << endl;
        cout << "¿À¸¥ÂÊÆÈ: ";
        _rightArm.Info();
        cout << endl;
        cout << endl;
    }

};

class BombArmRobot {
private:
    BombArm _leftArm, _rightArm;

public:
    BombArmRobot() {}

    void Info() {
        cout << "-- ÆøÅº¾Ï ·Îº¿ -- " << endl;
        cout << "¿ÞÂÊÆÈ: ";
        _leftArm.Info();
        cout << endl;
        cout << "¿À¸¥ÂÊÆÈ: ";
        _rightArm.Info();
        cout << endl;
        cout << endl;
    }

};

class LazerArmRobot {
private:
    LazerArm _leftArm, _rightArm;

public:
    LazerArmRobot() {}

    void Info() {
        cout << "-- ·¹ÀÌÀú¾Ï ·Îº¿ -- " << endl;
        cout << "¿ÞÂÊÆÈ: ";
        _leftArm.Info();
        cout << endl;
        cout << "¿À¸¥ÂÊÆÈ: ";
        _rightArm.Info();
        cout << endl;
        cout << endl;
    }
};

int main() {
    CannonArmRobot cannonArmRobot;
    BombArmRobot bombArmRobot;
    LazerArmRobot lazerArmRobot;

    cannonArmRobot.Info();
    cout << endl;
    bombArmRobot.Info();
    cout << endl;
    lazerArmRobot.Info();


    return 0;
}