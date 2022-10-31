#include "Note.h"
#include "Round.h"

float Note::GetHeight()
{
	if (!IsActive()) return -0.0f; // Non-active 상태일 경우
	return Round::frame - this->createTime; // 1 ~ ROWS 반환
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
