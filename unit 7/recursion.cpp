#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;

typedef unsigned long data;

data factorial(data n) {

	if (n == 1) return 1;

	return n*(factorial (n-1));
}

void reverse() {

	char x = _getche();

	if (x != '#')
		reverse();
	else {
		cout << endl;
		return;
	}

	cout << x;
}

string binary(data n) {

	if (n == 0) return "0";
	char x = '\x30';
	return x + binary(n/2);
}


int main() {

	cout << factorial(3);

	cout << endl;

	reverse();

	cout << endl;

	cout << binary(11);

	cout << endl;
}
