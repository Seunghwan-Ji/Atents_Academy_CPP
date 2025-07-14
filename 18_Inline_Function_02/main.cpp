#include <iostream>
#include <string>
#include "Building.h"

using namespace std;

// 인라인 함수

// C++은 태생적으로 C언어의 구문 구조를 기반으로 개발이 되어서
// 선언부(.h, 헤더파일), 구현부(.cpp)을 나누어서 개발을 하도록 되어있습니다.
// 클래스 내부에서 함수의 구현을 하는 경우에는 컴파일러 구현부에 멤버함수를
// 구현했을 때와는 다르게 받아드립니다.
// class 선언부안에 멤버함수의 구현부가 있는 경우에는
// 컴파일러 해당 멤버함수를 inline함수로 만들어달라는 요청으로 받아드립니다.



int main() {
	Building starTower("스타타워", 112300.23f, 23);

	cout << "빌딩명: " << starTower.GetName() << endl;
	cout << "전체면적: " << starTower.GetArea() << "평" << endl;
	cout << "전체층수: " << starTower.GetMaxFloor() << "층" << endl;

	starTower.CheckFloor(-1);

	int floor = -1;
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


	starTower.CheckAllFloor();


	return 0;
}