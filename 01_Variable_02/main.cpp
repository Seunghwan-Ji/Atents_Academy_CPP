#include <iostream>

using namespace std;

int main() {
	// �Ʒ� ������� ������ �� ������ ����Ÿ Ÿ����
	// ��谪�� �Է��Ͻð� ����غ�����..
	// 
	// ������
	short a;
	a = -32768;
	cout << "a = " << a << endl;

	long b;
	b = -2147483647 - 1;
	cout << "b = " << b << endl;

	int c;
	c = -2147483647 - 1;
	cout << "c = " << c << endl;

	unsigned short d;
	d = 65535;
	cout << "d = " << d << endl;

	unsigned long e;
	e = 4294967295;
	cout << "e = " << e << endl;

	unsigned int f;
	f = 4294967295;
	cout << "f = " << f << endl;

	// �Ǽ���
	float g;
	g = -3.4e-38f;
	printf("g = %f\n", g);
	cout << fixed; // ��½� �����Ҽ������� ǥ���ϵ��� �����ϴ� �Լ�.
	cout.precision(200); // �Ҽ��� 200��° �ڸ�����.
	cout << "g = " << g << endl;

	double h;
	h = -1.79769e+308;
	cout << "h = " << h << endl;

	// ������
	char i;
	i = 100;
	cout << "i = " << i << endl;

	unsigned char j;
	j = 101;
	cout << "j = " << j << endl;
	
	// ��� printf �Լ� ���
	// ���� �������ڿ�
	int ab = 20;
	int cb = 30;
	// %d ��ȣ�ִ� ������ ���
	cout << "ab = " << ab << ", cb = " << cb << endl;
	//printf("ab = %d, cb = %d\n", ab, cb);

	float dd = 1.3f;
	double ee = 3.4;
	// %f(float), %lf(double)
	//printf("dd = %f, ee = %lf\n", dd, ee);
	cout << "dd = " << dd << ", ee = " << ee << endl;

	// ������
	char AA = 65;
	unsigned char BB = 66;
	//printf("AA = %c, BB = %c\n", AA, BB);
	cout << "AA = " << AA << ", BB = " << BB << endl;


	return 0;
}