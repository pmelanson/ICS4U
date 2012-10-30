#include "NODE.h"

NODE_t::NODE_t() {

	data = 0;
	nextNode = 0;
}

NODE_t::NODE_t (long double x) {

	data = x;
	nextNode = 0;
}

NODE_t::~NODE_t () {
}

NODE_t* NODE_t::next() {
	return nextNode;
}

void NODE_t::link (NODE_t* node) {
	nextNode = node;
}
