#pragma once
#include "Global.h"
#include "RoundScene.h"
#include <iostream>

class RoundScene;

class Note
{
public:
	int createFrame; // ���� �Ǵ� ������ fps
	bool isAlive = true;	// ���� ��Ʈ: �Է��� �� ��Ʈ
	bool isAccel = false;
	bool isSlow = false;
	unsigned char type; // ��Ʈ�� ���� (0 = Normal, 1 = Section, 2 = Lie, 3 = Item)

	~Note() {};
	int GetHeight(unsigned int _frame); // ���� fps���� ��ġ ���� ��ȯ�ϴ� �Լ� (���� Active�� ���°� �ƴ϶�� 0�� ��ȯ)
	bool IsCheckCreate(unsigned int _frame); // ���� �Ǿ�� �ϴ��� üũ�ϰ� ��ȯ�ϴ� �Լ�
	void killNote();	// ������� �Է��� ������ ��Ʈ�� ����

	virtual bool IsActive(unsigned int _frame) = 0; // ���� ���忡 Active�� �������� üũ�ϰ� ��ȯ�ϴ� ��
	virtual bool IsMissNote(unsigned int _frame) = 0;	// ����ڰ� �Է����� ���� ��Ʈ���� Ȯ��
	virtual int getNoteLength() = 0;	// ��Ʈ�� ����(�Ϲ� ��Ʈ: 1, �ճ�Ʈ: n)
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
	int sectionTime; // ���ӵǴ� �ð� (�������� createTime�� ����)
	int endFrame;	// ����Ǿ� �ϴ� frame
public:

	SectionNote(int _createTime, int _endFrame) { this->type = 1; this->createFrame = _createTime; this->endFrame = _endFrame; this->sectionTime = this->endFrame - this->createFrame; };
	~SectionNote() {};
	int getNoteLength() override { return sectionTime; }
	bool IsActive(unsigned int _frame) override { return (this->createFrame < _frame&& this->endFrame + ROWS >= _frame); }
	bool IsMissNote(unsigned int _frame) override { return (this->endFrame + ROWS < _frame&& this->isAlive); }
	int getEndFrame() { return endFrame; }


};

// ��¥ ��Ʈ
class LieNote : public Note
{
public:
	LieNote(int _createTime) { this->type = 2; this->createFrame = _createTime; };
	~LieNote() {};
	int getNoteLength() override { return 1; }
	bool IsActive(unsigned int _frame) override { return (this->createFrame < _frame&& this->createFrame + ROWS >= _frame); }
	bool IsMissNote(unsigned int _frame) override { return this->createFrame + ROWS < _frame&& this->isAlive; }


};

// ��¥ �ճ�Ʈ
class LieSectionNote : public Note
{
	int sectionTime; // ���ӵǴ� �ð� (�������� createTime�� ����)
	int endFrame;	// ����Ǿ� �ϴ� frame

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

// ������ ��Ʈ(4)
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
