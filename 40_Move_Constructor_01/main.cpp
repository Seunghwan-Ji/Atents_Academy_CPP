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

    // 이동생성자
    DynamicArray(DynamicArray&& rref)
    {
        cout << "이동 생성자" << endl;

        _parr = rref._parr;
        rref._parr = NULL;
        _size = rref._size;
        cout << "_parr = " << _parr << endl;
    }

    void printParr()
    {
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

    // 우측값을 인자로 받는 대입연산자 오버로딩
    DynamicArray& operator=(DynamicArray&& rright)
    {
        cout << "DynamicArray& operator=(DynamicArray&& rright)" << endl;
        delete[] _parr; // 기존 주소의 메모리 반납.
        _parr = rright._parr; // 우측값의 주소 복사.
        rright._parr = NULL; // 원본 우측값의 주소는 우측값 객체의 소멸자에서 메모리 반납 처리를
                             // 막기 위해 NULL로 변경
                             // (기본적으로 동적 메모리의 주소값이 NULL 이면 반납 안함)

        _size = rright._size;

        cout << "_parr = " << _parr << endl; // 복사된 주소값 출력해보기.

        return *this;
    }

    // + 연산자 오버로딩
    DynamicArray operator+(DynamicArray& right)
    {
        cout << "operator+" << endl;
        DynamicArray temp(_size + right._size); // 새로운 객체 생성.

        // temp 객체 배열에 자신 객체의 모든 요소 복사.
        for (int i = 0; i < _size; i++)
        {
            temp[i] = (*this)[i];
        }

        // temp 객체 배열 나머지 부분에 right 객체의 모든 요소 복사.
        for (int i = 0; i < right._size; i++)
        {
            temp[i + _size] = right[i];
        }

        return temp;
        // temp -> temp2(시스템 내부적으로 만들어짐) -> array3
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

int main()
{
    DynamicArray array(20);
    DynamicArray array2(10);
    DynamicArray array3(30);

    for (int i = 0; i < array.GetSize(); i++)
    {
        array[i] = i;
    }

    for (int i = 0; i < array2.GetSize(); i++)
    {
        array2[i] = i + array.GetSize();
    }

    array3 = array + array2;

    array3.printParr();

    return 0;
}