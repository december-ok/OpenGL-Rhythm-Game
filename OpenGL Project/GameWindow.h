#pragma once
#include "Scene.h"
#include "Render.h"
#include "Input.h"

class GameWindow
{
public:
	GameWindow();
	~GameWindow();
	
	Scene* scene;
	
	void windowInit(int, char**);

	void init();
};

void reshapeFunction(int, int);
void display_callback();
void timer_callback(int);
void set_keyboard_callback(unsigned char, int, int);
void unset_keyboard_callback(unsigned char, int, int);
void set_special_keyboard_callback(int, int, int);
void unset_special_keyboard_callback(int, int, int);
