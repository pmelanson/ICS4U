#ifndef NODE_H
#define NODE_H

class NODE_t {
private:
	NODE_t*		nextNode;						//pointer to next node
public:
				NODE_t		();					//construct without value
				NODE_t		(long double x);	//construct with value
				~NODE_t		();					//deconstructs

	long double	data;							//holds data
	NODE_t*		next		();					//returns nextNode
	void		link		(NODE_t* node);		//link this node to the next node
};


#endif // NODE_H
