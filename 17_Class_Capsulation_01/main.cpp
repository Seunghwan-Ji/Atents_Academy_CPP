#include <iostream>
#include <string>

using namespace std;

// �ǽ�
// ���� �ִ� ������ǰ 3������ Ŭ������ ���� �����
// �� Ŭ���� Ÿ���� ��ü ������ �Ŀ� ��ü�� ���� �����ϰ� 
// ��ü�� ���� ����غ�����.

class Refrigerator
{
private:
	char _productCompany[30];
	float _capacityKg; // ���� �뷮
	int _doorCount; // ���� ��

public:
	Refrigerator(const char* productCompany, float capacityKg, int doorCount)
		: _capacityKg(capacityKg)
		, _doorCount(doorCount)
	{
		strcpy_s(_productCompany, sizeof(_productCompany), productCompany);
	}

	void Info()
	{
		cout << "[����� ����]" << endl;
		cout << "������: " << _productCompany << endl;
		cout << "�뷮(kg): " << _capacityKg << endl;
		cout << "���� ��: " << _doorCount << endl << endl;
	}
};

class Television
{
private:
	char _productCompany[30];
	float _resolution; // �ػ� 
	float _size; // ����ġ

public:
	Television(const char* productCompany, float resolution, float size)
		: _resolution(resolution)
		, _size(size)
	{
		strcpy_s(_productCompany, sizeof(_productCompany), productCompany);
	}

	void Info()
	{
		cout << "[�ڷ����� ����]" << endl;
		cout << "������: " << _productCompany << endl;
		cout << "�ػ�: " << _resolution << endl;
		cout << "ũ��(��ġ): " << _size << endl << endl;
	}
};

class WashingMachine
{
private:
	char _productCompany[30];
	float _capacityKg; // ��Ź �뷮
	bool _isDryerIncluded; // ������ ���� ����

public:
	WashingMachine(const char* productCompany, float capacityKg, bool isDryerIncluded)
		: _capacityKg(capacityKg)
		, _isDryerIncluded(isDryerIncluded)
	{
		strcpy_s(_productCompany, sizeof(_productCompany), productCompany);
	}

	void Info()
	{
		cout << "[��Ź�� ����]" << endl;
		cout << "������: " << _productCompany << endl;
		cout << "��Ź �뷮(kg): " << _capacityKg << endl;
		cout << "������ ���� ����: " << (_isDryerIncluded ? "����" : "������") << endl << endl;
	}
};

int main()
{
	Refrigerator samsungRef("�Ｚ", 618.5f, 3);

	Television lgTV("����", 2880, 84);

	WashingMachine lgWM("����", 100.0f, true);

	samsungRef.Info();

	lgTV.Info();

	lgWM.Info();

	return 0;
}