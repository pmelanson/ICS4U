#ifndef STACK_H
#define STACK_H

class stack_t {
public:
	float data[20];
	int top;

public:
	void	push	(float x);	//sets value if it won't overflow stack
	float	pop		();			//returns value if stack is not empty, otherwise 0
	float	peek	() {
		return (top != -1) ? data[top] : 0;		//returns value if stack is not empty, otherwise 0, does not remove from stack
	}

	stack_t() : top (-1) {}	//initializes top to -1
};

#endif // STACK_H
