#include <iostream>

using namespace std;

int main() {

    int x = 0;
    cout << "x�� ���� �Է��ϼ���: ";
    cin >> x;

    bool isIn = (0 < x) && (x < 10);


    if (isIn) {
        cout << "x: " << x << "�� 0�� 10���̿� �ִ�." << endl;
    }
    else {
        cout << "x: " << x << "�� 0�� 10���̿� ����." << endl;
    }


    return 0;
}