#include <iostream>
#include <string>

using namespace std;

// 실습
// 집에 있는 전자제품 3종류의 클래스를 각각 만들고
// 각 클래스 타입의 객체 생성한 후에 객체에 값을 저장하고 
// 객체의 값을 출력해보세요.

class Refrigerator
{
private:
	char _productCompany[30];
	float _capacityKg; // 음식 용량
	int _doorCount; // 도어 수

public:
	Refrigerator(const char* productCompany, float capacityKg, int doorCount)
		: _capacityKg(capacityKg)
		, _doorCount(doorCount)
	{
		strcpy_s(_productCompany, sizeof(_productCompany), productCompany);
	}

	void Info()
	{
		cout << "[냉장고 정보]" << endl;
		cout << "제조사: " << _productCompany << endl;
		cout << "용량(kg): " << _capacityKg << endl;
		cout << "도어 수: " << _doorCount << endl << endl;
	}
};

class Television
{
private:
	char _productCompany[30];
	float _resolution; // 해상도 
	float _size; // 몇인치

public:
	Television(const char* productCompany, float resolution, float size)
		: _resolution(resolution)
		, _size(size)
	{
		strcpy_s(_productCompany, sizeof(_productCompany), productCompany);
	}

	void Info()
	{
		cout << "[텔레비전 정보]" << endl;
		cout << "제조사: " << _productCompany << endl;
		cout << "해상도: " << _resolution << endl;
		cout << "크기(인치): " << _size << endl << endl;
	}
};

class WashingMachine
{
private:
	char _productCompany[30];
	float _capacityKg; // 세탁 용량
	bool _isDryerIncluded; // 건조기 포함 여부

public:
	WashingMachine(const char* productCompany, float capacityKg, bool isDryerIncluded)
		: _capacityKg(capacityKg)
		, _isDryerIncluded(isDryerIncluded)
	{
		strcpy_s(_productCompany, sizeof(_productCompany), productCompany);
	}

	void Info()
	{
		cout << "[세탁기 정보]" << endl;
		cout << "제조사: " << _productCompany << endl;
		cout << "세탁 용량(kg): " << _capacityKg << endl;
		cout << "건조기 포함 여부: " << (_isDryerIncluded ? "포함" : "미포함") << endl << endl;
	}
};

int main()
{
	Refrigerator samsungRef("삼성", 618.5f, 3);

	Television lgTV("엘지", 2880, 84);

	WashingMachine lgWM("엘지", 100.0f, true);

	samsungRef.Info();

	lgTV.Info();

	lgWM.Info();

	return 0;
}