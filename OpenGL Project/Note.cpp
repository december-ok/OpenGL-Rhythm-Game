#include "Note.h"
#include "Global.h"
#include <iostream>

void SwapLine(RoundScene* _roundScene, unsigned char _index01, unsigned char _index02);
void HpUp(RoundScene* _roundScene);
void ReinforceUp(RoundScene* _roundScene);
void BlinkOn(RoundScene* _roundScene);
void AccelOn(RoundScene* _roundScene);
void SlowDownOn(RoundScene* _roundScene);
void LieNoteOn(RoundScene* _roundScene);


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
	else if (itemType == HPUP) {
		cout << "HPUP" << endl;
		HpUp(_roundScene);
	}
	else if (itemType == REINFORCE) {
		cout << "ReinforceUp" << endl;
		ReinforceUp(_roundScene);
	}
	else if (itemType == BLINK) {
		cout << "Note Blink" << endl;
		BlinkOn(_roundScene);
	}
	else if (itemType == ACCELERATE) {
		cout << "Accel Note" << endl;
		AccelOn(_roundScene);
	}
	else if (itemType == SLOWDOWN) {
		cout << "Slow Down Note" << endl;
		SlowDownOn(_roundScene);
	}
	else if (itemType == LIENOTE) {
		cout << "Make Lienote" << endl;
		LieNoteOn(_roundScene);
	}
}

void SwapLine(RoundScene* _roundScene, unsigned char _index01, unsigned char _index02)
{
	vector<Note*> tmp = *_roundScene->getNotes(_index01);
	*(_roundScene->getNotes(_index01)) = *(_roundScene->getNotes(_index02));
	*(_roundScene->getNotes(_index02)) = tmp;
}

void HpUp(RoundScene* _roundScene)
{
	_roundScene->gameInfo->HP += 30;
	if (_roundScene->gameInfo->HP > 100)
		_roundScene->gameInfo->HP = 100;
}
void ReinforceUp(RoundScene* _roundScene)
{
	_roundScene->reinforce += 1000;
}

void BlinkOn(RoundScene* _roundScene)
{
	_roundScene->blink();
}

void AccelOn(RoundScene* _roundScene)
{
	int _frame = _roundScene->getFrame();
	_roundScene->setAccelNote(_frame);
}

void SlowDownOn(RoundScene* _roundScene)
{
	int _frame = _roundScene->getFrame();
	_roundScene->setSlowNote(_frame);
}

void LieNoteOn(RoundScene* _roundScene)
{
	int _frame = _roundScene->getFrame();
	_roundScene->lieNoteOn();
}