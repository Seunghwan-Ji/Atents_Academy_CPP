#include <iostream>
#include <string>

// 기능의 확장으로 본 상속
class ExtString : public std::string
{
public:
    ExtString() {}
    ExtString(char* pStr)
        : std::string(pStr) {}

    ExtString(std::string str)
        : std::string(str) {}

    int GetLength() {
        const char* ptr = c_str(); // 문자열이 저장된 메모리 주소값을 전달하는
        // string 클래스의 멤버함수

        // 주소값을 통해 문자열의 길이를 계산하는 기능.
        int count = 0;
        for (count = 0; ptr[count] != 0; count++); // 널 종료 문자를 만나기 전 까지 반복.

        return count;
    }

};

int main() {
    using namespace std;

    ExtString str((char*)"monster");

    cout << "str 문자열 길이: " << str.GetLength() << endl;

    cout << str << endl;

    string str2 = "I am a boy!!";
    ExtString extStr(str2);

    cout << "extStr 문자열길이: " << extStr.GetLength() << endl;
    cout << extStr << endl;


    ExtString str3 = str + extStr;

    cout << "str3 문자열 길이: " << str3.GetLength() << endl;
    cout << str3 << endl;

}