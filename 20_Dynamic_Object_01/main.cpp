#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Monster {
public:
    string _name;
    int _health;
    int _attack;
    int _defense;

public:
    Monster() // 기본생성자
        : _name(""), _health(0), _attack(0), _defense(0) {
    }

    Monster(string name, int health, int attack, int defense)   // 인자를 받는 생성자
        : _name(name), _health(health), _attack(attack), _defense(defense)
    {
        cout << _name << "생성자" << endl;
    }

    ~Monster() {
        cout << _name << "소멸자" << endl;
    }

    void Attack() {
        //cout << _name << "이 공격한다." << endl;
        cout << _attack << "공격한다." << endl;
    }

    void Defense() {
        cout << _name << "이 방어한다." << endl;
    }

    void Info() {
        cout << "몬스터명: " << this->_name << endl;
        cout << "생명력: " << _health << endl;
        cout << "공격력: " << _attack << endl;
        cout << "방어력: " << _defense << endl;
    }

};

int main() {
    // C는 malloc, calloc, realloc이라는 동적메모리 할당 함수를 사용
    int* pa = (int*)malloc(sizeof(int));

    *pa = 300;

    cout << "pa = " << pa << endl; // 할당된 동적메모리 공간의 주소값을 출력
    cout << "*pa = " << *pa << endl;   // 동적메모리공간에 저장된 값을 출력

    free(pa); // 할당된 동적메모리 공간을 할당해제.
    pa = NULL; // 반납처리한 주소값을 NULL로 초기화 하는 것이 좋습니다.
    free(pa);

    // C++에서는 new 연산자로 동적메모리 공간을 할당.
    pa = new int; // new 연산자를 사용해서 int 형 동적메모리 공간을 할당

    *pa = 2342;

    cout << "pa = " << pa << endl;
    cout << "*pa = " << *pa << endl;

    delete pa; // 반납처리 

    // 객체를 동적으로 할당할때는 반드시 new 연산자를 사용해야 합니다.
    // new 연산자를 사용해서 객체를 할당해야만 생성자를 호출하여
    // 온전한 객체로 생성할 수 있습니다.

    Monster* pmons = new Monster("드래곤", 100, 30, 20);   // 인자를 받는 생성자가 호출.

    pmons->Attack();
    cout << endl;
    pmons->Defense();
    cout << endl;
    pmons->Info();

    delete pmons;   // 객체는 delete연산자로 반납처리 해야 합니다. 
    //  delete 연산자는 객체를 반납처리할때 소멸자를 호출 시켜 줍니다.
    cout << endl;

    pmons = new Monster();   // 기본생성자가 호출 되면서 동적객체 생성.
    pmons->Info();

    delete pmons;





    return 0;
}