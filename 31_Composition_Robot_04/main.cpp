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
    Arm* _pLeftArm;
    Arm* _pRightArm;

public:
    Robot(string name, Arm* pleftArm, Arm* prightArm)
        : _name(name)
        , _pLeftArm(pleftArm)
        , _pRightArm(prightArm)
    {}

    void ChangeLeftArm(Arm* pLeftArm) { _pLeftArm = pLeftArm; }

    void ChangeRightArm(Arm* pRightArm) { _pRightArm = pRightArm; }

    void ChangeName(string name) { _name = name; }

    void Info()
    {
        cout << " -- " << _name << " -- " << endl;
        cout << "¿ÞÂÊÆÈ: ";
        _pLeftArm->Info();
        cout << endl;
        cout << "¿À¸¥ÂÊÆÈ: ";
        _pRightArm->Info();
        cout << endl;
        cout << endl;
    }
};

int main()
{
    CannonArm cannonArm;
    BombArm bombArm;
    LazerArm lazerArm;
    GunArm gunArm;

    Robot cannonArmRobot("Ä³³í¾Ï·Îº¿", &cannonArm, &cannonArm);
    Robot bombArmRobot("ÆøÅº¾Ï·Îº¿", &bombArm, &bombArm);
    Robot lazerArmRobot("·¹ÀÌÀú¾Ï·Îº¿", &lazerArm, &lazerArm);
    Robot gunArmRobot("°Ç¾Ï·Îº¿", &gunArm, &gunArm);

    Robot lgunArmRlazerArmRobot("¿ÞÆÈ °Ç¾Ï ¿À¸¥ÆÈ ·¹ÀÌÀú¾Ï ·Îº¿", &gunArm, &lazerArm);

    cannonArmRobot.Info();
    cout << endl;
    bombArmRobot.Info();
    cout << endl;
    lazerArmRobot.Info();
    cout << endl;
    gunArmRobot.Info();
    cout << endl;
    lgunArmRlazerArmRobot.Info();
    cout << endl;

    lgunArmRlazerArmRobot.ChangeLeftArm(&bombArm);
    lgunArmRlazerArmRobot.ChangeName("¿ÞÆÈ °Ç¾Ï ¿À¸¥ÆÈ ÆøÅº¾Ï ·Îº¿");
    lgunArmRlazerArmRobot.Info();

    return 0;
}