#include <iostream>

using namespace std;

// 관계연산자
// <, >, <=, >=, == , !=
int main() {
	int value1 = 0;
	int value2 = 0;

	cout << "처음 값을 입력하세요:";
	cin >> value1;   // cin객체는 키보드에서 값을 입력받을때 사용
	cout << "두번째 값을 입력하세요: ";
	cin >> value2;

	bool ret = value1 < value2;
	cout << value1 << " < " << value2 << " = " << ret << endl;

	ret = value1 > value2;
	cout << value1 << " > " << value2 << " = " << ret << endl;

	ret = value1 <= value2;
	cout << value1 << " <= " << value2 << " = " << ret << endl;

	ret = value1 >= value2;
	cout << value1 << " >= " << value2 << " = " << ret << endl;

	ret = value1 == value2;
	cout << value1 << " == " << value2 << " = " << ret << endl;

	ret = value1 != value2;
	cout << value1 << " != " << value2 << " = " << ret << endl;

	return 0;
}