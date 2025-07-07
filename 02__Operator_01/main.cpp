#include <iostream>

using namespace std;

int main() {
	int a = 1;
	int b = 2;
	int ret = 0;

	ret = a / b;

	cout << a << " / " << b << " = " << ret << endl;

	float fret = 0.0f;

	fret = a / b;

	cout << a << " / " << b << " = " << fret << endl;

	fret = a / (float)b; // (float) 형변환연산자

	cout << a << " / " << b << " = " << fret << endl;


	return 0;
}