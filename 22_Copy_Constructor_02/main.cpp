#include <iostream>

using namespace std;

class DynamicArray {
private:
    int* _parr;
    int _size;

public:
    DynamicArray(int size)
        : _size(size)
    {
        cout << "DynamicArray(int size) 생성자" << endl;
        _parr = new int[_size]; // 동적배열 생성
    }

    // 얕은 copy (shallow copy)의 경우에는 복사생성자 만들 필요가 없습니다. 
    // 컴파일러가 자동으로 만들어주는 복사 생성자를 사용하면 됩니다.

    // 깊은 copy (deep copy)의 경우에는 복사생성자를 직접 만들어야 합니다.   
    DynamicArray(DynamicArray& ref)   // 복사생성자
        : _size(ref._size)
    {
        cout << "복사생성자 " << endl;
        _parr = new int[_size];

        for (int i = 0; i < _size; i++) { // 인자로 들어온 객체의 동적배열의 값을 복사함.
            _parr[i] = ref._parr[i];
        }

    }


    ~DynamicArray() {
        cout << "~DynamicArray() 소멸자" << endl;
        delete[] _parr;   // 동적배열 반납처리.
    }

    void SetIndex(int index, int value) {
        _parr[index] = value;
    }

    int GetIndex(int index) {
        return _parr[index];
    }

    int GetSize() {
        return _size;
    }
};

int main() {

    DynamicArray array(10);

    for (int i = 0; i < array.GetSize(); i++) {
        array.SetIndex(i, i);
    }

    for (int i = 0; i < array.GetSize(); i++) {
        cout << "array[" << i << "] = " << array.GetIndex(i) << endl;
    }

    cout << "array2" << endl;
    DynamicArray array2(array);
    for (int i = array2.GetSize() - 1; i >= 0; i--) {
        array2.SetIndex(i, array2.GetSize() - i);
    }

    cout << "array 객체의 동적배열 값 출력" << endl;
    for (int i = 0; i < array.GetSize(); i++) {
        cout << "array[" << i << "] = " << array.GetIndex(i) << endl;
    }

    cout << endl;
    cout << "array2 객체의 동적배열 값 출력" << endl;
    for (int i = 0; i < array2.GetSize(); i++) {
        cout << "array2[" << i << "] = " << array2.GetIndex(i) << endl;
    }

    return 0;
}