#pragma once
class GameInfo
{
public:
	//게임 진행 정보
	float HP = 100;
	int score = 0;
	int combo = 0;
	int max_combo = 0;
	JUDGEMENT recentJudgement = NONE;

	//결과 출력용
	int perfect = 0;
	int great = 0;
	int normal = 0;
	int bad = 0;
	int miss = 0;
};