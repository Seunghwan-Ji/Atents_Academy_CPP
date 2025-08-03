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

    DynamicArray& operator=(DynamicArray& right)
    {
        delete[] _parr;

        _size = right._size;

        _parr = new int[_size];
                
        for (int i = 0; i < _size; i++)
        {
            _parr[i] = right._parr[i];
        }

        return *this;
    }
        
    DynamicArray& operator=(DynamicArray&& rright)
    {
        cout << "DynamicArray& operator=(DynamicArray&& rright)" << endl;
        delete[] _parr;
        _parr = rright._parr;
        rright._parr = NULL;

        _size = rright._size;

        cout << "_parr = " << _parr << endl;

        return *this;
    }

    DynamicArray operator+(DynamicArray& right)
    {
        cout << "operator+" << endl;
        DynamicArray temp(_size + right._size);

        for (int i = 0; i < _size; i++)
        {
            temp[i] = (*this)[i];
        }

        for (int i = 0; i < right._size; i++)
        {
            temp[i + _size] = right[i];
        }

        return temp;
    }


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

    // 친구 함수로 등록을 하게 되면
    // 등록이된 클래스의 private 영역에 접근을 할 수 있습니다.
    friend ostream& operator<<(ostream& o, DynamicArray& right);
};

// 만든 타입이 연산기호의 오른쪽에 오는 경우에는 
// 일반함수를 통해서 연산자 오버로딩을 할 수 있습니다.
ostream& operator<<(ostream& o, DynamicArray& right)
{
    for (int i = 0; i < right._size; i++)
    {
        o << right[i] << ", ";
    }

    return o;
}

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

    cout << array3;

    return 0;
}