#include <iostream>
using namespace std;


class stack_t {
	float data[20];
	int top;

public:
	void push(float x) {
		if (top != 19) data[++top] = x;	//sets value if it won't overflow stack
	}
	float pop() {
		if (top != -1) return data[top--];	//returns value if stack is not empty
		else return top;	//returns error
	}

	stack_t() : top (-1) {}	//initializes top to -1

};

class calc_t : stack_t {


};


int main() {

	stack_t stack;
	int n, x = 0;

	for (n=0; n<22; n++) {
		stack.push(x++);
		cout << stack.pop() << endl;
	}

	return 0;
}
