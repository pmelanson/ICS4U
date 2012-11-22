#ifndef NODE_HPP
#define NODE_HPP

class node_c {
private:
	node_c*					_next;								//pointer to next node
	const unsigned short	_size;
public:
							node_c		();						//construct without value
							node_c		(short unsigned size_);	//construct with value

	unsigned short			size();
	node_c*					next		() const;				//returns nextNode
	void					link		(node_c* node);			//link this node to the next node
};


#endif	//NODE_HPP
