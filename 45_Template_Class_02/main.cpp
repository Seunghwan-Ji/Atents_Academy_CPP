#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Student {
    string name;
    int age;
    int grade;
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
};

template<>
class DynamicArray<float*> {
private:
    int _size;
    float** _parr;

};

template <typename T>
ostream& operator<<(ostream& o, DynamicArray<T>& right) {
    for (int i = 0; i < right.GetSize(); i++) {
        o << right[i] << ", ";
    }

    return o;
}

// 템플릿 특수화: 템플릿을 특정 타입에 대해 다르게 구현하는 것
template<> // Student 타입에 대한 특수화.
ostream& operator<<(ostream& o, DynamicArray<Student>& right) {
    for (int i = 0; i < right.GetSize(); i++) {
        o << "나이: " << right[i].age << ", 학년: " << right[i].grade << ", 이름: " << right[i].name << endl;
    }

    return o;
}


int main() {
    srand(time(NULL)); // 랜덤 씨드값 생성
    DynamicArray<int> array(10);

    for (int i = 0; i < array.GetSize(); i++) {
        array[i] = i;
    }

    cout << array << endl;

    DynamicArray<float> floatArray(10);

    for (int i = 0; i < floatArray.GetSize(); i++) {
        floatArray[i] = i * 1.3f;
    }

    cout << floatArray << endl;


    DynamicArray<Student> stArray(10);

    char buff[100];

    for (int i = 0; i < stArray.GetSize(); i++) {
        sprintf(buff, "monster_%d", i);
        stArray[i].age = rand() % 10 + 5;
        stArray[i].grade = rand() % 3 + 1;
        stArray[i].name = buff;
    }


    cout << stArray << endl;




    return 0;
}