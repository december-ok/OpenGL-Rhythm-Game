#include "Note.h"
#include <iostream>

void SwapLine(RoundScene* _roundScene, unsigned char _index01, unsigned char _index02);

int Note::GetHeight(unsigned int _frame)
{
	if (!IsActive(_frame)) return ROWS; // Non-active
	return ROWS - (_frame - this->createFrame); // 
}

bool Note::IsCheckCreate(unsigned int _frame)
{
	return this->createFrame == _frame;

}

//bool Note::IsActive(unsigned int _frame)
//{
//	//cout << _frame << " | " << this->createFrame << endl;
//	return (this->createFrame < _frame&& this->createFrame + ROWS >= _frame);
//}

/*우선은 이렇게만 기능 구현. 세부 기능은 조정해야 함*/
//bool Note::IsMissNote(unsigned int _frame) {
//	return this->createFrame + ROWS < _frame && this->isAlive;
//}

void Note::killNote() {
	this->isAlive = false;
}


void ItemNote::UseItem(RoundScene* _roundScene)
{
	cout << "아이템 사용" << endl;
	if (itemType == SWITCHLINE) {
		cout << "라인 변경" << endl;
		SwapLine(_roundScene, 0, 3);
		SwapLine(_roundScene, 1, 2);
	}
}

void SwapLine(RoundScene* _roundScene, unsigned char _index01, unsigned char _index02)
{
	vector<Note*> tmp = *_roundScene->getNotes(_index01);
	*(_roundScene->getNotes(_index01)) = *(_roundScene->getNotes(_index02));
	*(_roundScene->getNotes(_index02)) = tmp;
}