#pragma once

#define WIDTH 1270
#define HEIGHT 720
#define COLUMS 127
#define ROWS 108
#define JUDGE_HEIGHT 5

#define FPS 60

#define LINES 4

#define PI 3.14159265358979323846
#define START_FRAME 5*FPS

#define LIE_DURATION 200

#define BLINK_DURATION 400
#define BLINK_DELAY 20

#define ACCEL_DURATION 400
#define ACCEL_INIT_VELOCITY 0
#define ACCEL_CONSTANT 0.0097087		// ���� X: �����ϸ� �������� ��Ʈ�� ���� ����

#define SLOW_DOWN_DURATION 400
#define SLOW_DOWN_INIT_VELOCITY 1.5
#define SLOW_DOWN_CONSTANT  -0.004854	// ���� X: �����ϸ� �������� ��Ʈ�� ���� ����

#define INF 214748364	// �Ϻη� ������ �ڸ� ��

enum MUSIC {
	CANON
};

enum JUDGEMENT {
	NONE,
	PERFECT,
	GREAT,
	NORMAL,
	BAD,
	MISS
};

enum UI_SELECTION {
	SINGLE_PLAY,
	ONLINE_PLAY,
	EXIT
};

enum JUDGEMENT_FRAME {
	PERFECT_FRAME = 5,
	GREAT_FRAME = 10,
	NORMAL_FRAME = 15,
	BAD_FRAME = 20,
	MISS_FRAME = 25

};