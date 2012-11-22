#ifndef TOWER_HPP
#define TOWER_HPP

#include <disc.hpp>
#include <globals.hpp>
#include <allegro.h>

typedef const unsigned short pos;
extern BITMAP *buffer;

class tower_c {

	dimension	height,
				width;
	const int	color;

	pos			_x;

	disc_c*		_head;
public:

	pos			x		() const;
	void		draw	() const;

	dimension	pop		();
	void		push	(dimension size);
	void		move	(tower_c& targ);
				tower_c	(pos x_);
};

#endif	//TOWER_HPP
