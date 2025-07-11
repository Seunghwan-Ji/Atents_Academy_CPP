#include <iostream>

using namespace std;

int GetScore(int value) { // 일반함수
    static int sum = 0;   // 정적변수

    sum += value;

    return sum;
}


int main() {

    for (int i = 0; i < 10; i++) {
        GetScore(i);
    }

    int ret = GetScore(0);

    cout << "ret = " << ret << endl;


    return 0;
}