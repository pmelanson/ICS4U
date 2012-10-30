#include "NODE.h"

NODE_t::NODE_t() {

	data = 0;
	nextNode = 0;
	prevNode = 0;
}

NODE_t::NODE_t (float x) {

	data = x;
	nextNode = 0;
	prevNode = 0;
}

NODE_t* NODE_t::next() {
	return nextNode;
}

NODE_t* NODE_t::prev() {
	return prevNode;
}

void NODE_t::link (NODE_t* node) {
	nextNode = node;
}
