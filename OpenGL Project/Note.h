#pragma once
class Note
{
public:
	int createFrame; // 생성 되는 시점의 fps
	bool isAlive = true;	// 죽은 노트: 입력이 된 노트
	unsigned char type; // 노트의 종류 (0 = Normal, 1 = Section, 2 = Lie, 3 = Item)

	~Note() {};
	virtual float GetHeight(unsigned int _frame); // 현재 fps에서 위치 값을 반환하는 함수 (만약 Active된 상태가 아니라면 0을 반환)
	bool IsCheckCreate(unsigned int _frame); // 생성 되어야 하는지 체크하고 반환하는 함수
	bool IsActive(unsigned int _frame); // 현재 월드에 Active한 상태인지 체크하고 반환하는 함
	bool IsMissNote(unsigned int _frame);	// 사용자가 입력하지 못한 노트인지 확인
	void killNote();	// 사용자의 입력이 들어오면 노트를 죽임
};

class NoramlNote : public Note
{
public:
	NoramlNote(int _createTime) { this->type = 0; this->createFrame = _createTime; };
	~NoramlNote() {};
};

class SectionNote : public Note
{
public:
	int sectionTime; // 지속되는 시간 (시작점은 createTime을 기준)

	SectionNote(int _createTime, int _sectionTime) { this->type = 1; this->createFrame = _createTime; this->sectionTime = _sectionTime; };
	~SectionNote() {};
};

class LieNote : public Note
{
public:
	LieNote(int _createTime) { this->type = 2; this->createFrame = _createTime; };
	~LieNote() {};
};

class ItemNote : public Note
{
public:
	unsigned char itemType;

	ItemNote(int _createTime, unsigned char _itemType) { this->type = 3; this->createFrame = _createTime; this->itemType = _itemType; };
	~ItemNote() {};
	void UseItem();
};
