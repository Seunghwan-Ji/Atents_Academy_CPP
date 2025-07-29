#include <iostream>

using namespace std;

// ���� ����

class Dragon
{
private:
    string _name;
    int _health;   // �����
    int _attack;   // ���ݷ�
    int _defense;   // ����

public:
    Dragon(string name, int health, int attack, int defense)
        : _name(name)
        , _health(health)
        , _attack(attack)
        , _defense(defense)
    {}

    void Attack(Dragon& enemy)
    {
        int damage = _attack - enemy._defense;
        int enemyOldHealth = enemy._health;
        enemy._health -= damage;

        cout << _name << "�� " << enemy._name << "�� �����ؼ� ������� " << enemyOldHealth << "���� " << enemy._health << "�� ������" << endl;
    }


    void Info()
    {
        cout << "�̸�: " << _name << endl;
        cout << "�����: " << _health << endl;
        cout << "���ݷ�: " << _attack << endl;
        cout << "����: " << _defense << endl;
    }

};

int main()
{
    Dragon dragonA("dragonA", 100, 24, 10);
    Dragon dragonB("dragonB", 90, 20, 12);

    dragonA.Attack(dragonB);

    dragonB.Info();

    return 0;
}