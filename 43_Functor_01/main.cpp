#include <iostream>

using namespace std;

//Functor : 객체를 함수형식으로 사용하는 것

class Oper abstract
{
public:
    virtual float operator()(float a, float b) = 0; // 순수가상함수
    virtual int operator()(int a, int b) abstract;   // 순수가상함수
    virtual int operator()(int a, int b, int c) abstract;
    virtual double operator()(double a, double b) abstract;
};

class Add : public Oper
{
public:
    float operator()(float a, float b) override
    {
        return a + b;
    }

    int operator()(int a, int b) override
    {
        return a + b;
    }

    int operator()(int a, int b, int c) override
    {
        return a + b + c;
    }

    double operator()(double a, double b) override
    {
        return a + b;
    }
};

class Sub : public Oper
{
public:
    float operator()(float a, float b) override
    {
        return a - b;
    }

    int operator()(int a, int b) override
    {
        return a - b;
    }

    int operator()(int a, int b, int c) override
    {
        return a - b - c;
    }

    double operator()(double a, double b) override
    {
        return a - b;
    }

};

class Mul : public Oper
{
public:
    float operator()(float a, float b) override
    {
        return a * b;
    }

    int operator()(int a, int b) override
    {
        return a * b;
    }

    int operator()(int a, int b, int c) override
    {
        return a * b * c;
    }

    double operator()(double a, double b) override
    {
        return a * b;
    }

};


class Div : public Oper
{
public:
    float operator()(float a, float b) override
    {
        return a / b;
    }

    int operator()(int a, int b) override
    {
        return a / b;
    }

    int operator()(int a, int b, int c) override
    {
        return a / b / c;
    }

    double operator()(double a, double b) override
    {
        return a / b;
    }

};



int Calculator(Oper& oper, int a, int b)
{
    return oper(a, b);
    //return add.operator()(a, b);
}

float Calculator(Oper& oper, float a, float b)
{
    return oper(a, b);
    //return add.operator()(a, b);
}

int Calculator(Oper& oper, int a, int b, int c)
{
    return oper(a, b, c);
    //return add.operator()(a, b);
}

double Calculator(Oper& oper, double a, double b)
{
    return oper(a, b);
    //return add.operator()(a, b);
}



int main() {
    int a = 20;
    int b = 30;
    int c = 40;

    float e = 3.4f;
    float f = 5.9f;

    double g = 102.123;
    double h = 34.567;

    Add add;
    Sub sub;
    Mul mul;
    Div div;

    cout << a << " + " << b << " = " << add(a, b) << endl;
    //cout << a << " + " << b << " = " << add.operator()(a, b) << endl;
    cout << a << " + " << b << " + " << c << " = " << add(a, b, c) << endl;
    cout << e << " + " << f << " = " << add(e, f) << endl;
    cout << g << " + " << h << " = " << add(g, h) << endl;

    cout << endl;

    cout << a << " + " << b << " = " << Calculator(add, a, b) << endl;
    cout << a << " - " << b << " = " << Calculator(sub, a, b) << endl;
    cout << a << " x " << b << " = " << Calculator(mul, a, b) << endl;
    cout << a << " / " << b << " = " << Calculator(div, a, b) << endl;

    cout << endl;

    cout << a << " + " << b << " + " << c << " = " << Calculator(add, a, b, c) << endl;
    cout << a << " - " << b << " - " << c << " = " << Calculator(sub, a, b, c) << endl;
    cout << a << " x " << b << " x " << c << " = " << Calculator(mul, a, b, c) << endl;
    cout << a << " / " << b << " / " << c << " = " << Calculator(div, a, b, c) << endl;

    cout << endl;

    cout << e << " + " << f << " = " << Calculator(add, e, f) << endl;
    cout << e << " - " << f << " = " << Calculator(sub, e, f) << endl;
    cout << e << " x " << f << " = " << Calculator(mul, e, f) << endl;
    cout << e << " / " << f << " = " << Calculator(div, e, f) << endl;



    return 0;
}