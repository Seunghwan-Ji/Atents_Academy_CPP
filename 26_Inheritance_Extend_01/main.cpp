#include <iostream>
#include "Math.h"

using namespace std;

// 기존 클래스의 기능 확장.

class ExtMath : public Math {
public:
	float div(float a, float b) {
		return a / b;
	}
};


int main() {
	float a = 30.4f;
	float b = 12.56f;
	

	cout << "Math" << endl;
	Math math;

	cout << a << " + " << b << " = " << math.add(a, b) << endl;
	cout << a << " - " << b << " = " << math.sub(a, b) << endl;
	cout << a << " x " << b << " = " << math.mul(a, b) << endl;

	cout << endl;

	cout << "ExtMath" << endl;
	ExtMath extMath;

	cout << a << " + " << b << " = " << extMath.add(a, b) << endl;
	cout << a << " - " << b << " = " << extMath.sub(a, b) << endl;
	cout << a << " x " << b << " = " << extMath.mul(a, b) << endl;
	cout << a << " / " << b << " = " << extMath.div(a, b) << endl;


	return 0;
}