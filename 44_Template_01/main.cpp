#include <iostream>
#include <string>

using namespace std;

// DataType에 일반화한 프로그래밍 환경을 제공. (일반화 프로그래밍, generic programming)
// C++에서는 Template으로 제공.

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

    int GetImaginary() {
        return _imaginary;
    }

    Complex operator+(Complex& right)
    {
        Complex temp(_real + right._real, _imaginary + right._imaginary);

        return temp; // 함수가 종료되면 temp 객체는 사라지므로 참조형이 아닌 일반 타입으로 반환.
    }

    bool operator>(Complex& right)
    {
        return _real > right._real;
    }
};


ostream& operator<<(ostream& o, Complex& ref) {
    o << ref.GetReal() << showpos << ref.GetImaginary() << "i";
    o << noshowpos;

    return o;
}

// 템플릿 함수  (T형에 치환되는 함수의 틀을 제공)
template <typename T>
T add(T a, T b) {
    cout << "T add(T a, T b)" << endl;
    return a + b;
}

template <typename T, typename T2>
T2 add(T a, T2 b) {
    cout << "T2 add(T a, T2 b)" << endl;
    return a + b;
}

template <typename T>
T Max(T& a, T& b) // 객체가 들어올 수 있기 때문에 인수를 래퍼런스형으로 받는다.
{
    return a > b ? a : b;
}

/*
int add(int a, int b) {
   return a + b;
}

float add(float a, float b) {
   return a + b;
}

double add(double a, double b) {
   return a + b;
}

string add(string a, string b) {
   return a + b;
}
*/

int main() {
    int a = 20;
    int b = 30;

    float c = 1.3f;
    float d = 10.4f;

    double e = 30.33;
    double f = 22.456;

    string str1 = "monster";
    string str2 = " is World!!";

    cout << a << " + " << b << " = " << add(a, b) << endl;
    cout << c << " + " << d << " = " << add(c, d) << endl;
    cout << e << " + " << f << " = " << add(e, f) << endl;
    cout << str1 << " + " << str2 << " = " << add(str1, str2) << endl;

    cout << a << " + " << c << " = " << add(a, c) << endl;


    Complex ca(10, 10);
    Complex cb(20, 30);
    Complex cc(0, 0);


    // 문제 1.
    // Complex 타입이 add 함수에 작동할 수 있도록 Complex 클래스를 완성하세요.
    cc = add(ca, cb);

    cout << ca << " + " << cb << " = " << cc << endl;


    // 문제 2.
    // 두값을 비교해서 큰값을 리턴하는 템플릿함수 Max를 만드시고 
    // 아래의 코드가 작동하도록 하세요..
    cout << a << "와 " << b << "중에 큰값은 " << Max(a, b) << endl;
    cout << c << "와 " << d << "중에 큰값은 " << Max(c, d) << endl;
    cout << e << "와 " << f << "중에 큰값은 " << Max(e, f) << endl;


    // extra.
    cc = Max(ca, cb);
    
    cout << "큰수는 " << cc << endl;






    return 0;
}