#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

// C++에서 구조체 타입은 클래스로 구현이 됩니다.
// default가 public 입니다.
struct Student {
    string _name;
    int _grade;
    int _classNum;

    Student() {}
    Student(string name, int grade, int classNum)
        : _name(name), _grade(grade), _classNum(classNum) {
    }

};


class Sort {
public:
    virtual bool operator()(Student& left, Student& right) = 0;
};

class Ascending : public Sort {
public:
    bool operator()(Student& left, Student& right) {
        if (left._grade > right._grade) {
            return true;
        }
        else {
            return false;
        }
    }
};

class Decending : public Sort {
public:
    bool operator()(Student& left, Student& right) {
        if (left._grade < right._grade) {
            return true;
        }
        else {
            return false;
        }
    }
};

class DynamicArray {
private:
    int _size;
    Student* _parr;

public:
    DynamicArray(int size)
        : _size(size)
    {
        _parr = new Student[_size];
    }

    ~DynamicArray() {
        delete[] _parr;
    }

    int GetSize() {
        return _size;
    }

    Student& operator[](int index) {
        return _parr[index];
    }

    // 정렬
    void Sort(Sort& comp) {
        for (int i = 0; i < _size - 1; i++) {
            for (int j = 0; j < _size - (i + 1); j++) {
                if (comp(_parr[j], _parr[j + 1])) {
                    Student temp = _parr[j];
                    _parr[j] = _parr[j + 1];
                    _parr[j + 1] = temp;
                }
            }
        }
    }

    friend ostream& operator<<(ostream& o, DynamicArray& ref);
};

ostream& operator<<(ostream& o, DynamicArray& ref) {
    for (int i = 0; i < ref._size; i++) {
        o << "이름: " << ref[i]._name << ", 학년: " << ref[i]._grade << ", 반: " << ref[i]._classNum << endl;
    }

    return o;
}

void InputStudent(Student& ref) {
    static int num = 0;
    char buff[30];

    sprintf(buff, "monster_%d", num++);
    ref._name = buff;
    ref._grade = rand() % 6 + 1;
    ref._classNum = rand() % 11 + 1;
}


void PrintStudent(Student& ref) {
    cout << "이름: " << ref._name << endl;
    cout << "학년: " << ref._grade << endl;
    cout << "반: " << ref._classNum << endl;
    cout << endl;
}

int main() {
    srand(time(NULL));   // 현재 시간으로 랜덤 씨드값 생성
    DynamicArray array(30);
    Student starray[30];

    int length = sizeof(starray) / sizeof(starray[0]);


    for (int i = 0; i < length; i++) {
        InputStudent(starray[i]);
    }

    for (int i = 0; i < length; i++) {
        PrintStudent(starray[i]);
    }


    // DynamicArray 클래스를 수정해서 Student배열의 값을 DynamicArray에 
    // 저장을 하고 DynamicArray객체를 이용해서 grade를 기준으로 정렬한 후에 출력
    // 해보세요...

    for (int i = 0; i < array.GetSize(); i++)
    {
        array[i] = starray[i];
    }

    cout << array << endl;

    Ascending ascending;

    array.Sort(ascending);

    cout << array << endl;

}