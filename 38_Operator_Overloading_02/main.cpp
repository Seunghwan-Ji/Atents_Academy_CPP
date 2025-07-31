#include <iostream>

using namespace std;

class DynamicArray
{
private:
    int* _parr;
    int _size;

public:
    DynamicArray(int size)
        : _size(size)
    {
        cout << "인자를 받는 생성자" << endl;
        _parr = new int[_size];
        cout << "_parr = " << _parr << endl;
    }

    // 깊은 복사를 해야 하는 경우에는
    // 기본적으로 제공되어지는 = (대입연산자)를 사용하면 문제가 발생할 수 있습니다.
    // 대입 연산자 오버로딩을 해야 합니다.
    DynamicArray& operator=(DynamicArray& right)
    {
        // 기존의 동적배열을 반납처리
        delete[] _parr;

        _size = right._size;

        // 동적배열을 다시 생성
        _parr = new int[_size];   // 인자로 들어온 right와 동일한 size의 동적메모리 공간을 만듦

        // right의 동적배열에 있는 값을 복사
        for (int i = 0; i < _size; i++)
        {
            _parr[i] = right._parr[i];
        }

        return *this;
    }

    // 배열 첨자 연산자를 연산자 오버로딩
    int& operator[](int index)
    {
        return _parr[index];
    }

    ~DynamicArray()
    {
        delete[] _parr;
    }

    int GetSize()
    {
        return _size;
    }
};

int main() {
    DynamicArray array(20);
    DynamicArray array2(10);
    DynamicArray array3(30);

    for (int i = 0; i < array2.GetSize(); i++)
    {
        array2[i] = i;
        //array.operator[](i) = i;
    }

    array = array2;

    cout << endl;
    for (int i = 0; i < array.GetSize(); i++)
    {
        cout << "array[" << i << "] = " << array[i] << endl;
    }

    cout << endl;

    for (int i = 0; i < array2.GetSize(); i++)
    {
        cout << "array2[" << i << "] = " << array2[i] << endl;
    }



    //array3 = array = array2;


    return 0;
}