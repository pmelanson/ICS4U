#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main () {

	float a;
	float sd, exp;

	cout << "(0-10) a = ";
	cin >> a;
	cout << "(1-5) sig digs: ";
	cin >> sd;
	cout << "(2-3) exponent = ";
	cin >> exp;
//	cout << setprecision (sd);

	float n;

//	while (true) {
//
//		cout << a << " = " << a+pow(10,-n) << ":\t" << (int(a * pow(10,sd)) == int(a+pow(10,-n)) ) << endl;
//		n++;
//		if (int(a * pow(10.,sd-1.)) == int(a+pow(10.,-n) * pow(10.,sd-1.)) )
//			break;
//	}

	do {

		cout << a << " = " << (a + pow(10, -n)) * pow(10,sd) << ":\t" << endl;
		n++;
	} while (int(a * pow(10,sd) != int(((a + pow(10, -n)) * pow(10,sd)))));

//	cout << "\n\nm = " <<


	return 0;
}
