#include <iostream>

using namespace std;

int main() {
	int value = 0;

	value = 100 + 200;

	// �ӽ������� ��������� �������� ����
	// ��Ƴ��� �뵵�� ���.
	int&& rrefa = 100; // ������ ����

	int&& rrefb = 200;   // ����������

	cout << "rrefa = " << rrefa << endl;
	cout << "rrefb = " << rrefb << endl;

	rrefa = 400;
	cout << endl;
	cout << "rrefa = " << rrefa << endl;
	cout << "rrefb = " << rrefb << endl;

	
	// ���� ����.
	int a = 100;

	int& refa = a;
	refa = 200;

	return 0;
}