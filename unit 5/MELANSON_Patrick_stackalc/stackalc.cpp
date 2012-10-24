#include <iostream>
#include <sstream>
#include "include\RPN.h"
using namespace std;

RPN_t& calc = RPN_t::getInstance();	//creates an RPN singleton


bool getInput() {

	cout << "[q]\t\tQuit\n";
	cout << "[+]\t\tAdd top two numbers\n";
	cout << "[-]\t\tsubtract top two numbers\n";
	cout << "[*]\t\tmultiply top two numbers\n";
	cout << "[/]\t\tdivide top two numbers\n";
	cout << "[num]\tadd number to stack\n";
	cout << ">";

	string buffer;
	cin >> buffer;
	cout << "\n";

	char arg;	//argument
	istringstream input (buffer);
	arg = tolower(input.get());

	while (arg != 'q' && arg != '+' && arg != '-' && arg != '*' && arg != '/' && arg != '#') {
		cout << "\nThat choice wasn't listed\n";
		cout << ">";
		cin >> buffer;
		cout << "\n";
		istringstream input (buffer);
		arg = tolower(input.get());
	}

	float num;
	input >> num;


	switch (arg) {
	case '#':
		calc.push(num);
		break;

	case '+':
		calc.add();
		break;

	case '-':
		calc.sub();
		break;

	case '*':
		calc.mult();
		break;

	case '/':
		calc.div();
		break;

	case 'q':
		return false;

	default:
		cout << "Invalid input";
		return false;
	}

	return true;
}


int main() {

	while(getInput())
		cout << calc.peek() << endl << calc.peek() << "\n\n";


	return 0;
}
