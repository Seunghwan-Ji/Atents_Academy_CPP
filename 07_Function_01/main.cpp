#include <iostream>

using namespace std;

// 함수(Function)

// returnType 함수명(매개변수){
//      명령어들;
// };
// returnType은 함수가 명령어를 처리한 결과값을 어떤 DataType으로 돌려주는지 알려주는 역활
// 함수명: 함수를 호출할때 사용하는 이름
// 매개변수(parameter): 함수를 호출할때 전달하는 인자(argument)값을 받는 변수

// 유용한 코드
// 반복되는 코드
// 를 하나의 단위로 묶을때 함수를 사용합니다.

// 


int add(int a, int b) {
    int sum = 0;
    sum = a + b;

    return sum;
}

void PrintMonster(int count) {
    for (int i = 0; i < count; i++) {
        cout << "Monster" << endl;
    }
}


int main() {

    PrintMonster(5);
    /*
    cout << "Monster" << endl;
    cout << "Monster" << endl;
    cout << "Monster" << endl;
    cout << "Monster" << endl;
    cout << "Monster" << endl;
    */



    PrintMonster(3);
    /*
    cout << "Monster" << endl;
    cout << "Monster" << endl;
    cout << "Monster" << endl;
    */


    PrintMonster(6);
    /*
    cout << "Monster" << endl;
    cout << "Monster" << endl;
    cout << "Monster" << endl;
    cout << "Monster" << endl;
    cout << "Monster" << endl;
    cout << "Monster" << endl;
    */


    return 0;
}