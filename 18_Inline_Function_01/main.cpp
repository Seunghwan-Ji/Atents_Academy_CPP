#include <iostream>
#include <string>

using namespace std;

// 인라인 함수

class Building {
private:
    std::string _name;
    float _area;
    int _maxFloor;

public:
    Building(string name, float area, int maxFloor)
        : _name(name), _area(area), _maxFloor(maxFloor) {
    }

    string GetName() {
        return _name;
    }

    float GetArea() {
        return _area;
    }

    int GetMaxFloor() {
        return _maxFloor;
    }

    void CheckFloor(int floor) {
        switch (floor) {
        case -1:
            cout << "지하 1층 배수 시스템을 체크합니다." << endl;
            break;

        case 1:
            cout << "1층 엘리베이터 시스템을 체크합니다." << endl;
            break;

        case 2:
            cout << "2층 방화시스템을 체크합니다." << endl;
            break;

        default:
            cout << floor << "층 일반시스템을 체크합니다." << endl;
            break;
        }
    }

    void CheckAllFloor() {
        cout << std::endl;
        cout << "빌딩의 모든 시스템을 체크합니다." << endl;

        for (int i = 0; i < _maxFloor; i++) {
            CheckFloor(i);
        }
    }
};


int main() {
    Building starTower("스타타워", 112300.23f, 23);

    cout << "빌딩명: " << starTower.GetName() << endl;
    cout << "전체면적: " << starTower.GetArea() << "평" << endl;
    cout << "전체층수: " << starTower.GetMaxFloor() << "층" << endl;

    starTower.CheckFloor(-1);


    starTower.CheckAllFloor();


    return 0;
}