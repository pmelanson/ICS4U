#include "stack.h"
#include <iostream>
//
//void stack_t::push(float x) {
//	if (top != 19) data[++top] = x;
//}

void stack_t::push(float x) {
	NODE_t* temp = head;
	head = new NODE_t;
	head->link(temp);
}
//
//float stack_t::pop() {
//	return (top != -1) ? data[top--] : 0;
//}

float stack_t::pop() {
	float temp = head->data;
	head = head->next();
	return temp;
}

float stack_t::peek() {
	return (!head) ? head->data : 0;
}

stack_t::stack_t() : head (0) {
}
