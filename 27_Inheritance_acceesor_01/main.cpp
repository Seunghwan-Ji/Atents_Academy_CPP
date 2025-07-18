#include <iostream>

using namespace std;


// 상속관계에서의 접근제어자


class A
{
public:
    int _value;
    int _value2;

public:
    A()
        : _value(0)
        , _value2(0)
    {
    }
    A(int value, int value2)
        : _value(value)
        , _value2(value2) 
    {
    }
};

class B : public A // public 을 private 또는 Protected 로 바꾸고 아래 코드에서 접근 여부를 확인해보자.
{
public:
    int _value3;
    int _value4;

public:
    B()
        : A(0, 0)
        , _value3(0)
        , _value4(0)
    {
    }

    B(int value, int value2, int value3, int value4)
        : A(value, value2)
        , _value3(value3)
        , _value4(value4)
    {
    }

    void Info()
    {
        cout << "A::_value = " << _value << endl;
        cout << "A::_value2 = " << _value2 << endl;
        cout << "B::_value3 = " << _value3 << endl;
        cout << "B::_value4 = " << _value4 << endl;
    }
};

class C : public B
{
public:
    void Info()
    {
        cout << "A::_value = " << _value << endl;
        cout << "A::_value2 = " << _value2 << endl;
        cout << "B::_value3 = " << _value3 << endl;
        cout << "B::_value4 = " << _value4 << endl;
    }
};

int main()
{
    A a(100, 200);
    B b(10, 20, 30, 40);

    cout << "a._value = " << a._value << endl;
    cout << "a._valu2 = " << a._value2 << endl;

    b.Info();

    //   cout << "b._value = " << b._value << endl;
    //   cout << "b._value2 = " << b._value2 << endl;
    cout << "b._value3 = " << b._value3 << endl;
    cout << "b._value4 = " << b._value4 << endl;

    return 0;
}