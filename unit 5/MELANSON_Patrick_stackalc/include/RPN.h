#ifndef RPN_H
#define RPN_H

#include "stack.h"	//parent class

class RPN_t : public stack_t {
private:
					RPN_t		();	//private constructor
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
	void			exp			();
};

#endif // RPN_H
