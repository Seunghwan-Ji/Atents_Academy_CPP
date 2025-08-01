#include <iostream>

using namespace std;

//Functor : 객체를 함수형식으로 사용하는 것

class Add {
public:
    float operator()(float a, float b) {
        return a + b;
    }

    int operator()(int a, int b) {
        return a + b;
    }

    int operator()(int a, int b, int c) {
        return a + b + c;
    }

    double operator()(double a, double b) {
        return a + b;
    }
};



int main() {
    int a = 20;
    int b = 30;
    int c = 40;

    float e = 3.4f;
    float f = 5.9f;

    double g = 102.123;
    double h = 34.567;

    Add add;

    cout << a << " + " << b << " = " << add(a, b) << endl;
    //cout << a << " + " << b << " = " << add.operator()(a, b) << endl;
    cout << a << " + " << b << " + " << c << " = " << add(a, b, c) << endl;
    cout << e << " + " << f << " = " << add(e, f) << endl;
    cout << g << " + " << h << " = " << add(g, h) << endl;




    return 0;
}