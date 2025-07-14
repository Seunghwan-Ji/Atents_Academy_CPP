#pragma once
#include <string>

class Building {
private:
	std::string _name;
	float _area;
	int _maxFloor;

public:
	Building(std::string name, float area, int maxFloor);
	std::string GetName();

	float GetArea();

	int GetMaxFloor();

	void CheckFloor(int floor);

	void CheckAllFloor();
};