#include "stack.h"

void stack_t::push(float x) {
	if (top != 19) data[++top] = x;
}

float stack_t::pop() {
	return (top != -1) ? data[top--] : 0;
}

float stack_t::peek() {
	return (top != -1) ? data[top] : 0;
}

stack_t::stack_t() : top (-1) {
}
