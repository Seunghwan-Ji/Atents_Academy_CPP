#pragma once
#include <string>
#include <iostream>

using namespace std;

class Building {
private:
	string _name;
	float _area;
	int _maxFloor;

public:
	Building(string name, float area, int maxFloor);
	string GetName();

	float GetArea();

	int GetMaxFloor();

	void CheckFloor(int floor);

	inline void CheckAllFloor(); // inline Ű���尡 ������ �����Ϸ��� �� �Լ���
	                             // inline �Լ��� ����� �޶�� ��û���� �޾Ƶ帳�ϴ�.
	                             // ��, ���� ������ �ڵ尡 ��� ���ϳ��� �־�� �մϴ�.
};

void Building::CheckAllFloor() {
	cout << endl;
	cout << "������ ��� �ý����� üũ�մϴ�." << endl;

	for (int i = 0; i < _maxFloor; i++) {
		CheckFloor(i);
	}
}