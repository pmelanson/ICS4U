#include <iostream>
#include <sstream>
#include "include\RPN.h"
using namespace std;

RPN_t& calc = RPN_t::getInstance();	//creates an RPN singleton


bool getInput() {

	cout << "[num]\tadd number to stack\n";
	cout << "[q]\tQuit\n";
	cout << "[+]\tAdd top two numbers\n";
	cout << "[-]\tsubtract top two numbers\n";
	cout << "[*]\tmultiply top two numbers\n";
	cout << "[/]\tdivide top two numbers\n";
	cout << ">";

	string buffer;
	cin >> buffer;
	cout << "\n";

	char arg;	//argument
	istringstream input (buffer);
	arg = tolower(input.peek());

	while (arg != 'q' && arg != '+' && arg != '-' && arg != '*' && arg != '/' && !isdigit(arg)) {
		cout << "\nThat choice wasn't listed\n";
		cout << ">";
		cin >> buffer;
		cout << "\n";
		istringstream input (buffer);
		arg = tolower(input.get());
	}

	float num;

	if (isdigit(arg)) {
		input >> num;
		arg = '#';
	}


	switch (arg) {
	case '#':
		calc.push(num);
		cout << num;
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
		cout << calc.peek() << "\n\n";


	return 0;
}
