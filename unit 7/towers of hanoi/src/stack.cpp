#include <hanoi/stack.hpp>

void stack_c::push(long double x) {
	NODE_c* temp = head;
	head = new NODE_c(x);
	head->link(temp);
}

long double stack_c::pop() {
	if (!head) return 0;
	long double temp = head->data;
	NODE_c* old = head;
	head = head->next();
	delete old;
	return temp;
}

long double stack_c::peek() {
	return (head) ? head->data : 0;
}

stack_c::stack_c() : head (0) {
}
