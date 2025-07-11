#include <iostream>

using namespace std;

// 프로그램 전반적으로 사용되어지는 Data를 쉽게 접근하게
// 하기위해서 정적멤버를 사용합니다.
class Global {
private:
    static int Score;
    static int volume;

public:
    static void SetVolume(int value) {
        volume = value;
    }

    static int GetVolume() {
        return volume;
    }
};

class Utility {
public:
    static float add(int a, int b) {
        return a + b;
    }

    static float sub(int a, int b) {
        return a - b;
    }

    static float mul(int a, int b) {
        return a * b;
    }

    static float div(int a, int b) {
        return a / (float)b;
    }
};

class A {
public:
    void SetVolume() {
        Global::GetVolume();

    }


};

class B {
public:
    void SetVolume() {
        Global::SetVolume(20);

    }
};

void func(int volume) {
    B b;

    b.SetVolume();
}

int main() {


    A a;

    a.SetVolume();

    cout << "volume = " << Global::GetVolume() << endl;

    int aa = 20;
    int bb = 30;

    /*
    Utility util;

    cout << aa << " + " << bb << " = " << util.add(aa, bb);
    */

    cout << aa << " + " << bb << " = " << Utility::add(aa, bb) << endl;






    return 0;
}