#include "RPN.h"

RPN_t::RPN_t() {
}

RPN_t& RPN_t::getInstance() {
	static RPN_t instance;
	return instance;
}

void RPN_t::add() {
	push (pop() + pop());
}
void RPN_t::sub() {
	push (pop() - pop());
}
void RPN_t::mult() {
	push (pop() * pop());
}
void RPN_t::div() {
	push (pop() / pop());
}
