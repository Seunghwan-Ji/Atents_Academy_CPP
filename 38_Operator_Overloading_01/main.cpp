#include <iostream>

using namespace std;

// 복소수 클래스
class Complex {
private:
    int _real;
    int _imaginary;

public:
    Complex(int real, int imaginary)
        : _real(real), _imaginary(imaginary) {
    }

    int GetReal() {
        return _real;
    }

    int GetImaginay() {
        return _imaginary;
    }

    // + 기호에 대한 연산자 오버로딩
    Complex& operator+(Complex& right) {
        Complex temp(_real + right._real, _imaginary + right._imaginary);

        return temp;
    }

    // 관계연산자
    bool operator<(Complex& right) {
        return _real < right._real;
    }

    bool operator>(Complex& right) {
        return _real > right._real;
    }

    bool operator==(Complex& right) {
        return _real == right._real;
    }

    bool operator!=(Complex& right) {
        return _real != right._real;
    }


    void Info() {
        cout << _real << showpos << _imaginary << "i";
        cout << noshowpos;
    }
};

// 기본 연산자는 기본 DataType의 연산 방법만을 제공합니다.
// 
// C++ 언어에서는 사용자만든 클래스형 DataType에 연산기호를 사용하는
// 방법을 제공하고 있습니다.
// 이것을 연산자 오버로딩(operator overloading)이라고 합니다.

// 연산자오버로딩을 할때 권고사항
// 기본 연산자기호의 인식범위를 벗어나지 말것.
// + 기호를 가지고 뺄셈 처리를 하지 마라.

int main() {
    Complex a(10, 10);
    Complex b(12, 12);
    Complex c(0, 0);

    a.Info();
    cout << endl;
    b.Info();
    cout << endl;

    c = a + b;
    //c = a.operator+(b);

    c.Info();
    cout << endl;

    bool ret = a < b;
    //ret = a.operator<(b);
    cout << "a < b = " << ret << endl;

    ret = a == b;
    //ret = a.operator==(b);
    cout << "a == b = " << ret << endl;


    return 0;
}