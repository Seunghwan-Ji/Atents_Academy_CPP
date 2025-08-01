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
        cout << "���ڸ� �޴� ������" << endl;
        _parr = new int[_size];
        cout << "_parr = " << _parr << endl;
    }

    // �̵�������
    DynamicArray(DynamicArray&& rref)
    {
        cout << "�̵� ������" << endl;

        _parr = rref._parr;
        rref._parr = NULL;
        _size = rref._size;
        cout << "_parr = " << _parr << endl;
    }

    void printParr()
    {
        cout << "_parr = " << _parr << endl;
    }


    // ���� ���縦 �ؾ� �ϴ� ��쿡��
    // �⺻������ �����Ǿ����� = (���Կ�����)�� ����ϸ� ������ �߻��� �� �ֽ��ϴ�.
    // ���� ������ �����ε��� �ؾ� �մϴ�.
    DynamicArray& operator=(DynamicArray& right)
    {
        // ������ �����迭�� �ݳ�ó��
        delete[] _parr;

        _size = right._size;

        // �����迭�� �ٽ� ����
        _parr = new int[_size];   // ���ڷ� ���� right�� ������ size�� �����޸� ������ ����

        // right�� �����迭�� �ִ� ���� ����
        for (int i = 0; i < _size; i++)
        {
            _parr[i] = right._parr[i];
        }

        return *this;
    }

    // �������� ���ڷ� �޴� ���Կ����� �����ε�
    DynamicArray& operator=(DynamicArray&& rright)
    {
        cout << "DynamicArray& operator=(DynamicArray&& rright)" << endl;
        delete[] _parr; // ���� �ּ��� �޸� �ݳ�.
        _parr = rright._parr; // �������� �ּ� ����.
        rright._parr = NULL; // ���� �������� �ּҴ� ������ ��ü�� �Ҹ��ڿ��� �޸� �ݳ� ó����
        // ���� ���� NULL�� ����
        // (�⺻������ ���� �޸��� �ּҰ��� NULL �̸� �ݳ� ����)

        _size = rright._size;

        cout << "_parr = " << _parr << endl; // ����� �ּҰ� ����غ���.

        return *this;
    }

    // + ������ �����ε�
    DynamicArray operator+(DynamicArray& right)
    {
        cout << "operator+" << endl;
        DynamicArray temp(_size + right._size); // ���ο� ��ü ����.

        // temp ��ü �迭�� �ڽ� ��ü�� ��� ��� ����.
        for (int i = 0; i < _size; i++)
        {
            temp[i] = (*this)[i];
        }

        // temp ��ü �迭 ������ �κп� right ��ü�� ��� ��� ����.
        for (int i = 0; i < right._size; i++)
        {
            temp[i + _size] = right[i];
        }

        return temp;
    }


    // �迭 ÷�� �����ڸ� ������ �����ε�
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

    // ģ�� �Լ��� ����� �ϰ� �Ǹ�
    // ����̵� Ŭ������ private ������ ������ �� �� �ֽ��ϴ�.
    friend ostream& operator<<(ostream& o, DynamicArray& right);
};

// ���� Ÿ���� �����ȣ�� �����ʿ� ���� ��쿡�� 
// �Ϲ��Լ��� ���ؼ� ������ �����ε��� �� �� �ֽ��ϴ�.
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