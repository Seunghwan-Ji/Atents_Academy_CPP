#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

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
    virtual bool operator()(int left, int right) = 0;
};

class Ascending : public Sort {
public:
    bool operator()(int left, int right) {
        if (left > right) {
            return true;
        }
        else {
            return false;
        }
    }
};


class Decending : public Sort {
public:
    bool operator()(int left, int right) {
        if (left < right) {
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
    int* _parr;

public:
    DynamicArray(int size)
        : _size(size)
    {
        _parr = new int[_size];
    }

    ~DynamicArray() {
        delete[] _parr;
    }

    int GetSize() {
        return _size;
    }

    int& operator[](int index) {
        return _parr[index];
    }

    // 정렬
    // 버블정렬
    void Sort(Sort& comp) {
        for (int i = 0; i < _size - 1; i++) {
            for (int j = 0; j < _size - (i + 1); j++) {

                if (comp(_parr[j], _parr[j + 1])) {
                    int temp = _parr[j];
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
        o << ref[i] << ", ";
    }

    return o;
}



int main() {
    srand(time(NULL));   // 현재 시간으로 랜덤 씨드값 생성
    DynamicArray array(30);

    Ascending ascend;
    Decending dcend;

    for (int i = 0; i < array.GetSize(); i++) {
        array[i] = rand() % 100; // 0 ~ 99
    }



    cout << "정렬 전: " << array << endl;

    cout << "내림 차순" << endl;
    array.Sort(ascend);

    cout << "정렬 후: " << array << endl;


    cout << "올름 차순" << endl;
    array.Sort(dcend);

    cout << "정렬 후: " << array << endl;





    return 0;
}