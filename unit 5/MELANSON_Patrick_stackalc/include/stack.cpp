#include "stack.h"

void stack_t::push(long double x) {
	NODE_t* temp = head;
	head = new NODE_t(x);
	head->link(temp);
}

long double stack_t::pop() {
	if (!head) return 0;
	long double temp = head->data;
	NODE_t* old = head->next();
	head = head->next();
	delete old;
	return temp;
}

long double stack_t::peek() {
	return (head) ? head->data : 0;
}

stack_t::stack_t() : head (0), tail (0) {
}
