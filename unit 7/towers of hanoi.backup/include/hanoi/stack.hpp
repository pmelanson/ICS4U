#ifndef STACK_HPP
#define STACK_HPP

#include <hanoi/NODE.hpp>	//parent class

class stack_c {
private:
	NODE_c*		head;						//pointer to head of list
public:
	void		push	(long double x);	//sets value if it won't overflow stack
	long double	pop		();					//returns value if stack is not empty, otherwise 0
	long double	peek	();					//returns value if stack is not empty, otherwise 0, does not remove from stack

				stack_c	();					//initializes head and tail to NULL
};

#endif	//STACK_HPP
