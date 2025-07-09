#include <iostream>
#include <string>


using namespace std;

// �ּ�, �ֹι�ȣ, ��������, �̸�, ����, ����
// ĸ��ȭ: Ŭ���� Ű����� ����Ÿ�� ���� ��
// ĸ��ȭ�� ���ؼ� Ŭ������ DataType Son

// class Ŭ������ {
//    Datas;
// };

// ĸ��ȭ�� �⺻ ��å�� ��������
// ���������� ĸ��ȭ�� ����Ÿ�� �����ϴ� ���� ö���ϰ� ���ڴٴ� �ǹ��Դϴ�.
// ��ü�ȿ� ����� ������ �����Ҷ� ����ϴ� ����
// ����������.
// private (�⺻) : ��ü���� ����� �����ϴ� ���� ������� �ʰڴ�.
// protected : �ڽĿ��Դ� ���� ���, �ܺο��� ���� ����
// public : �ܺο��� �����ϴ� ���� ���.

// ��������� �ܺο��� �ٷ� �����ϴ� ���� ������� ����� �մϴ�. (�ǰ����)
// ����Լ��� ���ؼ� �����ϵ��� �ض�.
// ��������� �����Ҷ� ����ϴ� �Լ��� Set/Get �Լ���� �մϴ�.
// ��������� ���� �����ϴ� �Լ��� Set�Լ�
// ��������� ���� �ܺη� �����ϴ� �Լ��� Get�Լ�

class Son {
private:
    string address; // �������
    string juminNum;
    string name;
    int age;
    bool sungbyul;

public:
    void SetAddress(string value) {
        address = value;
    }

    string GetAddress() {
        return address;
    }

    void SetJuminNum(string value) {
        juminNum = value;
    }

    string GetJuminNum() {
        return juminNum;
    }

    void SetName(string value) {
        name = value;
    }

    string GetName() {
        return name;
    }

    // ��������� Set/Get �Լ��� ����ؼ� �����ϴ� ���
    // ����� �۾��� ����( ���� ��� �߸��������� �����ϱⰡ ����)
    // ����Ǵ� ���� Data�� ��ȿ�� �˻�, ���Ἲ(��Ȯ��, �ϰ���, ��ȿ��)�˻縦 �־
    // �߸��� ����Ÿ�� ���� ���� ������ �� �ֽ��ϴ�.
    void SetAge(int value) {
        if (value < 0) {
            age = 0;
        }
        else if (value > 200) {
            age = 200;
        }
        else {
            age = value;
        }

    }

    int GetAge() {
        return age;
    }

    void SetSungByul(bool value) {
        sungbyul = value;
    }

    bool GetSungByul() {
        return sungbyul;
    }
};


int main() {
    Son a; // Ŭ������ DataType Son ���� a�� ����.
    // Ŭ������ DataType���� ������� ������ Ư���� ��ü��� �մϴ�.

// Ŭ������ ������ ����� �����Ҷ� .(period)�����ڸ� ����մϴ�.

    a.SetAddress("����");
    a.SetJuminNum("1111111-1111111");
    a.SetName("�����");
    a.SetAge(33);
    a.SetSungByul(false);   // true: ����, false: ����


    cout << "�ּ�: " << a.GetAddress() << endl;
    cout << "�ֹι�ȣ: " << a.GetJuminNum() << endl;
    cout << "�̸�: " << a.GetName() << endl;
    cout << "����: " << a.GetAge() << endl;
    if (a.GetSungByul()) {
        cout << "����: ����" << endl;
    }
    else {
        cout << "����: ����" << endl;
    }

    a.SetAge(400);


    return 0;
}