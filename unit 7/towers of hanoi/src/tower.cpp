#include <tower.hpp>

pos			tower_c::x		() const {return _x;}
void		tower_c::draw	() const {

	rectfill(buffer, x(), SCREEN_H/2, x() + width, SCREEN_H/2 + height + width, color);

	if (!_head)
		return;

	static disc_c* it = _head;
	short unsigned y = 0;
	while (it->next()) {
		it->draw(x(), SCREEN_H/2 - height - y++ * discHeight);
		it = it->next();
	}

}

dimension	tower_c::pop	() {

	if (!_head)
		return 0;

	dimension temp = _head->size();
	delete _head;
	return temp;
}
void		tower_c::push	(dimension size) {

	disc_c* temp = _head;
	_head = new disc_c(size);
	_head->link(temp);
}
void		tower_c::move	(tower_c& tower) {tower.push(pop());}
