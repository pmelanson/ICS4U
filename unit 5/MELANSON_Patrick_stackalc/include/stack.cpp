#include "stack.h"

stack_t::push(float x) {
	if (top != 19) data[++top] = x;
}

stack_t::pop() {
	return (top != -1) ? data[top--] : 0;
}
