#include <iostream>
#include <limits>
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

public:
	void add() {push (pop() + pop());}
	void sub() {push (pop() - pop());}
	void mult() {push (pop() * pop());}
	void div() {push (pop() / pop());}
};

int main() {

	RPN_t calc;

	calc.push(5);
	calc.push(6);

	calc.add();
	cout << calc.pop() << endl;

	calc.push(5);
	calc.push(6);

	calc.sub();
	cout << calc.pop() << endl;

	calc.push(5);
	calc.push(6);

	calc.mult();
	cout << calc.pop() << endl;

	calc.push(5);
	calc.push(6);

	calc.div();
	cout << calc.pop() << endl;

	return 0;
}
