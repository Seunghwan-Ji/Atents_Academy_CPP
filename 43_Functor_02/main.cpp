#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;



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
    void Sort(bool isDesend) {
        for (int i = 0; i < _size - 1; i++) {
            for (int j = 0; j < _size - (i + 1); j++) {

                if (isDesend) { // 오름 차순
                    if (_parr[j] > _parr[j + 1]) {
                        int temp = _parr[j];
                        _parr[j] = _parr[j + 1];
                        _parr[j + 1] = temp;
                    }

                }
                else { // 내림 차순
                    if (_parr[j] < _parr[j + 1]) {
                        int temp = _parr[j];
                        _parr[j] = _parr[j + 1];
                        _parr[j + 1] = temp;
                    }

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

    for (int i = 0; i < array.GetSize(); i++) {
        array[i] = rand() % 100; // 0 ~ 99
    }


    cout << "정렬 전: " << array << endl;

    array.Sort(false);

    cout << "정렬 후: " << array << endl;





    return 0;
}