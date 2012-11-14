#include <hanoi/NODE.hpp>

NODE_c::NODE_c() {
	data = 0;
	nextNode = 0;
}

NODE_c::NODE_c (long double x) {
	data = x;
	nextNode = 0;
}

NODE_c* NODE_c::next() {
	return nextNode;
}

void NODE_c::link (NODE_c* node) {
	nextNode = node;
}
