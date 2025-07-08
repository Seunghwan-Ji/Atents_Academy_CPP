#include <iostream>

using namespace std;


// 증감연산자
// ++ , --
// 정수값을 1증가, 1감소
int main() {
	int a = 20;
	int c = 0;

	a++;   // 후치형
	// a = a + 1;
	cout << "a++ = " << a << endl;

	++a;   // 전치형
	// a = a + 1;
	cout << "++a = " << a << endl;

	c = a++;
	// c = a;
	// a = a + 1;
	cout << "c = a++ " << "c = " << c << ", a = " << a << endl;


	c = ++a;
	// a = a + 1;
	// c = a;
	cout << "c = ++a " << "c = " << c << ", a = " << a << endl;


	a--;
	// a = a - 1;


	--a;
	// a = a - 1;

	c = a--;
	// c = a;
	// a = a - 1;


	return 0;
}