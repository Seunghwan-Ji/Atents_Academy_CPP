#include <iostream>

using namespace std;

// 참조형 멤버변수
// 상수형 멤버변수

int main() {
	// 상수형 변수
	100; // 상수(constant)
	200;

	int sum;

	sum = 100;
	sum = 200;

	// 변수를 상수성을 띄도록 할 수 가 있습니다.
	// 변수에 저장된 값을 변경하지 못하도록 할 수가 있습니다.
	// 변수를 만들때 변수의 정의앞에 const 키워드를 사용하면
	// 변수가 상수성 띄게 됩니다.
	// 상수형 변수는 변수를 만듦과 동시에 초기화가 되어야 합니다.
	const int MAX = 400; // 상수형변수

	//MAX = 400; // MAX는 상수형 변수여서 저장하고 있는 값을 변경할 수 없습니다.

	// 참조형변수
	int a = 1000;
	int b = 2000;

	// 참조형 변수를 만들때 만듦과 동시에 초기화를 해야 합니다.
	// a변수의 별칭인 refa가 만들었다.
	int& refa = a; // a변수를 참조하는 refa 변수를 만듦



	refa = 4000;

	cout << "a = " << a << endl;
	cout << "refa = " << refa << endl;

	cout << "&a = " << &a << endl;
	cout << "&refa = " << &refa << endl;

	// 포인터변수
	int* pa;

	pa = &a;

	cout << "before a = " << a << endl;
	cout << "before *pa = " << *pa << endl;

	*pa = 60000;

	cout << endl;
	cout << "after a = " << a << endl;
	cout << "before *pa = " << *pa << endl;


	pa = &b;

	cout << "before a = " << a << endl;
	cout << "before *pa = " << *pa << endl;
	cout << "before b = " << b << endl;

	*pa = 23456;

	cout << "after a = " << a << endl;
	cout << "after *pa = " << *pa << endl;
	cout << "after b = " << b << endl;

	// 참조형변수와 포인터형변수는 내부적인 작동방법은 동일합니다.
	// 참조형변수는 초기값으로 전달된 변수의 주소값을 변경할 수 없습니다.
	// 참조형변수는 생성될때 전달된 변수의 메모리공간만 가리키게 됩니다.



	return 0;
}