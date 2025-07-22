#include <iostream>

using namespace std;

class Arm
{
private:
    string _name;

public:
    Arm(string name)
        : _name(name)
    {}

    void Info()
    {
        cout << _name;
    }
};

class CannonArm : public Arm
{
public:
    CannonArm()
        : Arm("Ä³³í¾Ï")
    {}
};

class BombArm : public Arm
{
public:
    BombArm()
        : Arm("ÆøÅº¾Ï")
    {}
};

class LazerArm : public Arm
{
public:
    LazerArm()
        : Arm("·¹ÀÌÀú¾Ï")
    {}
};

class GunArm : public Arm
{
public:
    GunArm()
        : Arm("°Ç¾Ï")
    {}
};

class Robot
{
private:
    string _name;
    Arm&   _leftArm;
    Arm&   _rightArm;

public:
    Robot(string name, Arm& leftArm, Arm& rightArm)
        : _name(name)
        , _leftArm(leftArm)
        , _rightArm(rightArm)
    {}

    void Info()
    {
        cout << "-- " << _name << " --" << endl;
        cout << "¿ÞÂÊÆÈ: ";
        _leftArm.Info();
        cout << endl;
        cout << "¿À¸¥ÂÊÆÈ: ";
        _rightArm.Info();
        cout << endl;
        cout << endl;
    }
};

class CannonArmRobot : public Robot
{
public:
    CannonArmRobot(CannonArm& leftArm, CannonArm& rightArm)
        : Robot("Ä³³í¾Ï ·Îº¿", leftArm, rightArm)
    {}
};

class BombArmRobot : public Robot
{
public:
    BombArmRobot(BombArm& leftArm, BombArm& rightArm)
        : Robot("ÆøÅº¾Ï ·Îº¿", leftArm, rightArm)
    {}
};

class LazerArmRobot : public Robot
{
public:
    LazerArmRobot(LazerArm& leftArm, LazerArm& rightArm)
        : Robot("·¹ÀÌÀú¾Ï ·Îº¿", leftArm, rightArm)
    {}
};

class GunArmRobot : public Robot
{
public:
    GunArmRobot(GunArm& leftArm, GunArm& rightArm)
        : Robot("°Ç¾Ï ·Îº¿", leftArm, rightArm)
    {}
};

int main() {
    CannonArm cannonArm;
    BombArm bombArm;
    LazerArm lazerArm;
    GunArm gunArm;


    CannonArmRobot cannonArmRobot(cannonArm, cannonArm);
    BombArmRobot bombArmRobot(bombArm, bombArm);
    LazerArmRobot lazerArmRobot(lazerArm, lazerArm);
    GunArmRobot gunArmRobot(gunArm, gunArm);

    cannonArmRobot.Info();
    cout << endl;
    bombArmRobot.Info();
    cout << endl;
    lazerArmRobot.Info();
    cout << endl;
    gunArmRobot.Info();


    return 0;
}