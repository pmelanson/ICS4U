#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdlib.h>
#include "include\RPN.h"
using namespace std;

RPN_t& calc = RPN_t::getInstance();	//creates an RPN singleton


bool getInput() {

	///initialization///
	char TL = '\xC9', TR = '\xBB', horz = '\xC4', vert = '\xB3', BL = '\xC8', BR = '\xBC';	//creating extended ASCII characters using their hex values
	short unsigned n;
	const unsigned dispw = 27, buttonw = 14;	//width of display and buttons
	string buttontop, buttonbott;

	///generate button strings///
	buttontop += TL;
	for(n=0; n<buttonw; ++n)
		buttontop += horz;
	buttontop += TR;
	buttonbott += BL;
	for(n=0; n<buttonw; ++n)
		buttonbott += horz;
	buttonbott += BR;


	///print out display///
	cout <<TL; for(n=0; n<dispw; ++n) cout <<horz; cout <<TR << endl;
	cout << vert << setw(dispw) << left << calc.peek() << vert << endl;
	cout <<BL; for(n=0; n<dispw; ++n) cout <<horz; cout <<BR << endl;


	cout << right;

	///print out + - * / buttons///
	cout << buttontop														<< '\t' << buttontop														<< '\t' << buttontop														<< '\t' << buttontop << endl;
	cout << vert << setw(buttonw/2. +1) << '+' << setw(buttonw/2. +0.5) << vert	<< '\t' << vert << setw(buttonw/2. +1) << '-' << setw(buttonw/2. +0.5) << vert	<< '\t' << vert << setw(buttonw/2. +1) << '*' << setw(buttonw/2. +0.5) << vert	<< '\t' << vert << setw(buttonw/2. +1) << '/' << setw(buttonw/2. +0.5) << vert << endl;
	cout << buttonbott														<< '\t' << buttonbott														<< '\t' << buttonbott														<< '\t' << buttonbott << endl;

	///print out recip sign sqrt exp buttons///
	cout << buttontop																<< '\t' << buttontop																<< '\t' << buttontop																<< '\t' << buttontop << endl;
	cout << vert << setw(buttonw/2. +3) << "recip" << setw(buttonw/2. -1.5) << vert	<< '\t' << vert << setw(buttonw/2. +2.5) << "sign" << setw(buttonw/2. -1.) << vert	<< '\t' << vert << setw(buttonw/2. +2.5) << "sqrt" << setw(buttonw/2. -1.) << vert	<< '\t' << vert << setw(buttonw/2. +1.5) << "x^y" << setw(buttonw/2.) << vert << endl;
	cout << buttonbott																<< '\t' << buttonbott																<< '\t' << buttonbott																<< '\t' << buttonbott << endl;


	///get input///
	cout << "\n> ";
	string buffer;
	cin >> buffer;
	cout << "\n";

	///parse input///
	string arg;	//argument
	istringstream input(buffer);
	float num;

	if (input.peek() == '$') {
		input >> arg;
		if (arg == "$q")
			return false;
		else if (arg == "$+")
			calc.add();
		else if (arg == "$-")
			calc.sub();
		else if (arg == "$*")
			calc.mult();
		else if (arg == "$/")
			calc.div();
		else if (arg == "recip")
			calc.recip();
		else if (arg == "$sign")
			calc.sign();
		else if (arg == "$sqrt")
			calc.sqrt();
		else if (arg == "$x^y")
			calc.exp();
	}
	else if (input >> num) {
		calc.push(num);
		cout << endl;
	}
	else {
		cout << "invalid input\n";
		return false;
	}


	system("cls");

	return true;
}


int main() {

	cout << "Patrick Melanson - RPN calculator emulator\n";

	while(getInput());

	return 0;
}
