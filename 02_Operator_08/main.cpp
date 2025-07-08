#include <iostream>

using namespace std;

int main() {
	int a;
	int b = 30;
	float c = 3.4f;

	a = 20;

	// 기본 데이타 타입간에는 컴파일러가 자동으로 형변환을 시켜버립니다.
	// 묵시적형변환
	a = c;

	// 실수값을 정수형 변수에 대입할때는
	// 명시적형변환을 해야합니다.
	a = (int)c;   // 명시적형변환

	c = b;   // 정수값을 실수형 변수에 대입할때는 묵시적 형변환을 해도 됩니다.

	// 축약형
	a += 1;
	// a = a + 1;

	a += b;
	// a = a + b;

	a /= b;
	// a = a / b;



	return 0;
}