#include <iostream>

using namespace std;

// 제어문
// 프로그램의 실행 흐름을 제어할 때 사용
// 조건문
//   - 분기문(분기: 프로그램의 실행흐름을 다른쪽으로 보내는 것)
//    - 조건분기 : if, if-else, if-else-if, switch-case(선택문)
//    - 무조건 분기 : goto
// 반복문
// for, while, do - while

int main() {
    int a = 20;
    int b = 30;

    // if(조건식) {
    //      명령어;
    // }

    if (a > b) { // 단일 조건문
        cout << a << "가 " << b << "보다 크다." << endl;

    }

    if (a < b) { // 이중 조건문
        cout << a << "가 " << b << "보다 작다" << endl;
    }
    else {
        cout << a << "가 " << b << "보다 크거나 같다" << endl;
    }

    int input = 0;
    cout << "0에서 10사이에 정수값을 입력하세요:";
    cin >> input;

    if (input >= 0 && input < 3) { // 다중 조건문
        cout << input << "은 0에서 3사이의 숫자이다." << endl;
    }
    else if (input >= 3 && input < 5) {
        cout << input << "은 3보다 크고 5보다 작다" << endl;
    }
    else if (input >= 5 && input < 8) {
        cout << input << "은 5보다 크거나 같고 8보다 작다" << endl;
    }
    else { // 생략가능
        cout << input << "은 8보다 크거나 0보다 작다 " << endl;
    }




    return 0;
}