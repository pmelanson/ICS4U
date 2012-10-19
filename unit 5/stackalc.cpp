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
/*
class RPN_t : public stack_t {
private:
//	RPN_t();
//	static RPN_t* _instance;
public:
	static RPN_t& getInstance() {
            // The only instance
            static RPN_t _instance;
            return _instance;
	}

	void add() {push (pop() + pop());}
	void sub() {push (pop() - pop());}
	void mult() {push (pop() * pop());}
	void div() {push (pop() / pop());}
};
*/
class RPN_t : public stack_t {
private:
	RPN_t();
	// Stop the compiler generating methods of copy the object
	RPN_t(RPN_t const& copy);	//I don't implement this
	RPN_t& operator=(RPN_t const& copy);	//or this

public:
	static RPN_t& getInstance() {
		// The only instance
		// Guaranteed to be lazy initialized
		// Guaranteed that it will be destroyed correctly
		static RPN_t instance;
		return instance;
	}
};

RPN_t calc = RPN_t::getInstance();

//RPN_t RPN_t::instance()
//{
//	if(_instance==NULL)
//	{
//		_instance=new RPN_t;
//	}
//	return _instance;
//}

//RPN_t RPN_t::_instance=NULL;

//RPN_t calc = RPN_t::getInstance();

//RPN_t poop = RPN_t::getInstance();
/*
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
	}//	cout << calc.pop();
//	cout << poop.pop();


	switch (choice) {
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
*/
int main() {

//	calc.push(5);
//	poop.push(8);
//	cout << calc.pop();
//	cout << poop.pop();

	return 0;
}
