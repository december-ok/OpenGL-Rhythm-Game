#pragma once
class Note
{
public:
	int createTime; // ���� �Ǵ� ������ fps
	unsigned char type; // ��Ʈ�� ���� (0 = Normal, 1 = Section, 2 = Lie, 3 = Item)

	~Note() {};
	virtual float GetHeight(unsigned int _frame); // ���� fps���� ��ġ ���� ��ȯ�ϴ� �Լ� (���� Active�� ���°� �ƴ϶�� 0�� ��ȯ)
	bool IsCheckCreate(unsigned int _frame); // ���� �Ǿ�� �ϴ��� üũ�ϰ� ��ȯ�ϴ� �Լ�
	bool IsActive(unsigned int _frame); // ���� ���忡 Active�� �������� üũ�ϰ� ��ȯ�ϴ� �Լ�
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
	int sectionTime; // ���ӵǴ� �ð� (�������� createTime�� ����)

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
