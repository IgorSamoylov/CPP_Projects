// XOR_in_CPP.cpp: определяет точку входа для приложения.
//

#include "XOR_in_CPP.h"

#include <cassert> // для assert()

using namespace std;

int main()
{
	bool A = true;
	bool B = false;
	bool C;

	C = A != B;
	cout << C << endl;

	C = A ^ B;
	cout << C << endl;

	C = A && !B || !A && B;
	cout << C << endl;

	C = A + B == 1;
	cout << C << endl;

	assert (C);

	return 0;
}
