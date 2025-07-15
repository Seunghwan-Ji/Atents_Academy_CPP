#include <iostream>

using namespace std;
// 기본생성자 (인자를 받지 않는 생성자)
// 인자를 받는 생성자
// 복사생성자 (자신의 타입을 인자로 받는 생성자
// 복사 생성자는 만들지 않으면 컴파일러 자동으로 만들어 줍니다.

class Complex
{
private:
	int _real;
	int _imaginary;

public:
	Complex(int real, int imaginary)
		: _real(real)
		, _imaginary(imaginary)
	{
		cout << "인자를 받는 생성자" << endl;
	}

	Complex(Complex& ref) // 복사 생성자
		: _real(ref._real)
		, _imaginary(ref._imaginary)
	{
		cout << "복사 생성자" << endl;
	}

	int GetReal() {
		return _real;
	}

	int GetImaginary() {
		return _imaginary;
	}

	void Info() {
		cout << _real << showpos << _imaginary << "i";
		cout << noshowpos;
	}
};

int main()
{
	Complex a(10, -10);
	a.Info();

	cout << endl;

	Complex b(a); // 자신의 타입을 인자로 받는 생성자를 복사 생성자라고 합니다.
	// Complex b = a; 이 식과 같은 표현입니다.
	b.Info();

	return 0;
}