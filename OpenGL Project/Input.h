#pragma once
/*������� �Է��� ��� Class�Դϴ�.
����ڰ� Ű�� �Է��ϸ� �� Ŭ���� Ÿ���� ������
Queue�� �� �����Դϴ�.*/
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

