#include <allegro.h>
#include <iostream>
#include <towers.hpp>
using namespace std;

BITMAP *buffer = NULL;	//declares buffer
const unsigned dispw = 800, disph = 600;
bool speed = false;

volatile unsigned cycle = 0;

void CYCLE() {

	++cycle;
}
END_OF_FUNCTION (CYCLE);


bool init() {

	bool success = true;

	allegro_init();
	set_window_title ("Towers of Hanoi");

	install_keyboard();

	set_color_depth (desktop_color_depth() );
	set_gfx_mode (GFX_AUTODETECT_WINDOWED, dispw, disph, 0, 0);

	buffer = create_bitmap (dispw, disph);
	clear_bitmap (buffer);

	if (!buffer)
		success = false;

	LOCK_VARIABLE (cycle);
	LOCK_FUNCTION (CYCLE);
	install_int_ex (CYCLE, BPS_TO_TIMER (60) );

	return success;
}

void cleanup() {

}

void input() {

}

void calc() {

	--cycle;
}

void draw() {


	draw_sprite (buffer, screen, disph, dispw); // Draw the buffer to the screen
	draw_sprite (screen, buffer, 0, 0);
	clear_bitmap (buffer); // Clear the contents of the buffer bitmap
}

void run() {

	while (!key[KEY_ESC]) {

		while (speed || cycle > 0) {
			input();
			calc();
		}

		draw();
	}
}

int main() {

	init();

	run();

	cleanup();

	return 0;
}
END_OF_MAIN()
