#pragma once
class GameInfo
{
public:
	//���� ���� ����
	float HP = 100;
	int score = 0;
	int combo = 0;

	JUDGEMENT recentJudgement = NONE;

	//��� ��¿�
	int perfect = 0;
	int great = 0;
	int normal = 0;
	int bad = 0;
	int miss = 0;
};