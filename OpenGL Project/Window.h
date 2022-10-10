#pragma once

#include "Round.h"
#include "Global.h"


class Window
{
public:
	Window();
	~Window();
	
	Round* round;
	
	void windowInit(int, char**);

	void init();
	void keyboard_callback(int, int, int);
	
};

void reshapeFunction(int, int);
void display_callback();
void timer_callback(int);