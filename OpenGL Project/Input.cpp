#include "Input.h"

Input::Input(unsigned int i_f, int i_l)
	:input_frame(i_f), input_line(i_l)
{
}

Input::~Input()
{
	// �� ��������..?
}

unsigned int Input::getInputFrame()
{
	return input_frame;
}

int Input::getInputLine()
{
	return input_line;
}

