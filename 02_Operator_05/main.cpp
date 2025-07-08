#include <iostream>

using namespace std;

int main() {
	int k = 0;

	k && (k = k + 1);

	cout << "And K = " << k << endl;

	k = 0;

	k || (k = k + 2);

	cout << "OR K = " << k << endl;




	return 0;
}