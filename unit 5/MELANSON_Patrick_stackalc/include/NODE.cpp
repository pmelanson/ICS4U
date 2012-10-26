#include "NODE.h"

NODE_t::NODE_t() {

	data = 0;
	nextNode = 0;	//is really NULL, but I'd have to include another library for that
}

NODE_t::NODE_t (float x) {

	data = x;
	nextNode = 0;	//is really NULL, but I'd have to include another library for that
}

NODE_t* NODE_t::next() {
	return nextNode;
}

void NODE_t::link (NODE_t* node) {
	nextNode = node;
}
