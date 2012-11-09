#include <iostream>			//for input/output
#include <iomanip>			//for output formatting
#include <sstream>			//for input parsing
#include "include\RPN.h"	//for my RPN
using namespace std;

RPN_t& calc = RPN_t::getInstance();	//creates an RPN singleton


bool getInput() {

	///initialization///
	const unsigned buttonw = 7;	//width of buttons, do not set too low

	const unsigned dispw = (buttonw + 2) * 4 + 1;	//width of display, equal to width of 4 buttons
	char TL ='\xC9', TR ='\xBB', h ='\xC4',v='\xB3', BL ='\xC8', BR ='\xBC';	//creating extended ASCII characters using their hexvalues
	short unsigned n;	//counter
	string buttontop, buttonbott;	//shorthand for top and bottom of buttons

	///generate button strings///
	buttontop += TL;
	for(n=0; n<buttonw; ++n)
		buttontop += h;
	buttontop += TR;

	buttonbott += BL;
	for(n=0; n<buttonw; ++n)
		buttonbott += h;
	buttonbott += BR;

	///print out display///
	(dispw -2) > 15 ? cout<<setprecision(15) : cout<<setprecision(dispw -2);	//maximum precision before I run into floating point garbage

	cout <<TL;
	for(n=0; n<dispw; ++n) cout <<h;
	cout <<TR << endl;

	cout <<v<< setw(dispw) << left << calc.peek() <<v<< endl;

	cout <<BL;
	for(n=0; n<dispw; ++n) cout <<h;
	cout <<BR << endl;


	cout << right;

	///print out + - * / buttons///
	cout << buttontop													<<' '<< buttontop													<<' '<< buttontop													<<' '<< buttontop << endl;
	cout <<v<< setw(buttonw/2. +1) <<'+'<< setw(buttonw/2. +0.5) <<v	<<' '<<v<< setw(buttonw/2. +1) <<'-'<< setw(buttonw/2. +0.5) <<v	<<' '<<v<< setw(buttonw/2. +1) <<'*'<< setw(buttonw/2. +0.5) <<v	<<' '<<v<< setw(buttonw/2. +1) <<'/'<< setw(buttonw/2. +0.5) <<v<< endl;
	cout << buttonbott													<<' '<< buttonbott															<<' '<< buttonbott											<<' '<< buttonbott << endl;

	///print out recip sign sqrt exp buttons///
	cout << buttontop														<<' '<< buttontop														<<' '<< buttontop														<<' '<< buttontop << endl;
	cout <<v<< setw(buttonw/2. +3) << "recip" << setw(buttonw/2. -1.5) <<v	<<' '<<v<< setw(buttonw/2. +2.5) << "sign" << setw(buttonw/2. -1.) <<v	<<' '<<v<< setw(buttonw/2. +2.5) << "sqrt" << setw(buttonw/2. -1.) <<v	<<' '<<v<< setw(buttonw/2. +1.5) << "log" << setw(buttonw/2.) <<v<< endl;
	cout << buttonbott														<<' '<< buttonbott														<<' '<< buttonbott														<<' '<< buttonbott << endl;

	///print out trig functions///
	cout << buttontop														<<' '<< buttontop														<<' '<< buttontop														<<' '<< buttontop << endl;
	cout <<v<< setw(buttonw/2. +3) << "sin" << setw(buttonw/2. -1.5) <<v	<<' '<<v<< setw(buttonw/2. +2.5) << "cos" << setw(buttonw/2. -1.) <<v	<<' '<<v<< setw(buttonw/2. +2.5) << "tan" << setw(buttonw/2. -1.) <<v	<<' '<<v<< setw(buttonw/2. +1.5) << "pi" << setw(buttonw/2.) <<v<< endl;
	cout << buttonbott														<<' '<< buttonbott														<<' '<< buttonbott														<<' '<< buttonbott << endl;

	///print out meta functions///
	cout << buttontop														<<' '<< buttontop														<<' '<< TL;
	for (n=0; n<(buttonw +1)*2 +1; n++) cout<<h;
	cout<<TR<<endl;
	cout <<v<< setw(buttonw/2. +3) << "del" << setw(buttonw/2. -1.5) <<v	<<' '<<v<< setw(buttonw/2. +2.5) << "help" << setw(buttonw/2. -1.) <<v	<<' '<<v<< setw(buttonw +2.5) << "power" << setw(buttonw +2.5) <<v<<endl;
	cout << buttonbott														<<' '<< buttonbott														<<' '<< BL;
	for (n=0; n<(buttonw +1)*2 +1; n++) cout<<h;
	cout<<BR<<endl;

	///get input///
	cout << "\n> ";
	string buffer;
	cin >> buffer;
	cout << "\n";

	///parse input///
	string arg;	//argument
	istringstream input(buffer);
	long double num;

	system("cls");

	if (isdigit(input.peek())) {	//if a number is detected
		input >> num;
		calc.push(num);
		cout << endl;
	} else {						//if an argument is detected
		input >> arg;
		if(arg == "q")
			return false;
		else if(arg == "+")
			calc.add();
		else if(arg == "-")
			calc.sub();
		else if(arg == "*")
			calc.mult();
		else if(arg == "/")
			calc.div();
		else if(arg == "recip")
			calc.recip();
		else if(arg == "sign")
			calc.sign();
		else if(arg == "sqrt")
			calc.sqrt();
		else if(arg == "log")
			calc.logarithm();
		else if(arg == "sin")
			calc.sine();
		else if(arg == "cos")
			calc.cosine();
		else if(arg == "tan")
			calc.tangent();
		else if(arg == "pi")
			calc.pi();
		else if(arg == "del")
			calc.pop();
		else if(arg == "help" || arg == "help")
			cout << "Patrick Melanson - RPN calculator emulator. Type 'q' to quit.";
		else if(arg == "power")
			return false;
		else
			cout << "Bad argument";

		cout << endl;
	}


	return true;
}


int main() {

	cout << "Patrick Melanson - RPN calculator emulator. Type 'q' to quit.\n";

	while(getInput());

	return 0;
}
