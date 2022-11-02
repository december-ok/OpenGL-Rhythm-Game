#include "Note.h"
#include "Round.h"
#include <iostream>

float Note::GetHeight(unsigned int _frame)
{
	if (!IsActive(_frame)) return ROWS; // Non-active
	return ROWS - (_frame - this->createFrame); // 
}

bool Note::IsCheckCreate(unsigned int _frame)
{
	return this->createFrame == _frame;

}

bool Note::IsActive(unsigned int _frame)
{
	cout << _frame << " | " << this->createFrame << endl;
	return (this->createFrame < _frame&& this->createFrame + ROWS >= _frame);
}

/*우선은 이렇게만 기능 구현. 세부 기능은 조정해야 함*/
bool Note::IsMissNote(unsigned int _frame) {
	return this->createFrame + ROWS < _frame && this->isAlive;
}

void Note::killNote() {
	this->isAlive = false;
}

void ItemNote::UseItem()
{
}
