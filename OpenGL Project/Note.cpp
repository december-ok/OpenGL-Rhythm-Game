#include "Note.h"
#include "Round.h"

float Note::GetHeight()
{
	if (!IsActive()) return -0.0f; // Non-active ������ ���
	return Round::frame - this->createTime; // 1 ~ ROWS ��ȯ
}

bool Note::IsCheckCreate()
{
	return this->createTime == Round::frame;
	
}

bool Note::IsActive()
{
	return this->createTime < Round::frame && this->createTime + ROWS >= Round::frame;
}

void ItemNote::UseItem()
{
}
