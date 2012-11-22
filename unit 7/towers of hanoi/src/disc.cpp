#include <disc.hpp>

dimension	disc_c::size	() const;

void		disc_c::link	(disc_c* node);
disc_c*		disc_c::next	();

void		disc_c::draw	(dimension x, dimension y) const {

	rectfill(buffer, x - size()/2, y, x + size()/2, y + height/2
}

			disc_c::disc_c	(dimension size_) : _size (size_) {}
