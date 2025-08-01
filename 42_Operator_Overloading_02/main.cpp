#include <iostream>

using namespace std;

// 형변환 연산자 오버로딩


class A {
private:
    int _value;
    int _value2;

public:
    A(int value, int value2)
        : _value(value), _value2(value2) {
    }

    void Info() {
        cout << "_value = " << _value << endl;
        cout << "_value2 = " << _value2 << endl;

    }
};

class Complex {
private:
    int _real;
    int _imaginary;

public:
    Complex(int real, int imaginary)
        : _real(real), _imaginary(imaginary) {
    }

    // explcit을 생성자 앞에 쓰면 이 생성자가지고
    // 묵시적으로 형변환하지 말라는 의미입니다.
    explicit Complex(int real)
        : _real(real), _imaginary(0) {
    }

    Complex(float real) {
        _real = (int)real;
        _imaginary = 0;

    }

    // int형 형변환 연산자
    operator int() {
        return _real;
    }

    // float형 형변환 연산자
    operator float() {
        return (float)_real;
    }

    // A DataType 형변환연산자
    operator A() {
        return A(_real, _imaginary);
    }

    int GetReal() {
        return _real;
    }

    int GetImaginary() {
        return _imaginary;
    }

    friend ostream& operator<<(ostream& o, Complex& ref);
};

ostream& operator<<(ostream& o, Complex& ref) {
    o << ref._real << showpos << ref._imaginary << "i";

    o << noshowpos;

    return o;
}


int main() {
    Complex a(10, 10);
    Complex c(0, 0);


    //a = 1; // 묵시적형변환

    a = Complex(1); // 명시적형변환

    cout << "a = " << a << endl;

    a = 3.23f;

    a = Complex(3.23f);

    cout << "a = " << a << endl;

    int e = 0;

    e = a;

    e = (int)a;

    float h = 0.0f;

    h = (float)a;


    A g(0, 0);

    g = (A)a;

    g.Info();

    return 0;
}