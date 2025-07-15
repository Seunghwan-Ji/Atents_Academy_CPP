#include "Building.h"
#include <iostream>

using namespace std;

Building::Building(string name, float area, int maxFloor)
	: _name(name), _area(area), _maxFloor(maxFloor) {}

string Building::GetName() {
	return _name;
}

float Building::GetArea() {
	return _area;
}

int Building::GetMaxFloor() {
	return _maxFloor;
}

void Building::CheckFloor(int floor) {
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
