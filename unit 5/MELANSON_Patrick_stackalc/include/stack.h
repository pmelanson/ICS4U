#ifndef STACK_H
#define STACK_H

class stack_t {
public:
	float	data[20];
	int		top;				//index to top of stack

public:
	void	push	(float x);	//sets value if it won't overflow stack
	float	pop		();			//returns value if stack is not empty, otherwise 0
	float	peek	();			//returns value if stack is not empty, otherwise 0, does not remove from stack

			stack_t	();			//initializes top to -1
};

#include "stack.cpp"

#endif // STACK_H
