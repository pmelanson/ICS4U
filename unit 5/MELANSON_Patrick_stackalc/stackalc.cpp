#include <iostream>
#include <sstream>
using namespace std;



class RPN_t : public stack_t {
private:
	RPN_t() {}	//private constructor
	//override default functions
	RPN_t(RPN_t const& copy);            //no definition
	RPN_t& operator=(RPN_t const& copy); //no definition

public:
	static RPN_t& getInstance() {
		static RPN_t instance;	//only ever has one instance, no matter how many times getInstance is called
		return instance;
	}

	//operators
	void add() {push (pop() + pop());}
	void sub() {push (pop() - pop());}
	void mult() {push (pop() * pop());}
	void div() {push (pop() / pop());}
};

RPN_t& calc = RPN_t::getInstance();


bool getInput() {

	cout << "[q]\t\tQuit\n";
	cout << "[+]\t\tAdd top two numbers\n";
	cout << "[-]\t\tsubtract top two numbers\n";
	cout << "[*]\t\tmultiply top two numbers\n";
	cout << "[/]\t\tdivide top two numbers\n";
	cout << "[#[num]]\tadd number to stack\n";
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
