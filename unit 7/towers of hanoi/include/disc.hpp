#ifndef DISC_HPP
#define DISC_HPP

#include <globals.hpp>
#include <allegro.h>

extern BITMAP *buffer;


class disc_c {

	const int color;
	dimension height;

	dimension	_size;

	disc_c*		_next;

public:
	dimension	size	() const;

	void		link	(disc_c* node);
	disc_c*		next	();

	void		draw	(dimension x, dimension y) const;

				disc_c	(dimension size_);
};


#endif	//DISC_HPP
