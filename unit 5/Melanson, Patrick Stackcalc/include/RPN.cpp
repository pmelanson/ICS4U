#include "RPN.h"
#define _USE_MATH_DEFINES	//allows use of math.h constants
#include <cmath>

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
void RPN_t::recip() {
	push (1. / pop());
}
void RPN_t::sign() {
	push (-pop());
}
void RPN_t::sqrt() {
	push (sqrtf(pop()));
}
void RPN_t::logarithm() {
	push (log(pop()));
}
void RPN_t::sine() {
	push (sin(pop()));
}
void RPN_t::cosine() {
	push (cos(pop()));
}
void RPN_t::tangent() {
	push (tan(pop()));
}
void RPN_t::pi() {
	push (M_PI);
}
