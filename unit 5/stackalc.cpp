#include <iostream>
#include <ctype.h>
using namespace std;


class stack_t {
	float data[20];
	int top;

public:
	void push(float x) {
		if (top != 19) data[++top] = x;	//sets value if it won't overflow stack
	}
	float pop() {
		return (top != -1) ? data[top--] : 0;	//returns value if stack is not empty, otherwise 0
	}

	stack_t() : top (-1) {}	//initializes top to -1

};

class RPN_t : public stack_t {
private:
	//private constructor
	RPN_t();
	//override default functions
	RPN_t(RPN_t const& copy);            //no definition
	RPN_t& operator=(RPN_t const& copy); //no definition

public:
	static RPN_t* getInstance() {
		static RPN_t* instance;	//only ever has one instance
		return instance;
	}

	//operators
	void add() {push (pop() + pop());}
	void sub() {push (pop() - pop());}
	void mult() {push (pop() * pop());}
	void div() {push (pop() / pop());}
};

RPN_t* calc = RPN_t::getInstance();


bool getInput() {

	cout << "[q]\t\tQuit\n";
	cout << "[+]\t\tAdd top two numbers\n";
	cout << "[-]\t\tsubtract top two numbers\n";
	cout << "[*]\t\tmultiply top two numbers\n";
	cout << "[/]\t\tdivide top two numbers\n";
	cout << "[number]\tadd number to stack\n";
	cout << ">";

	char choice;

	cin >> choice;
	choice = tolower(choice);

	while (choice != 'q' && choice != '+' && choice != '-' && choice != '*' && choice != '/' && !isdigit(choice) ) {
		cout << "\nThat choice wasn't listed\n";
		cout << ">";
		cin >> choice;
	}


	switch (choice) {
	case '+':
		calc->add();
		break;

	case '-':
		calc->sub();
		break;

	case '*':
		calc->mult();
		break;

	case '/':
		calc->div();
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

//	calc->push(5);
//	calc->push(8);
//	cout << calc->pop();
//	cout << calc->pop();

	cout << &calc;
	calc->push(1.2);


	return 0;
}
