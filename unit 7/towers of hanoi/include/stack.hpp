#ifndef STACK_HPP
#define STACK_HPP

#include <node.hpp>	//parent class

class stack_t {
private:
	node_c*		_head;						//pointer to head of list
public:
	void		draw	();					//draws everything on stack

				stack_t	();					//initializes head and tail to NULL
};

#endif	//STACK_HPP
