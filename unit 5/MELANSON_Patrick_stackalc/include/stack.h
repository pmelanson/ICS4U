#ifndef STACK_H
#define STACK_H

#include "NODE.h"	//parent class

class stack_t {
private:
	NODE_t*		head;
public:
	void		push	(long double x);	//sets value if it won't overflow stack
	long double	pop				();			//returns value if stack is not empty, otherwise 0
	long double	peek			();			//returns value if stack is not empty, otherwise 0, does not remove from stack

				stack_t	();					//initializes head and tail to NULL
};

#endif // STACK_H
