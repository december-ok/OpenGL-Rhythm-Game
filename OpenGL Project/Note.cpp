#include "Note.h"
#include "Round.h"
#include <iostream>

float Note::GetHeight()
{
	if (!IsActive()) return -0.0f; // Non-active ������ ���
	return frame - this->createTime; // 1 ~ ROWS ��ȯ
}

bool Note::IsCheckCreate()
{
	return this->createTime == frame;
	
}

bool Note::IsActive()
{
	cout << frame << " | " << this->createTime << endl;
	return (this->createTime < frame && this->createTime + ROWS >= frame);
}

void ItemNote::UseItem()
{
}
