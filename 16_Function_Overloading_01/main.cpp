#include <iostream>
#include <string>
// 오버로딩 (Overloading)

using namespace std;

// C언어의 경우에는 프로젝트를 통털어서 동일한 이름의 함수가 있을 수 없습니다.
// C++에서는 한 프로젝트안에 동일한 이름의 함수를 사용할 수 있습니다.
// 이것을 오버로딩(Overloading)이라고 합니다.
// 함수 이름은 동일하지만 매개변수의 갯수나 매개변수의 DataType이 달라야 합니다.
// return Type은 함수명에 포함되지 않습니다.

// C++은 함수의 이름을 네이밍할때 네임맹글링이라는 방법을 사용합니다.
// 내부적으로 사용할 함수의 이름에 매개변수의 DataType이나 매개변수의 갯수를 포함시키는 방법입니다.



float add(float a, float b) { // addYY
	return a + b;
}

int add(int a, int b) { // addXX
	return a + b;
}

float add(float a, int b) { // addYX
	return a + (float)b;
}

double add(double a, double b) { // addZZ
	return a + b;
}

string add(string a, string b) { // addSS
	return a + b;
}

int add(int a, int b, int c) { // addXXX
	return a + b + c;
}


int main() {
	int a = 20;
	int b = 30;
	int iret = 0;

	float c = 2.4f;
	float d = 3.4f;
	float fret = 0.0f;

	double e = 10.3;
	double f = 23.4;
	double dret = 0.0;

	string g = "Monster";
	string h = " is World!!";
	string sret = "";

	iret = add(a, b); // call addXX (어셈블리어 호출 명령어)

	//call _add;

	cout << a << " + " << b << " = " << iret << endl;

	fret = add(c, d); // call addYY
	cout << c << " + " << d << " = " << fret << endl;

	dret = add(e, f); // call addZZ
	cout << e << " + " << f << " = " << dret << endl;

	sret = add(g, h); // call addSS
	cout << g << " + " << h << " = " << sret << endl;


	return 0;
}