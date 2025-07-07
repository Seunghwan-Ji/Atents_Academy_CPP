#include <iostream>

using namespace std;

int main() {
	// 아래 만들어진 변수에 각 변수의 데이타 타입의
	// 경계값을 입력하시고 출력해보세요..
	// 
	// 정수형
	short a;
	a = -32768;
	cout << "a = " << a << endl;

	long b;
	b = -2147483647 - 1;
	cout << "b = " << b << endl;

	int c;
	c = -2147483647 - 1;
	cout << "c = " << c << endl;

	unsigned short d;
	d = 65535;
	cout << "d = " << d << endl;

	unsigned long e;
	e = 4294967295;
	cout << "e = " << e << endl;

	unsigned int f;
	f = 4294967295;
	cout << "f = " << f << endl;

	// 실수형
	float g;
	g = -3.4e-38f;
	printf("g = %f\n", g);
	cout << fixed; // 출력시 고정소수점수로 표기하도록 설정하는 함수.
	cout.precision(200); // 소수점 200번째 자리까지.
	cout << "g = " << g << endl;

	double h;
	h = -1.79769e+308;
	cout << "h = " << h << endl;

	// 문자형
	char i;
	i = 100;
	cout << "i = " << i << endl;

	unsigned char j;
	j = 101;
	cout << "j = " << j << endl;
	
	// 출력 printf 함수 사용
	// 형식 지정문자열
	int ab = 20;
	int cb = 30;
	// %d 부호있는 정수형 출력
	cout << "ab = " << ab << ", cb = " << cb << endl;
	//printf("ab = %d, cb = %d\n", ab, cb);

	float dd = 1.3f;
	double ee = 3.4;
	// %f(float), %lf(double)
	//printf("dd = %f, ee = %lf\n", dd, ee);
	cout << "dd = " << dd << ", ee = " << ee << endl;

	// 문자형
	char AA = 65;
	unsigned char BB = 66;
	//printf("AA = %c, BB = %c\n", AA, BB);
	cout << "AA = " << AA << ", BB = " << BB << endl;


	return 0;
}