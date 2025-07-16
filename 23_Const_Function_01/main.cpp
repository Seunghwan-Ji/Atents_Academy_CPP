#include <iostream>
#include <string>

using namespace std;

class Fruit {
private:
    string _name;   // 과일명
    float _weight;   // 무게
    float _brixDegree;   // 당도

public:
    Fruit(string name, float weight, float brixDegree)
        : _name(name), _weight(weight), _brixDegree(brixDegree) {
    }

    string GetName() const { // const 함수
        // const 함수는 멤버변수의 값을 변경하지 않는 함수
        //_name = "monster";
        return _name;
    }

    void SetName(string value) {
        _name = value;
    }

    float GetBrixDegree() const {
        return _brixDegree;
    }

    float GetWeight() const {
        return _weight;
    }

    void ShowInfo() const {
        cout << "과일명: " << _name << endl;
        cout << "무게: " << _weight << "g" << endl;
        cout << "당도: " << _brixDegree << "%" << endl;
        cout << endl;
    }
};

// 객체의 참조값을 const로 전달하게 되면
// 전달받은 함수에서 객체의 값을 변경할 수 없습니다.
// 객체를 const로 전달하면 참조값으로 const 멤버함수만 호출 할 수 있습니다.

void PrintFruit(const Fruit& ref) {
    //ref.SetName("호박");
    cout << "과일명: " << ref.GetName() << endl;
    cout << "무게: " << ref.GetWeight() << "g" << endl;
    cout << "당도: " << ref.GetBrixDegree() << "%" << endl;
    cout << endl;
}


int main() {
    Fruit fruitArray[3] = {
       {"바나나" , 0.3f, 80.0f},
       {"사과", 0.8f, 83.0f},
       {"딸기", 0.2f, 78.0f}
    };

    int length = sizeof(fruitArray) / sizeof(Fruit);

    for (int i = 0; i < length; i++) {
        PrintFruit(fruitArray[i]);
    }

    return 0;
}