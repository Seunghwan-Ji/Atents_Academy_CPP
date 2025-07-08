#include <iostream>

using namespace std;

int main() {

    int x = 0;
    cout << "x의 값을 입력하세요: ";
    cin >> x;

    bool isIn = (0 < x) && (x < 10);


    if (isIn) {
        cout << "x: " << x << "가 0과 10사이에 있다." << endl;
    }
    else {
        cout << "x: " << x << "가 0과 10사이에 없다." << endl;
    }


    return 0;
}