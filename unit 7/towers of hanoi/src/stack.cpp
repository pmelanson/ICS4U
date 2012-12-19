#include <stack.hpp>

void stack_t::push(long double x) {
	node_c* temp = head;
	head = new node_c(x);
	head->link(temp);
}

long double stack_t::pop() {
	if (!head) return 0;
	long double temp = head->data;
	node_c* old = head;
	head = head->next();
	delete old;
	return temp;
}

long double stack_t::peek() {
	return (head) ? head->data : 0;
}

stack_t::stack_t() : head (0) {
}
