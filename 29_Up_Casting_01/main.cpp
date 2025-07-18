#include <iostream>

using namespace std;

// UpCasting , DownCasting
// UpCasting : 상속관계에서 부모의 DataType으로 자식을 받는 것

class Parent {
public:
    int _pvalue;

public:
    Parent()
        : _pvalue(0) {
    }

    Parent(int pvalue)
        : _pvalue(pvalue) {
    }

    void ShowInfo() {
        cout << "Parent::_pvalue = " << _pvalue << endl;
    }
};

class Child : public Parent {
public:
    int _cvalue;

public:
    Child()
        : Parent(0), _cvalue(0) {
    }

    Child(int pvalue, int cvalue)
        : Parent(pvalue), _cvalue(cvalue) {
    }

    void ShowInfo() {
        cout << "Child::Parent::_pvalue = " << _pvalue << endl;
        cout << "Child::_cvalue = " << _cvalue << endl;
    }
};

int main() {

    Parent parent(5);

    Child child(10, 20);

    parent.ShowInfo();

    // 상속관계에 있는 DataType 간에는
    // 자식 객체를 부모 객체에 대입을 할 수 있습니다.
    // 자식은 부모의 영역을 가지고 있기 때문에 가능합니다.
    parent = child;

    parent.ShowInfo();

    // 부모객체를 자식객체에 대입할 수 없습니다.
    // 부모는 자식의 영역을 가지고 있지 않기 때문에 값을 채워줄 수가 없습니다.
    //child = parent;

    // 자식객체를 부모객체에 대입을 할 때 자식의 영역은 대입이 되지 않기 때문에
    // 값의 유실이 발생합니다.

    // 자식객체를 부모객체에 대입을 할때는 
    // 값을 대입하지 않고 참조타입이나 포인터 타입으로 대입을 합니다.
    // 부모의 참조타입이나 포인터 타입에 자식의 타입을 대입하는 것을 UpCasting
    cout << endl;
    cout << "UpCasting" << endl;
    cout << "참조타입으로 전달" << endl;
    Parent& refp = child;   // 참조타입
    refp.ShowInfo();

    Child& refc = (Child&)refp;  // DownCasting: 이런 경우에는 다운 캐스팅이 허용이 됩니다.
    refc.ShowInfo();


    cout << endl;
    cout << "포인터 타입으로 전달" << endl;
    Parent* pparent = &child; // 포인터타입 UpCasting

    pparent->ShowInfo();   // pparent가 Paretn* 타입이어서 Parent타입의 ShowInfo 함수가 홏출

    Child* pchild = (Child*)pparent; // DownCasting

    pchild->ShowInfo();


    return 0;
}