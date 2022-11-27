#pragma once
#include "Global.h"
#include "RoundScene.h"
#include <iostream>

class RoundScene;

class Note
{
public:
	int createFrame; // 생성 되는 시점의 fps
	bool isAlive = true;	// 죽은 노트: 입력이 된 노트
	bool isAccel = false;
	bool isSlow = false;
	unsigned char type; // 노트의 종류 (0 = Normal, 1 = Section, 2 = Lie, 3 = Item)

	~Note() {};
	int GetHeight(unsigned int _frame); // 현재 fps에서 위치 값을 반환하는 함수 (만약 Active된 상태가 아니라면 0을 반환)
	bool IsCheckCreate(unsigned int _frame); // 생성 되어야 하는지 체크하고 반환하는 함수
	void killNote();	// 사용자의 입력이 들어오면 노트를 죽임

	virtual bool IsActive(unsigned int _frame) = 0; // 현재 월드에 Active한 상태인지 체크하고 반환하는 함
	virtual bool IsMissNote(unsigned int _frame) = 0;	// 사용자가 입력하지 못한 노트인지 확인
	virtual int getNoteLength() = 0;	// 노트의 길이(일반 노트: 1, 롱노트: n)
};

class NormalNote : public Note
{
public:
	NormalNote(int _createTime) { this->type = 0; this->createFrame = _createTime; };
	~NormalNote() {};
	int getNoteLength() override { return 1; }
	bool IsActive(unsigned int _frame) override { return (this->createFrame < _frame&& this->createFrame + ROWS >= _frame); }
	bool IsMissNote(unsigned int _frame) override { return this->createFrame + ROWS < _frame&& this->isAlive; }

};

class SectionNote : public Note
{
	int sectionTime; // 지속되는 시간 (시작점은 createTime을 기준)
	int endFrame;	// 종료되야 하는 frame
public:

	SectionNote(int _createTime, int _endFrame) { this->type = 1; this->createFrame = _createTime; this->endFrame = _endFrame; this->sectionTime = this->endFrame - this->createFrame; };
	~SectionNote() {};
	int getNoteLength() override { return sectionTime; }
	bool IsActive(unsigned int _frame) override { return (this->createFrame < _frame&& this->endFrame + ROWS >= _frame); }
	bool IsMissNote(unsigned int _frame) override { return (this->endFrame + ROWS < _frame&& this->isAlive); }
	int getEndFrame() { return endFrame; }


};

// 가짜 노트
class LieNote : public Note
{
public:
	LieNote(int _createTime) { this->type = 2; this->createFrame = _createTime; };
	~LieNote() {};
	int getNoteLength() override { return 1; }
	bool IsActive(unsigned int _frame) override { return (this->createFrame < _frame&& this->createFrame + ROWS >= _frame); }
	bool IsMissNote(unsigned int _frame) override { return this->createFrame + ROWS < _frame&& this->isAlive; }


};

// 가짜 롱노트
class LieSectionNote : public Note
{
	int sectionTime; // 지속되는 시간 (시작점은 createTime을 기준)
	int endFrame;	// 종료되야 하는 frame

public:
	LieSectionNote(int _createTime, int _endFrame) { this->type = 3; this->createFrame = _createTime; this->endFrame = _endFrame; this->sectionTime = this->endFrame - this->createFrame;
	};
	~LieSectionNote() {};
	int getNoteLength() override { return sectionTime; }
	bool IsActive(unsigned int _frame) override { return (this->createFrame < _frame&& this->endFrame + ROWS >= _frame); }
	bool IsMissNote(unsigned int _frame) override { return this->endFrame + ROWS < _frame&& this->isAlive; }

};

enum ITEMTYPE {
	ITEM_01,
	ITEM_02,
	SWITCHLINE
};

// 아이템 노트(4)
class ItemNote : public Note
{
public:
	
	ITEMTYPE itemType;

	ItemNote(int _createTime, ITEMTYPE _itemType) { this->type = 4; this->createFrame = _createTime; this->itemType = _itemType; };
	~ItemNote() {};
	void UseItem(RoundScene* _roundScene);
	int getNoteLength() override { return 1; }
	bool IsActive(unsigned int _frame) override { return (this->createFrame < _frame&& this->createFrame + ROWS >= _frame); }
	bool IsMissNote(unsigned int _frame) override { return this->createFrame + ROWS < _frame&& this->isAlive; }
};
