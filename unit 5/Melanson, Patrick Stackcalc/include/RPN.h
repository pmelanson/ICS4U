#ifndef RPN_H
#define RPN_H

#include "stack.h"	//parent class

class RPN_t : public stack_t {
public:
	static RPN_t&	getInstance	();	//returns the same address no matter how many times called


	///operators///
	void			add			();
	void			sub			();
	void			mult		();
	void			div			();
	void			recip		();
	void			sign		();
	void			sqrt		();
	void			logarithm	();
	void			sine		();
	void			cosine		();
	void			tangent		();
	void			pi			();
};

#endif // RPN_H
