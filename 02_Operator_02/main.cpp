#include <iostream>
#include <random>

using namespace std;

// % 나머지 연산자
// 임의의값을 일정한 범위의 값으로 만들때 사용.

int main() {
    std::random_device rand;
    std::mt19937 random(rand());
    std::uniform_int_distribution<int> dist(0, 65535);

    int randValue = 0;
    int direction = 0;

    // North: 0, South: 1, West: 2, East: 3
    for (int i = 0; i < 10; i++) {
        randValue = dist(random);   // 랜덤 값을 구함
        direction = randValue % 4;   // 0 ~ 3 사이의 값으로 만듦

        cout << "랜덤값: " << randValue << ", 방향값: " << direction << endl;

        switch (direction) {
        case 0:
            cout << "북쪽으로 이동" << endl;
            break;

        case 1:
            cout << "남쪽으로 이동" << endl;
            break;

        case 2:
            cout << "서쪽으로 이동" << endl;
            break;

        case 3:
            cout << "동쪽으로 이동" << endl;
            break;

        }
        cout << endl;

    }






    return 0;
}