#include <iostream>
#include <string>


using namespace std;

// 주소, 주민번호, 가족관계, 이름, 나이, 성별
// 캡슐화: 클래스 키워드로 데이타를 묶는 것
// 캡슐화를 통해서 클래스형 DataType Son

// class 클래스명 {
//    Datas;
// };

// 캡슐화의 기본 정책은 정보은닉
// 정보은닉은 캡슐화한 데이타에 접근하는 것을 철저하게 막겠다는 의미입니다.
// 객체안에 멤버에 접근을 제어할때 사용하는 것을
// 접근제어자.
// private (기본) : 객체안의 멤버에 접근하는 것을 허용하지 않겠다.
// protected : 자식에게는 접근 허용, 외부에서 접근 불허
// public : 외부에서 접근하는 것을 허용.

// 멤버변수는 외부에서 바로 접근하는 것을 허용하지 말라고 합니다. (권고사항)
// 멤버함수를 통해서 접근하도록 해라.
// 멤버변수에 접근할때 사용하는 함수를 Set/Get 함수라고 합니다.
// 멤버변수의 값을 변경하는 함수를 Set함수
// 멤버변수의 값을 외부로 전달하는 함수를 Get함수

class Son {
private:
    string address; // 멤버변수
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

    // 멤버변수를 Set/Get 함수를 사용해서 접근하는 경우
    // 디버깅 작업이 용이( 값이 어디서 잘못들어오는지 추적하기가 용이)
    // 저장되는 값의 Data의 유효성 검사, 무결성(정확성, 일관성, 유효성)검사를 넣어서
    // 잘못된 데이타가 들어가는 것을 보정할 수 있습니다.
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
    Son a; // 클래스형 DataType Son 변수 a를 만듦.
    // 클래스형 DataType으로 만들어진 변수를 특별히 객체라고 합니다.

// 클래스형 변수로 멤버에 접근할때 .(period)연산자를 사용합니다.

    a.SetAddress("런던");
    a.SetJuminNum("1111111-1111111");
    a.SetName("손흥민");
    a.SetAge(33);
    a.SetSungByul(false);   // true: 여자, false: 남자


    cout << "주소: " << a.GetAddress() << endl;
    cout << "주민번호: " << a.GetJuminNum() << endl;
    cout << "이름: " << a.GetName() << endl;
    cout << "나이: " << a.GetAge() << endl;
    if (a.GetSungByul()) {
        cout << "성별: 여자" << endl;
    }
    else {
        cout << "성별: 남자" << endl;
    }

    a.SetAge(400);


    return 0;
}