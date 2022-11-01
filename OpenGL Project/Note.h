#pragma once
class Note
{
public:
	int createTime; // 생성 되는 시점의 fps
	unsigned char type; // 노트의 종류 (0 = Normal, 1 = Section, 2 = Lie, 3 = Item)

	~Note() {};
	virtual float GetHeight(unsigned int _frame); // 현재 fps에서 위치 값을 반환하는 함수 (만약 Active된 상태가 아니라면 0을 반환)
	bool IsCheckCreate(unsigned int _frame); // 생성 되어야 하는지 체크하고 반환하는 함수
	bool IsActive(unsigned int _frame); // 현재 월드에 Active한 상태인지 체크하고 반환하는 함수
};

class NoramlNote : public Note 
{
public:
	NoramlNote(int _createTime) { this->type = 0; this->createTime = _createTime; };
	~NoramlNote() {};
};

class SectionNote : public Note
{
public:
	int sectionTime; // 지속되는 시간 (시작점은 createTime을 기준)

	SectionNote(int _createTime, int _sectionTime) { this->type = 1; this->createTime = _createTime; this->sectionTime = _sectionTime; };
	~SectionNote() {};
};

class LieNote : public Note
{
public:
	LieNote(int _createTime) { this->type = 2; this->createTime = _createTime; };
	~LieNote() {};
};

class ItemNote : public Note
{
public:
	unsigned char itemType;

	ItemNote(int _createTime, unsigned char _itemType) { this->type = 3; this->createTime = _createTime; this->itemType = _itemType; };
	~ItemNote() {};
	void UseItem();
};
