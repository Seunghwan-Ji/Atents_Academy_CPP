#include <iostream>

using namespace std;

// 메모리의 세그먼트 구조
// 코드 영역: 함수..
// 데이터 영역: 전역 변수, 정적 변수..
// 스택 영역: 자동 변수..
// 힙 영역: 동적 변수, 동적 객체..

int global = 0;    // 외부변수, 전역변수

void func(int c) { // 매개변수(parameter) : 로컬변수, 자동변수
	int a;   // 로컬변수, 자동변수


	static int astatic = 20;   // 로컬변수, 정적변수
}


class A {
private:
	int _member;    // 멤버변수
};

int main() {
	int b = 20;


	return 0;
}