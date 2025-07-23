#include <iostream>
#include <string>

using namespace std;

class Computer {
private:
    string _id;

public:
    Computer(string id)
        : _id(id) {
    }

    void Login() {
        cout << _id << "로 로그인을 합니다." << endl;
    }

    void LogOut() {
        cout << _id << "가 로그아웃합니다. " << endl;
    }

    void PlayGame(string gameName) {
        cout << gameName << "을 플레이 합니다." << endl;
    }

    void SendKakaoTalkMessage(string id, string message) {
        cout << id << "에게 " << message << "를 보냅니다." << endl;
    }

    void ReceiveKakaoTalkMessage(string id, string message) {
        cout << id << "에게 " << message << "를 받았습니다." << endl;
    }

};

class Phone {
private:
    string _number;

public:
    Phone(string number)
        : _number(number) {
    }

    void SendCall(string number) {
        cout << _number << "에서 " << number << "로 전화를 겁니다." << endl;
    }

    void ReceiveCall(string number) {
        cout << number << "에서 " << _number << "로 걸려온 전화를 받습니다." << endl;
    }

    void SendMessage(string number, string message) {
        cout << number << "로 [ " << message << "]를 보냅니다." << endl;
    }

    void ReceiveMessage(string number, string message) {
        cout << number << "에서 [" << message << "] 가 도착했습니다." << endl;
    }

};


class SmartPhone : public Computer, public Phone {
public:
    SmartPhone(string phoneNumber, string id)
        : Phone(phoneNumber), Computer(id) {
    }

    void Login(string password) {
        Computer::Login();
    }

};

// Computer, Phone 클래스를 만들고 다중상속을 해서 SmartPhone 클래스만들고
// SmartPhone 객체 만든후에 작동시켜 보세요...

int main() {

    SmartPhone smartPhone("000-0000-0000", "monster");

    smartPhone.Login("00000");

    smartPhone.SendCall("111-1111-1111");
    smartPhone.ReceiveCall("222-2222-2222");

    smartPhone.SendMessage("333-3333-3333", "안녕하세요");
    smartPhone.ReceiveMessage("333-3333-3333", "누구세요");

    smartPhone.PlayGame("리니지");



    return 0;
}