#pragma once
#include "Round.h"
#include "Global.h"


class Window
{
public:
	Window();
	~Window();
	
	Round* round;
	int line_input[LINES]; // 각 라인 별 입력 횟수 저장 - list로 할 때
	
	void windowInit(int, char**);

	void init();
};

void reshapeFunction(int, int);
void display_callback();
void timer_callback(int);
void set_keyboard_callback(unsigned char, int, int);
void unset_keyboard_callback(unsigned char, int, int);