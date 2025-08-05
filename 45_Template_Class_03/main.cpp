#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Item {
private:
    int _no;
    string _name;
    int _count;

public:
    Item(int no, string name, int count)
        : _no(no), _name(name), _count(count) {
    }

    int GetCount() {
        return _count;
    }

    int GetNo() {
        return _no;
    }

    string GetName() {
        return _name;
    }
};

struct Student {
    string name;
    int age;
    int grade;
};

template <typename T>
class Sort {
public:
    virtual bool CompareValue(T left, T right) = 0;
    virtual bool operator()(T left, T right) = 0;
};

template <typename T>
class Acending : public Sort<T> {
public:
    bool CompareValue(T left, T right) override {
        if (left > right) {
            return true;
        }
        else {
            return false;
        }
    }

    bool operator()(T left, T right) {
        return left < right;
    }
};

template <typename T>
class Decending : public Sort<T> {
public:
    bool CompareValue(T left, T right) override {
        if (left < right) {
            return true;
        }
        else {
            return false;
        }

    }

    bool operator()(T left, T right) {
        return left < right;
    }
};


template <>
class Acending<Item*> : public Sort<Item*> {
public:
    bool CompareValue(Item* pLeft, Item* pRight) override {
        if (pLeft->GetCount() < pRight->GetCount()) {
            return true;
        }
        else {
            return false;
        }
    }

    bool operator()(Item* pLeft, Item* pRight) {
        return pLeft->GetCount() < pRight->GetCount();
    }

};

template <>
class Decending<Item*> : public Sort<Item*> {
public:
    bool CompareValue(Item* pLeft, Item* pRight) override {
        if (pLeft->GetCount() > pRight->GetCount()) {
            return true;
        }
        else {
            return false;
        }
    }

    bool operator()(Item* pLeft, Item* pRight) {
        return pLeft->GetCount() < pRight->GetCount();
    }

};


// 템플릿 클래스
template <typename T>
class DynamicArray {
private:
    int _size;
    T* _parr;

public:
    DynamicArray(int size)
        : _size(size) {
        _parr = new T[_size];
    }

    ~DynamicArray() {
        delete[] _parr;
    }

    int GetSize() {
        return _size;
    }

    T& operator[](int index) {
        return _parr[index];
    }

    void Sort(Sort<T>& ref) {
        for (int i = 0; i < _size - 1; i++) {
            for (int j = 0; j < _size - (i + 1); j++) {
                if (ref.CompareValue(_parr[j], _parr[j + 1])) {
                    T temp = _parr[j];
                    _parr[j] = _parr[j + 1];
                    _parr[j + 1] = temp;
                }
            }
        }
    }
};

// 템플릿 클래스
template <>
class DynamicArray<Item*> {
private:
    int _size;
    Item** _parr;

public:
    DynamicArray(int size)
        : _size(size) {
        _parr = new Item * [_size];
    }

    ~DynamicArray() {
        cout << "DynamicArray Item 소멸자" << endl;
        for (int i = 0; i < _size; i++) {
            delete _parr[i];
        }
        delete[] _parr;
    }

    int GetSize() {
        return _size;
    }

    Item*& operator[](int index) {
        return _parr[index];
    }

    void Sort(Sort<Item*>& ref) {
        for (int i = 0; i < _size - 1; i++) {
            for (int j = 0; j < _size - (i + 1); j++) {
                if (ref.CompareValue(_parr[j], _parr[j + 1])) {
                    Item* temp = _parr[j];
                    _parr[j] = _parr[j + 1];
                    _parr[j + 1] = temp;
                }
            }
        }
    }
};

template <typename T>
ostream& operator<<(ostream& o, DynamicArray<T>& ref) {
    for (int i = 0; i < ref.GetSize(); i++) {
        o << ref[i] << " ";
    }

    return o;
}


// Student 타입을 출력하는 operator<< 함수를 만들어 보세요...
// 템플릿 특수화
template <>
ostream& operator<<(ostream& o, DynamicArray<Student>& ref) {
    for (int i = 0; i < ref.GetSize(); i++) {
        o << "나이: " << ref[i].age << ", 학년: " << ref[i].grade << ", 이름: " << ref[i].name << endl;
    }

    return o;
}

template<>
ostream& operator<<(ostream& o, DynamicArray<Item*>& ref) {
    for (int i = 0; i < ref.GetSize(); i++) {
        o << "아이템번호: " << ref[i]->GetNo() << ", 아이템이름: " << ref[i]->GetName() << ", 아이템갯수: " << ref[i]->GetCount() << endl;
    }

    return o;

}



int main() {
    srand(time(NULL));   //랜덤 씨드값 생성
    DynamicArray<int> array(10);

    for (int i = 0; i < array.GetSize(); i++) {
        array[i] = rand() % 100;
    }

    cout << "소팅 전 " << endl;
    cout << array << endl;

    cout << "소팅 후 " << endl;
    Acending<int> aSort;
    array.Sort(aSort);
    cout << "오름차순: " << array << endl;

    Decending<int> dSort;
    array.Sort(dSort);
    cout << "내림차순: " << array << endl;


    DynamicArray<Item*> arrayItem(30);

    char buff[30];
    for (int i = 0; i < arrayItem.GetSize(); i++) {
        sprintf(buff, "Item_%d", i);
        arrayItem[i] = new Item(i, buff, rand() % 100);
    }

    // DynamicArray<Item*>을 count를 기준으로 오름차순으로 정렬하고 cout 객체로 출력
    // 해보세요..
    Acending<Item*> aItemSort;
    Decending<Item*> dItemSort;

    cout << "오름차순" << endl;
    arrayItem.Sort(aItemSort);

    cout << arrayItem << endl;

    cout << endl;
    cout << "내림차순" << endl;

    arrayItem.Sort(dItemSort);

    cout << arrayItem << endl;




    return 0;
}