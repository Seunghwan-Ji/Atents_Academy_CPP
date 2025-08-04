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

    // ����
    // ��������
    void Sort(bool isDesend) {
        for (int i = 0; i < _size - 1; i++) {
            for (int j = 0; j < _size - (i + 1); j++) {

                if (isDesend) { // ���� ����
                    if (_parr[j] > _parr[j + 1]) {
                        int temp = _parr[j];
                        _parr[j] = _parr[j + 1];
                        _parr[j + 1] = temp;
                    }

                }
                else { // ���� ����
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
    srand(time(NULL));   // ���� �ð����� ���� ���尪 ����
    DynamicArray array(30);

    for (int i = 0; i < array.GetSize(); i++) {
        array[i] = rand() % 100; // 0 ~ 99
    }


    cout << "���� ��: " << array << endl;

    array.Sort(false);

    cout << "���� ��: " << array << endl;





    return 0;
}