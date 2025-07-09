#include <iostream>

using namespace std;

// 포인터
// c/c++ 언어에는 메모리 공간상의 주소값을
// 저장하는 DataType을 가지고 있습니다.
// 이 DataType을 포인터형 이라고 합니다.


int main() {
	int a = 20;


	cout << "&a = " << &a << endl;

	int* pa = &a; // 포인터형지정자

	int** ppa = &pa;


	**ppa; // 포인터 연산자 : 주소값에 사용하는 연산자로 해당 주소값에 할당 받은 공간을 의미합니다.
	**&pa;
	*pa;
	*&a;
	a;

	cout << "&**ppa = " << &**ppa << endl;
	cout << "&**&pa = " << &**&pa << endl;
	cout << "&*pa = " << &*pa << endl;
	cout << "&*&a = " << &*&a << endl;
	cout << "&a = " << &a << endl;

	cout << endl;
	**ppa = 4000;


	cout << "**ppa = " << **ppa << endl;
	cout << "**&pa = " << **&pa << endl;
	cout << "*pa = " << *pa << endl;
	cout << "*&a = " << *&a << endl;
	cout << "a = " << a << endl;





	return 0;
}