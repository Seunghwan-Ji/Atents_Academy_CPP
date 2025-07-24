#include <iostream>

using namespace std;

class Parent {
public:
    void Print() {   // 일반멤버함수
        cout << "Parent::Print()" << endl;
    }

    virtual void VPrint1() {   // 가상함수
        cout << "Parent::VPrint1()" << endl;
    }

    virtual void VPrint2() {   // 가상함수
        cout << "Parent::VPrint2()" << endl;
    }

    virtual void VPrint3() {   // 가상함수
        cout << "Parent::VPrint3()" << endl;
    }
};

class Child1 : public Parent {
public:
    void Print() {
        cout << "Child1::Print()" << endl;
    }

    void VPrint1() override {
        cout << "Child1::VPrint1()" << endl;
    }
};

class Child2 : public Parent {
public:
    void Print() {
        cout << "Child2::Print()" << endl;
    }

    void VPrint2() override {
        cout << "Child2::VPrint2()" << endl;
    }
};

class Child3 : public Parent {
public:
    void VPrint3() override {
        cout << "Child3::VPrint3()" << endl;
    }
};

// 일반멤버함수 호출
void FuncPrint(Parent& ref) {
    ref.Print();
    //ref.Parent::Print(); // 정적바인딩 (컴파일타임에 어디에 함수를 호출할지 결정하는 것)

}

void FuncPrint(Child1& ref) {
    ref.Print();
    //ref.Child1::Print(); // 정적바인딩

}

void FuncPrint(Child3& ref) {
    ref.Print();
    //ref.Parent::Print(); // 정적바인딩

}

// 가상함수 호출
void FuncVPrint1(Parent& ref) {
    ref.VPrint1(); // 동적바인딩 (실행할때 어떤함수를 호출할지 결정하느 것)
    // 가상함수는 참조형 매개변수에 들어온 타입에 준해서 작동을 합니다.
    // 실행파일을 만들때 어디에 가상함수가 호출 될지 결정할 수가 없습니다.
    // 결정을 유보합니다.
    // 실행중에 어느 타입의 가상함수가 호출될지 결정하는 것 동적바인딩.

       // 가상함수테이블은 가상함수의 주소값을 저장하고 있음.
    // ref.__vfptr[0]();   // _vfptr은 가상함수 테이블의 주소값을 저장하고 있음.
}

// 가상함수 호출
void FuncVPrint2(Parent& ref) {
    ref.VPrint2();
    // ref.__vfptr[1]();

}

int main() {
    Parent parent;
    Child1 child1;
    Child2 child2;
    Child3 child3;

    // 일반멤버함수호출
    cout << "일반멤버함수 Call FuncPrint" << endl;
    FuncPrint(parent);
    FuncPrint(child1);
    FuncPrint(child2);
    FuncPrint(child3);
    cout << endl;
    cout << endl;

    // 가상멤버함수 호출
    cout << "가상멤버함수 Call FuncVPrint1" << endl;
    FuncVPrint1(parent);
    FuncVPrint1(child1);
    FuncVPrint1(child2);
    FuncVPrint1(child3);
    cout << endl;
    cout << endl;

    cout << "가상멤버함수 Call FuncVPrint2" << endl;
    FuncVPrint2(parent);
    FuncVPrint2(child1);
    FuncVPrint2(child2);
    FuncVPrint2(child3);

    return 0;
}