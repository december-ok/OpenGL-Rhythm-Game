#include "Note.h"
#include "Round.h"
#include <iostream>

float Note::GetHeight(unsigned int _frame)
{
	if (!IsActive(_frame)) return -0.0f; // Non-active 상태일 경우
	return _frame - this->createTime; // 1 ~ ROWS 반환
}

bool Note::IsCheckCreate(unsigned int _frame)
{
	return this->createTime == _frame;
	
}

bool Note::IsActive(unsigned int _frame)
{
	cout << _frame << " | " << this->createTime << endl;
	return (this->createTime < _frame && this->createTime + ROWS >= _frame);
}

void ItemNote::UseItem()
{
}
