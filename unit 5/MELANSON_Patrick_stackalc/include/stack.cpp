#include "stack.h"

void stack_t::push(float x) {
	NODE_t* temp = head;
	head = new NODE_t(x);
	head->link(temp);
}

float stack_t::pop() {
	if (!head) return 0;
	float temp = head->data;
	head = head->next();
	return temp;
}

float stack_t::peek() {
	return (head) ? head->data : 0;
}

stack_t::stack_t() : head (0) {
}
