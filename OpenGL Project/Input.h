#pragma once
/*사용자의 입력을 담는 Class입니다.
사용자가 키를 입력하면 이 클래스 타입의 변수가
Queue에 들어갈 예정입니다.*/
class Input
{
	unsigned int input_frame;
	int input_line;
public:
	Input(unsigned int i_f, int i_l);
	~Input();

	unsigned int getInputFrame();
	int getInputLine();
};

