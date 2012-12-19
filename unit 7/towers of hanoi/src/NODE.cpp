#include <node.hpp>

node_c::node_c() {
	data = 0;
	nextNode = 0;
}

node_c::node_c (short unsigned size_) : size (size_), nextNode (0) {}

node_c* node_c::next() {
	return nextNode;
}

void node_c::link (node_c* node) {
	nextNode = node;
}
