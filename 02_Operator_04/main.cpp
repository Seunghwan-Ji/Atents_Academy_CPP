#include <iostream>

using namespace std;

int main() {
	bool TRUE = -2000;
	bool FALSE = 0;


	cout << "논리 &&(And) 연산자\n";
	bool ret = TRUE && TRUE;
	cout << "TRUE && TRUE = " << ret << endl;
	ret = TRUE && FALSE;
	cout << "TRUE && FALSE = " << ret << endl;
	ret = FALSE && TRUE;
	cout << "FALSE && TRUE = " << ret << endl;
	ret = FALSE && FALSE;
	cout << "FALSE && FALSE = " << ret << endl;

	cout << "\n논리 ||(OR) 연산자\n";
	ret = TRUE || TRUE;
	cout << "TRUE || TRUE = " << ret << endl;
	ret = TRUE || FALSE;
	cout << "TRUE || FALSE = " << ret << endl;
	ret = FALSE || TRUE;
	cout << "FALSE || TRUE = " << ret << endl;
	ret = FALSE || FALSE;
	cout << "FALSE || FALSE = " << ret << endl;

	cout << "\n논리 !(not)연산자\n";
	ret = !TRUE;
	cout << "!TRUE = " << ret << endl;

	ret = !FALSE;
	cout << "!FALSE = " << ret << endl;




	return 0;
}