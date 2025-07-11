#include <iostream>
#include <string>

using namespace std;

// 클래스를 만들때 반드시 생성자 필요한 경우가 있습니다.
class Student {
private:
    string _name;
    int _grade;
    int _classNum;

    const int MAXSTUDENTCOUNT;   // 전체 학생수 (상수형 멤버변수)
    int& _specialClassNum;   // 특활반  (참조형 멤버변수)

public:

    // 상수형 멤버변수나 참조형 멤버변수는 생성자 초기화 리스트를 통해서
    // 초기화를 해야 합니다.
    // 생성자 초기화 리스트로 초기화를 진행한다는 의미는
    // 객체의 메모리가 할당됨과 동시에 초기값이 부여가 된다는 것입니다.
    Student(string name, int grade, int classNum, int maxStudentCount, int& special)
        : _name(name), _grade(grade), _classNum(classNum), MAXSTUDENTCOUNT(maxStudentCount), _specialClassNum(special)
    {
        // C++ 클래스 에서는 변수의 공간을 할당하고 대입 연산을 통해 값을 초기화 하기보다는,
        // 콜론 기호(:)로 초기화 리스트를 통해 할당과 동시에 값을 초기화 한다.
        /*
        _name = name;
        _grade = grade;
        _classNum = classNum;
        */
    }


    void Info() {
        cout << "이름: " << _name << endl;
        cout << "학년: " << _grade << endl;
        cout << "반: " << _classNum << endl;
        cout << "총학생수: " << MAXSTUDENTCOUNT << endl;
        cout << "특활반: " << _specialClassNum << endl;
    }
};


int main() {

    int specialStudentNum = 11;

    Student st("Monster", 3, 5, 200, specialStudentNum);


    st.Info();
    cout << endl;

    specialStudentNum = 200;

    st.Info();


    return 0;
}