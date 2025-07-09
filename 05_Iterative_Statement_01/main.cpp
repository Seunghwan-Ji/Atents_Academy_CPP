#include <iostream>

using namespace std;

// 반복문
// 특정한 명령들을 반복적으로 실행할 때 사용
// for, while, do-while(사용빈도 낮음)

int main() {
    // for(초기식; 조건식; 증감식){
    //       명령어들;
    // }

    // 반복횟수를 아는 경우에 사용하기 좋은 구조
    cout << "단일 for문" << endl;
    for (int i = 0; i < 10; i += 2) {
        cout << "i = " << i << endl;

    }

    cout << endl;
    cout << "이중 for문" << endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << "i = " << i << ", j = " << j << endl;
        }
    }

    /*
    int a = 0;
    for (; a < 10;) {
    }
    */


    cout << "while 문" << endl;
    // 반복횟수는 모르지만 
    // while문의 조건식 부분을 만족하는 동안에는
    // 얼마든지 명령어를 반복해도 되는 경우
    int loopCount = 0;

    cout << "정수값을 입력하세요: ";
    cin >> loopCount;

    while (loopCount > 0) {
        loopCount -= 10;
        cout << "loopCount = " << loopCount << endl;
    }

    cout << "do - while" << endl;
    cout << "정수값을 입력하세요: ";
    cin >> loopCount;

    do {
        loopCount -= 10;

        cout << "loopCount = " << loopCount << endl;

    } while (loopCount > 0);





    return 0;
}