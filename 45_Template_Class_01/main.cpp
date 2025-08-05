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

// ÅÛÇÃ¸´ Å¬·¡½º
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


int main() {
    srand(time(NULL)); // ·£´ý ¾¾µå°ª »ý¼º
    DynamicArray<int> array(10);

    for (int i = 0; i < array.GetSize(); i++) {
        array[i] = i;
    }

    for (int i = 0; i < array.GetSize(); i++) {
        cout << "array[" << i << "] = " << array[i] << endl;
    }


    DynamicArray<float> floatArray(10);

    for (int i = 0; i < floatArray.GetSize(); i++) {
        floatArray[i] = i * 1.3f;
    }

    for (int i = 0; i < floatArray.GetSize(); i++) {
        cout << "floatArray[" << i << "] = " << floatArray[i] << endl;
    }


    DynamicArray<Student> stArray(10);

    char buff[100];

    for (int i = 0; i < stArray.GetSize(); i++) {
        sprintf(buff, "monster_%d", i);
        stArray[i].age = rand() % 10 + 5;
        stArray[i].grade = rand() % 3 + 1;
        stArray[i].name = buff;
    }







    return 0;
}