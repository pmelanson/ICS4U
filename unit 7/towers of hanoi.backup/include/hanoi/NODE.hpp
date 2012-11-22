#ifndef NODE_HPP
#define NODE_HPP

class NODE_c {
private:
	NODE_c*		nextNode;						//pointer to next node
public:
				NODE_c		();					//construct without value
				NODE_c		(long double x);	//construct with value

	long double	data;							//holds data
	NODE_c*		next		();					//returns nextNode
	void		link		(NODE_c* node);		//link this node to the next node
};


#endif	//NODE_HPP
