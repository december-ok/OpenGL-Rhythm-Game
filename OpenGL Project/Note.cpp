#include "Note.h"
#include "Round.h"
#include <iostream>

float Note::GetHeight(unsigned int _frame)
{
	if (!IsActive(_frame)) return ROWS; // Non-active ������ ���
	return ROWS - (_frame - this->createFrame); // 1 ~ ROWS ��ȯ
}

bool Note::IsCheckCreate(unsigned int _frame)
{
	return this->createFrame == _frame;
	
}

bool Note::IsActive(unsigned int _frame)
{
	cout << _frame << " | " << this->createFrame << endl;
	return (this->createFrame < _frame && this->createFrame + ROWS >= _frame);
}

void ItemNote::UseItem()
{
}
