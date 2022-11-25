#include "Render.h"
#include "RoundScene.h"
#include <vector>
#include <iostream>
#include <random>
#include <bass.h>
#include <stdlib.h>
#include "FireWork.h"

using namespace std;


RoundScene::RoundScene(GameWindow* window, MUSIC id)
{
	this->window;
	
	this->id = id;
	for (int i = 0; i < LINES; i++) {
		line_input[i] = 0;
	}
	
	switch (this->id)
	{
	case CANON:
		this->name = "Cannon Variation";
		this->artist = "Johan Pachelbel";
		this->musicFile = "./Canon.mp3";
		break;
	default:
		break;
	}


	this->init();
	// id�� ���� �뷡 �������� ��������
}

RoundScene::~RoundScene()
{
	free(this->gameInfo);
	free(this->U_Config);
	for (int line = 0; line < LINES;line++) {
		for (size_t i = 0; i < this->notes[line].size(); i++)
		{
			free(this->notes[line][i]);
		}
	}
	
	BASS_Free();

	free(this);
}

void RoundScene::init() {

	this->gameInfo = new GameInfo();
	U_Config = new UserConfig();
	BASS_Init(-1, 44100, 0, 0, NULL);

	this->loadMusic();

	int s;
	float t;

	switch (this->id)
	{
	case CANON:
		// ��� ���۾� �κ�
		// ���� Ȯ�ο� ���� ���̽�
		s = 1020;
		t = 11.25f;

		//this->notes[1].push_back((Note*)new NoramlNote(300));
		this->notes[1].push_back((Note*)new SectionNote(300, 350));


		this->notes[3].push_back((Note*)new NoramlNote(390));
		this->notes[2].push_back((Note*)new NoramlNote(435));
		this->notes[1].push_back((Note*)new NoramlNote(480));
		this->notes[3].push_back((Note*)new NoramlNote(570));
		this->notes[2].push_back((Note*)new NoramlNote(615));
		this->notes[1].push_back((Note*)new NoramlNote(660));
		this->notes[0].push_back((Note*)new NoramlNote(750));
		this->notes[2].push_back((Note*)new NoramlNote(795));
		this->notes[1].push_back((Note*)new NoramlNote(840));

		this->notes[0].push_back((Note*)new NoramlNote(930));
		this->notes[1].push_back((Note*)new NoramlNote(935));
		this->notes[0].push_back((Note*)new NoramlNote(940));
		this->notes[1].push_back((Note*)new NoramlNote(945));
		this->notes[0].push_back((Note*)new NoramlNote(950));
		this->notes[1].push_back((Note*)new NoramlNote(955));
		this->notes[0].push_back((Note*)new NoramlNote(960));
		this->notes[1].push_back((Note*)new NoramlNote(965));
		this->notes[2].push_back((Note*)new NoramlNote(970));
		this->notes[3].push_back((Note*)new NoramlNote(975));
		this->notes[2].push_back((Note*)new NoramlNote(980));
		this->notes[3].push_back((Note*)new NoramlNote(985));
		this->notes[1].push_back((Note*)new NoramlNote(990));
		this->notes[3].push_back((Note*)new NoramlNote(995));
		this->notes[1].push_back((Note*)new NoramlNote(1000));
		this->notes[3].push_back((Note*)new NoramlNote(1005));

		this->notes[1].push_back((Note*)new NoramlNote(s));
		this->notes[3].push_back((Note*)new NoramlNote(s + 1 * t));
		this->notes[2].push_back((Note*)new NoramlNote(s + 2 * t));
		this->notes[3].push_back((Note*)new NoramlNote(s + 3 * t));
		this->notes[1].push_back((Note*)new NoramlNote(s + 4 * t));
		this->notes[3].push_back((Note*)new NoramlNote(s + 5 * t));
		this->notes[2].push_back((Note*)new NoramlNote(s + 6 * t));
		this->notes[3].push_back((Note*)new NoramlNote(s + 7 * t));

		for (int i = 0; i < 8; i++)
		{
			s += 90;
			this->notes[0].push_back((Note*)new NoramlNote(s));
			this->notes[2].push_back((Note*)new NoramlNote(s + 1 * t));
			this->notes[1].push_back((Note*)new NoramlNote(s + 2 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 3 * t));
			this->notes[0].push_back((Note*)new NoramlNote(s + 4 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 5 * t));
			this->notes[1].push_back((Note*)new NoramlNote(s + 6 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 7 * t));

			s += 90;
			this->notes[1].push_back((Note*)new NoramlNote(s));
			this->notes[2].push_back((Note*)new NoramlNote(s + 1 * t));
			this->notes[0].push_back((Note*)new NoramlNote(s + 2 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 3 * t));
			this->notes[1].push_back((Note*)new NoramlNote(s + 4 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 5 * t));
			this->notes[0].push_back((Note*)new NoramlNote(s + 6 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 7 * t));

			s += 90;
			this->notes[2].push_back((Note*)new NoramlNote(s));
			this->notes[3].push_back((Note*)new NoramlNote(s + 1 * t));
			this->notes[1].push_back((Note*)new NoramlNote(s + 2 * t));
			this->notes[3].push_back((Note*)new NoramlNote(s + 3 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 4 * t));
			this->notes[3].push_back((Note*)new NoramlNote(s + 5 * t));
			this->notes[1].push_back((Note*)new NoramlNote(s + 6 * t));
			this->notes[3].push_back((Note*)new NoramlNote(s + 7 * t));

			s += 90;
			this->notes[3].push_back((Note*)new NoramlNote(s));
			this->notes[0].push_back((Note*)new NoramlNote(s + 1 * t));
			this->notes[1].push_back((Note*)new NoramlNote(s + 2 * t));
			this->notes[0].push_back((Note*)new NoramlNote(s + 3 * t));
			this->notes[3].push_back((Note*)new NoramlNote(s + 4 * t));
			this->notes[0].push_back((Note*)new NoramlNote(s + 5 * t));
			this->notes[1].push_back((Note*)new NoramlNote(s + 6 * t));
			this->notes[0].push_back((Note*)new NoramlNote(s + 7 * t));

			s += 90;
			this->notes[1].push_back((Note*)new NoramlNote(s));
			this->notes[2].push_back((Note*)new NoramlNote(s + 1 * t));
			this->notes[3].push_back((Note*)new NoramlNote(s + 2 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 3 * t));
			this->notes[0].push_back((Note*)new NoramlNote(s + 4 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 5 * t));
			this->notes[3].push_back((Note*)new NoramlNote(s + 6 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 7 * t));

			s += 90;
			this->notes[1].push_back((Note*)new NoramlNote(s));
			this->notes[3].push_back((Note*)new NoramlNote(s + 1 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 2 * t));
			this->notes[3].push_back((Note*)new NoramlNote(s + 3 * t));
			this->notes[1].push_back((Note*)new NoramlNote(s + 4 * t));
			this->notes[3].push_back((Note*)new NoramlNote(s + 5 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 6 * t));
			this->notes[3].push_back((Note*)new NoramlNote(s + 7 * t));

			s += 90;
			this->notes[1].push_back((Note*)new NoramlNote(s));
			this->notes[3].push_back((Note*)new NoramlNote(s + 1 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 2 * t));
			this->notes[3].push_back((Note*)new NoramlNote(s + 3 * t));
			this->notes[0].push_back((Note*)new NoramlNote(s + 4 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 5 * t));
			this->notes[0].push_back((Note*)new NoramlNote(s + 6 * t));
			this->notes[3].push_back((Note*)new NoramlNote(s + 7 * t));

			s += 90;
			this->notes[1].push_back((Note*)new NoramlNote(s));
			this->notes[2].push_back((Note*)new NoramlNote(s + 1 * t));
			this->notes[0].push_back((Note*)new NoramlNote(s + 2 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 3 * t));
			this->notes[1].push_back((Note*)new NoramlNote(s + 4 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 5 * t));
			this->notes[3].push_back((Note*)new NoramlNote(s + 6 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 7 * t));

			s += 90;
			this->notes[1].push_back((Note*)new NoramlNote(s));
			this->notes[2].push_back((Note*)new NoramlNote(s + 1 * t));
			this->notes[3].push_back((Note*)new NoramlNote(s + 2 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 3 * t));
			this->notes[0].push_back((Note*)new NoramlNote(s + 4 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 5 * t));
			this->notes[3].push_back((Note*)new NoramlNote(s + 6 * t));
			this->notes[2].push_back((Note*)new NoramlNote(s + 7 * t));
		}

		break;
	default:
		break;
	}
}

void RoundScene::loadMusic() {
	this->stream = BASS_StreamCreateFile(FALSE, this->musicFile.c_str(), 0, 0, 0);
	BASS_ChannelPlay(this->stream, FALSE);
	setMVol(U_Config->M_Vol);
	BASS_ChannelPause(this->stream);

	//������ ���� ���
	QWORD len = BASS_ChannelGetLength(stream, BASS_POS_BYTE);
	double time = BASS_ChannelBytes2Seconds(stream, len);
	endFrame = START_FRAME + (time * FPS);
}

void RoundScene::playEffectSound() {
	HSTREAM effect = BASS_StreamCreateFile(FALSE, "./hit_sound.mp3", 0, 0, 0);
	BASS_ChannelSetAttribute(effect, BASS_ATTRIB_VOL, U_Config->E_Vol);
	BASS_ChannelPlay(effect, FALSE);
}

void RoundScene::playSound() {
	if (this->stream){
		BASS_ChannelPlay(this->stream, FALSE);
	}
}

void RoundScene::pauseSound(bool pause)
{
	if (pause) BASS_ChannelPause(this->stream);
	else {
		if (frame >= START_FRAME) {
			this->playSound();
		}
	}
}

void RoundScene::setMVol(float volume)
{
	bool check = BASS_ChannelSetAttribute(stream, BASS_ATTRIB_VOL, volume);
}

void RoundScene::receiveJudgement(int judge,Note* nott)
{
	//(0 = Normal, 1 = Section, 2 = Lie, 3 = LieSection 4 = Item)
	int type = nott->type;

	//miss �ƴҶ��� Ȯ��
	//item type : 1 : ȸ��, 2 : ����, up 3 : ���� ������ 

	if (type == 4 && judge < 5) {
		ItemNote* tmpNott = (ItemNote*)nott;
		unsigned char itemType = tmpNott->itemType;

		if (itemType == 1) {
			gameInfo->HP += 30;
		}
		else if (itemType == 2) {
			//������ ����(�ӽ�)
			reinforce += 1000;
		}
	}

	//���� up ������ ����
	//����Ʈ < �ش��Ʈ < miss �ش��Ʈ ���� up
	if (reinforce > 0 && judge > 1 && judge < 5) {
		judge--;
	}
	//lie��Ʈ
	//������ ���� �ƴ� �� ó��

	// ��¥ ��Ʈ - ��¥ �ճ�Ʈ�� ����.
	if (type == 2) {
		printf("lie\n");
		if (judge < 6)
			gameInfo->HP -= 30;
	}
	else if (type == 1) {
		calcSectionInfo(judge);
	}
	else calcInfo(judge);

	if (gameInfo->HP > 100)
		gameInfo->HP = 100;
	if (gameInfo->HP <= 0) {
		printf("���\n");
		exit(0);
	}
}

void RoundScene::calcInfo(int judge)
{
	//perfect 1 great 2 normal 3 bad 4 miss : ���� ��� ����
	//��Ʈ ���� : �⺻���� * �޺� ���ʽ�(100combo�� 10% ����) * ���� ����(1.3 1.1 1.0 0.5 0)
	int base = 100;
	int interval = gameInfo->combo / 100;
	float calc = 0;

	switch (judge) {
	case 1:
		gameInfo->HP += 2;
		gameInfo->combo++;
		gameInfo->perfect++;
		gameInfo->recentJudgement = PERFECT;
		calc = base * (1 + (interval * 0.1)) * 1.3;
		break;
	case 2:
		gameInfo->HP += 1;
		gameInfo->combo++;
		gameInfo->great++;
		gameInfo->recentJudgement = GREAT;
		calc = base * (1 + (interval * 0.1)) * 1.1;
		break;
	case 3:
		gameInfo->combo++;
		gameInfo->normal++;
		gameInfo->recentJudgement = NORMAL;
		calc = base * (1 + (interval * 0.1)) * 1;
		break;
	case 4:
		gameInfo->HP -= 5;
		gameInfo->combo = 0;
		gameInfo->bad++;
		gameInfo->recentJudgement = BAD;
		calc = base * 0.5;
		break;
	default:
		gameInfo->HP -= 10;
		gameInfo->combo = 0;
		gameInfo->miss++;
		gameInfo->recentJudgement = MISS;
	}

	int tmp = calc;
	gameInfo->score += tmp;
}

void RoundScene::calcSectionInfo(int judge)
{
	//perfect 1 great 2 normal 3 bad 4 miss : ���� ��� ����
	//��Ʈ ���� : �⺻���� * �޺� ���ʽ�(100combo�� 10% ����) * ���� ����(1.3 1.1 1.0 0.5 0)
	int base = 100;
	int interval = gameInfo->combo / 100;
	float calc = 0;

	switch (judge) {
	case 1:
		gameInfo->HP += 0.2;
		gameInfo->combo++;
		gameInfo->perfect++;
		gameInfo->recentJudgement = PERFECT;
		calc = base * (1 + (interval * 0.1)) * 1.3;
		break;
	case 2:
		gameInfo->HP += 0.1;
		gameInfo->combo++;
		gameInfo->great++;
		gameInfo->recentJudgement = GREAT;
		calc = base * (1 + (interval * 0.1)) * 1.1;
		break;
	case 3:
		gameInfo->combo++;
		gameInfo->normal++;
		gameInfo->recentJudgement = NORMAL;
		calc = base * (1 + (interval * 0.1)) * 1;
		break;
	case 4:
		gameInfo->HP -= 0.5;
		gameInfo->combo = 0;
		gameInfo->bad++;
		gameInfo->recentJudgement = BAD;
		calc = base * 0.5;
		break;
	default:
		gameInfo->HP -= 1;
		gameInfo->combo = 0;
		gameInfo->miss++;
		gameInfo->recentJudgement = MISS;
	}

	int tmp = calc;
	gameInfo->score += tmp;
}

void RoundScene::setInput(unsigned char key) {
	//cout << key;
	if (key == 'd') {
		this->key[0] = true;
		this->renderKey[0] = true;
		this->playEffectSound();
	}
	else if (key == 'f') {
		this->key[1] = true;
		this->renderKey[1] = true;
		this->playEffectSound();
	}
	else if (key == 'j') {
		this->key[2] = true;
		this->renderKey[2] = true;
		this->playEffectSound();
	}
	else if (key == 'k') {
		this->key[3] = true;
		this->renderKey[3] = true;
		this->playEffectSound();
	}
	else if (key == 'p') {
		pause = !(pause);
		pauseSound(pause);
	}
	else if (key == '[') {
		U_Config->M_Vol -= 0.1;
		if (U_Config->M_Vol < 0) U_Config->M_Vol = 0;
		setMVol(U_Config->M_Vol);
	}
	else if (key == ']') {
		U_Config->M_Vol += 0.1;
		if (U_Config->M_Vol > 1) U_Config->M_Vol = 1;
		setMVol(U_Config->M_Vol);
	}
	//ȿ���� ��������
	else if (key == ',') {
		U_Config->E_Vol -= 0.1;
		if (U_Config->E_Vol < 0) U_Config->E_Vol = 0;
	}
	else if (key == '.') {
		U_Config->E_Vol += 0.1;
		if (U_Config->E_Vol > 1) U_Config->E_Vol = 1;
	}
	// ������ �׽�Ʈ��
	else if (key == 'q') {
		blink();
		printf("Blink On!\n");
	}
	else if (key == 'w') {
		setAccelNote(frame);
		printf("Accel On!\n");
	}
	else if (key == 'e') {
		setSlowNote(frame);
		printf("Slow Down On!\n");
	}
	else if (key == 'r') {
		lieNoteOn();
		printf("Lie Note On!\n");
	}
}
void RoundScene::unsetInput(unsigned char key) {
	if (key == 'd') {
		this->key[0] = false;
		this->renderKey[0] = false;
	}
	else if (key == 'f') {
		this->key[1] = false;
		this->renderKey[1] = false;
	}
	else if (key == 'j') {
		this->key[2] = false;
		this->renderKey[2] = false;
	}
	else if (key == 'k') {
		this->key[3] = false;
		this->renderKey[3] = false;
	}
}


void RoundScene::checkSectionNote()
{
	// ��� line�� ���Ͽ� �˻�
	for (int i = 0; i < LINES; i++) {

		// ���� �ճ�Ʈ�� �Է� ������ ��,
		if (section_judgement[i] != -1) {
			
			// ���� �ճ�Ʈ
			Note* current_section =  notes[i][line_input[i]];

			// ���� �������� ���� - �Է���
			if (this->renderKey[i]) {
				// �Է� ���̰� �ճ�Ʈ�� ���̺��� ª�ٸ�, 
				if (current_section->getNoteLength() > section_input[i]) {
					// �ճ�Ʈ ���� �ݺ� ����
					receiveJudgement(section_judgement[i], current_section);

					// input++
					section_input[i] += 1;
				}
				// ���� ���̰� ������ -> �������� �ճ�Ʈ �Է� x
				else if (current_section->getNoteLength() == section_input[i]) {
					// �Է� Ƚ��, ���� �ʱ�ȭ
					section_input[i] = 0;
					section_judgement[i] = -1;
					section_delay[i] = 0;

					// ��Ʈ ����
					this->deleteNote(i, line_input[i]);
					this->setLineInput(i);
				}
			}
			// ���� ������ - �� �̻� �ճ�Ʈ �Է� X
			else {
				// ������ ��Ʈ���� ���� ���ϱ�
				unsigned int end_frame =
					(current_section->createFrame + current_section->getNoteLength()) + (ROWS - JUDGE_HEIGHT);
				unsigned int unset_delay = end_frame - frame;
				
				// ��Ʈ ����
				this->deleteNote(i, line_input[i]);
				this->setLineInput(i);

				// Normal �Է±����� ���� �Է� ���
				if (unset_delay <= NORMAL_FRAME && unset_delay >= -NORMAL_FRAME) {
					receiveJudgement(section_judgement[i], current_section);
				}
				// Bad ���ϴ� ��� Miss��
				else {
					receiveJudgement(5, current_section);
				}

				// �Է� Ƚ��, ���� �ʱ�ȭ
				section_input[i] = 0;
				section_judgement[i] = -1;
				section_delay[i] = 0;

			}

		}
		else {
			continue;
		}

	}
	
}

void RoundScene::checkInput()
{
	// Queue�� ������� �ʴٸ�,
	while (!InputQueue.empty()) {
		// ���� �Է�
		Input* current_input = InputQueue.front();

		int i_line = current_input->getInputLine();
		unsigned int i_frame = current_input->getInputFrame();

		// �Է� ó��
		getNoteDelay(i_line, i_frame);

		// Queue ����
		InputQueue.pop();
		delete current_input;
	}

}

void RoundScene::addInput(int line)
{
	InputQueue.push(new Input(frame, line));
}

int RoundScene::getNearNote(int line, int current_frame)
{
	int note_start = 0;
	int note_end = this->notes[line].size() - 1;
	int vector_center = 0;	// �ӽ� �ʱ�ȭ

	// ������ frame: binary_search
	while (note_start <= note_end) {
		vector_center = (note_start + note_end) / 2;
		if (this->notes[line][vector_center]->createFrame == current_frame) {
			return vector_center;
		}
		// ����������
		else if (this->notes[line][vector_center]->createFrame > current_frame) {
			note_end = vector_center - 1;
		}
		// ��������
		else {
			note_start = vector_center + 1;
		}
	}

	// �ڽź��� �Ʒ��� �ִ� ��Ʈ + �� �� ��Ʈ�� �ƴ� ��,
	if (this->notes[line][vector_center]->createFrame < current_frame && vector_center != this->notes[line].size()) {
		return vector_center + 1;
	}
	else {
		return vector_center;
	}
	
}

void RoundScene::makeLieNoteData(int current_frame)
{
	// �� ���κ� ���� frame�� ���� ����� ��Ʈ index ã��
	int nearest_note[LINES];		// ��Ʈ index
	int nearest_note_frame[LINES];	// ��Ʈ ���� frame

	for (int i = 0; i < LINES; i++) {
		// �� ���κ� ���� ������ ��Ʈ�� ���� - �ش� ��Ʈ���� ����
		nearest_note[i] = getNearNote(i, current_frame);
		nearest_note_frame[i] = this->notes[i][nearest_note[i]]->createFrame;
	}

	for (int i = current_frame; i < current_frame + LIE_DURATION; i++) {
		// �ֽ� update
		for (int j = 0; j < LINES; j++) {
			// �ճ�Ʈ�϶�
			if (this->notes[j][nearest_note[j]]->type == 1) {
				int _length = this->notes[j][nearest_note[j]]->getNoteLength();
				// �ճ�Ʈ�� ���� �����Ӻ��� �Ʒ��� �ִٸ�,
				if (nearest_note_frame[j] + _length < i) {
					nearest_note[j]++;
					nearest_note_frame[j] = this->notes[j][nearest_note[j]]->createFrame;
				}
			}
			// �Ϲݳ�Ʈ�϶�
			else {
				// �ش� ��Ʈ�� �����Դٸ�
				if (nearest_note_frame[j] < i) {
					nearest_note[j]++;
					nearest_note_frame[j] = this->notes[j][nearest_note[j]]->createFrame;
				}
			}
		}
		
		// ��¥ ��Ʈ ���� �� �ִ��� Ȯ�ο�
		bool is_available[LINES];

		// �ش� �����ӿ� �����ϴ� ��Ʈ ��
		int _count = 0;

		// ������Ʈ ������ ����
		int lie_count = LINES - 1;

		// �迭 �ʱ�ȭ
		for (int k = 0; k < LINES; k++) {
			
			// �ճ�Ʈ���?
			if (this->notes[k][nearest_note[k]]->type == 1) {
				int _length = this->notes[k][nearest_note[k]]->getNoteLength();
				// �ճ�Ʈ�� ���̿� �����Ѵٸ�, 
				if (nearest_note_frame[k] + _length > i) {
					is_available[k] = false;
				}
			}
			// �ƴ϶��?
			else {
				// �̹� �ش� line frame�� ��¥ ��Ʈ�� ������
				if (nearest_note_frame[k] == i) {
					is_available[k] = false;
					_count++;
				}
				else {
					is_available[k] = true;
				}

			}
			
		}
		// ���� �� �ִ� ��¥��Ʈ ���� ����
		for (int l = _count; l > 0; l--) {
			// ������ ���� ����
			int rand_line = rand() % 100;
			bool _flag = true;

			for (int m = 0; m < LINES; m++) {

				// ������ ���� ���� - Ŀ���� �ʵ��� mod ����
				rand_line = rand_line % 4;

				// ��¥ ��Ʈ ���� ����
				if (is_available[rand_line]) {
					lie_notes[rand_line].push_back((Note*) new LieNote(i));
					is_available[rand_line++] = false;
					_flag = false;
					break;
				}
				else {
					rand_line++;
					continue;
				}
			}

			// �� �̻� ��¥ ��Ʈ �߰� �Ұ���
			if (_flag) {
				break;
			}
		}
	}	
}

void RoundScene::renderLieNotes()
{
	if (frame + 120 > 10000) return;
	int input_count = 0;
	for (int line = 0; line < LINES; ++line) {
		for (int scope = 0; scope < this->lie_notes[line].size(); ++scope) {
			if (this->lie_notes[line][scope] == nullptr)
				break;
			if (this->lie_notes[line][scope]->IsActive(frame) && this->lie_notes[line][scope]->isAlive) {
				
				// ��Ʈ�� �� ����
				glColor3f(0.96f, 1, 0.98f);

				int height = this->lie_notes[line][scope]->GetHeight(frame);
				int noteLength = this->lie_notes[line][scope]->getNoteLength();

				//printf("%d: line, %d: scope, %d: accel_dist\n", line, scope, frame);

				glRectd(20.f + ((float)line * 4), height, 24.f + ((float)line * 4), height + noteLength);

			}
		}
	}
}

void RoundScene::setLieInput(int line)
{
	lie_input[line]++;
}

void RoundScene::lieNoteOn()
{
	lie_on = true;
	makeLieNoteData(frame);
}

void RoundScene::lieNoteOff()
{
	lie_on = false;
	lie_count = 0;
	// ���� ��Ʈ �Է� Ƚ�� �ʱ�ȭ
	for (int i = 0; i < LINES; i++) {
		lie_input[i] = 0;
	}
	printf("Lie Note Off\n");
}

void RoundScene::lieTimerCheck()
{
	lie_count++;
	if (lie_count > LIE_DURATION + ROWS) {
		lieNoteOff();
		clearLieNoteVector();
	}
}

void RoundScene::clearLieNoteVector()
{
	for (int i = 0; i < LINES; i++) {
		this->lie_notes[i].clear();
		vector<Note*>().swap(this->lie_notes[i]);
	}
}

// �̱���
int RoundScene::isOverlapNote(int start_frame, int end_frame)
{
	for (int i = 0; i < LINES; i++) {

	}
	return 0;
}

void RoundScene::blink()
{
	blink_on = true;
}

void RoundScene::blinkOff()
{
	blink_on = false;
	blink_count = 0;
	printf("Blink Off..\n");
}

void RoundScene::blinkCountUp()
{
	blink_count++;
}

void RoundScene::setAccelNote(int _frame)
{
	// ��� ���ο� ���Ͽ�,
	for (int i = 0; i < LINES; i++) {
		int _count = line_input[i];
		while (true) {
			// �̹� ������� ��Ʈ
			if (this->notes[i][_count]->createFrame < _frame) {
				_count++;
				continue;
			}
			// ������ ��Ʈ��
			else if (this->notes[i][_count]->createFrame <= _frame + ACCEL_DURATION) {
				this->notes[i][_count++]->isAccel = true;
				continue;
			}
			// ������ �Ѿ�� �͵�
			else {
				break;
			}
		}
	}
}

double RoundScene::calcAccelNoteDist(int _time)
{
	if (_time < 0) {
		return 0.0;
	}
	else {
		return ACCEL_INIT_VELOCITY * _time + ACCEL_CONSTANT * _time * _time;

	}
}

void RoundScene::setSlowNote(int _frame)
{
	// ��� ���ο� ���Ͽ�,
	for (int i = 0; i < LINES; i++) {
		int _count = line_input[i];
		while (true) {
			// �̹� ������� ��Ʈ
			if (this->notes[i][_count]->createFrame < _frame) {
				_count++;
				continue;
			}
			// ������ ��Ʈ��
			else if (this->notes[i][_count]->createFrame <= _frame + SLOW_DOWN_DURATION) {
				this->notes[i][_count++]->isSlow = true;
				continue;
			}
			// ������ �Ѿ�� �͵�
			else {
				break;
			}
		}
	}
}

double RoundScene::calcSlowNoteDist(int _time)
{
	if (_time < 0) {
		return 0.0;
	}
	else {
		return SLOW_DOWN_INIT_VELOCITY * _time + SLOW_DOWN_CONSTANT * _time * _time;

	}
}

void RoundScene::update() {
	if (!pause) {
	this->addTime();
	this->deleteMissNode();
	this->checkInput();
	this->checkSectionNote();
	if (blink_on && blink_count >= BLINK_DURATION) {
		blinkOff();
	}
	else if (blink_on) {
		blinkCountUp();
	}

	if (lie_on) {
		lieTimerCheck();
	}

	if (frame == START_FRAME) {
		this->playSound();	// 5�� �� ���� ����
	}
	if (reinforce > 0) reinforce--;
	}
}

void RoundScene::render() {
	//glColor4f(1, 0.8f, 0, 0.5f);
	//drawCircle(20, 20, 3);
	
	
	if (!blink_on || (blink_count/BLINK_DELAY) % 2 == 1) {
		this->renderNotes();
	}

	if (lie_on) {
		this->renderLieNotes();
	}
	this->renderGrid();
	this->renderInputEffect();
	
	this->renderCombo();
	this->renderJudgement();
	this->renderScoreAndInfo();
}

void RoundScene::renderCombo() {
	if (this->gameInfo->combo == 0) {
		return;
	}
	
	float x = 50;
	float y = 50;
	
	string content = to_string(this->gameInfo->combo) + " COMBO";
	
	glPushMatrix();
	glTranslatef(x, y, 0);
	glScalef(0.04, 0.06, 1);
	glColor4f(1, 0.8f, 0, 0.5f);
	glLineWidth(5);
	for (auto c : content)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(x + 0.15f, y, 0);
	glColor4f(0, 0.65f, 1, 0.5f);
	glScalef(0.04, 0.06, 1);
	glLineWidth(5);
	for (auto c : content)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(x + 0.3f, y, 0);
	glColor4f(0.19f, 0.65f, 0.32f, 0.5f);
	glScalef(0.04, 0.06, 1);
	glLineWidth(5);
	for (auto c : content)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(x + 0.45f, y, 0);
	glColor4f(0.9f, 1, 0.15f, 0.5f);
	glScalef(0.04, 0.06, 1);
	glLineWidth(5);
	for (auto c : content)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
	}
	glPopMatrix();
}
void RoundScene::renderJudgement() {
	if (this->gameInfo->recentJudgement == NONE) {
		return;
	}

	float x = 50;
	float y = 36;

	string content = "";
	switch (this->gameInfo->recentJudgement) {
	case PERFECT:
		glColor4f(0.64f, 0.05f, 0.6f, 0.5f);
		content = "PERFECT";
		break;
	case GREAT:
		glColor4f(0.9f, 0.55f, 0.15f, 0.5f);
		content = " GREAT ";
		break;
	case NORMAL:
		glColor4f(0.1f, 0.75f, 0.15f, 0.5f);
		content = " NORMAL";
		break;
	case BAD:
		glColor4f(0.3f, 0.75f, 0.74f, 0.5f);
		content = "  BAD  ";
		break;
	case MISS:
		glColor4f(0.4f, 0.4f, 0.4f, 0.5f);
		content = "  MISS  ";
		break;
	}
	

	glPushMatrix();
	glTranslatef(x, y, 0);
	glScalef(0.04, 0.06, 1);
	glLineWidth(5);
	for (auto c : content)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(x + 0.15f, y, 0);
	glScalef(0.04, 0.06, 1);
	glLineWidth(5);
	for (auto c : content)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(x + 0.3f, y, 0);
	glScalef(0.04, 0.06, 1);
	glLineWidth(5);
	for (auto c : content)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(x + 0.45f, y, 0);
	glScalef(0.04, 0.06, 1);
	glLineWidth(5);
	for (auto c : content)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
	}
	glPopMatrix();
}
void RoundScene::renderScoreAndInfo() {
	float x = 0;
	float y = 105;
	
	string content ="Score: " + to_string(this->gameInfo->score);
	glColor4f(1, 1, 1, 1);
	glRasterPos2f(x, y);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}

	y = 101;
	content = "Life: " + to_string(this->gameInfo->HP);
	glColor4f(1, 1, 1, 1);
	glRasterPos2f(x, y);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}

	x = 50;
	y = 0;
	content = "Music: " + this->artist + " - " + this->name;
	glRasterPos2f(x, y);
	for (auto c : content)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}
}
void RoundScene::renderGrid() {
	glLineWidth(1);
	glColor3f(1, 1, 1);

	//glBegin(GL_LINE_LOOP);
	//glVertex2f(x, y);
	//glVertex2f(x + 1, y);
	//glVertex2f(x + 1, y + 1);
	//glVertex2f(x, y + 1);
	//glEnd();

	for (int i = 0; i < LINES+1; ++i) {
		glBegin(GL_LINE_LOOP);
		glVertex2f(20 + (i * 4), 0);
		glVertex2f(20 + (i * 4), ROWS);
		glEnd();
	}

	glColor3f(1,1,1);
	glRectd(20, 5, 36, 6);
}


void RoundScene::renderNotes() {
	if (frame + 120 > 10000) return;
	int input_count = 0;
	for (int line = 0; line < LINES; ++line) {
		for (int scope = 0; scope < this->notes[line].size(); ++scope) {
			if (this->notes[line][scope] == nullptr)
				break;
			//cout << "fps: " << frame << " | ";
			if (this->notes[line][scope]->IsActive(frame) && this->notes[line][scope]->isAlive) {
				// ��Ʈ�� �� ����
				switch (line)
				{
				case 0:
					glColor3f(1, 0.8f, 0);
					break;
				case 1:
					glColor3f(0, 0.65f, 1);
					break;
				case 2:
					glColor3f(0.19f, 0.65f, 0.32f);
					break;
				case 3:
					glColor3f(0.9f, 1, 0.15f);
				default:
					break;
				}

				// ��¥ ��Ʈ ���� ����
				if (this->notes[line][scope]->type == 2) {
					glColor3f(0.96f, 1, 0.98f);

				}
				// ���� ��Ʈ
				if (this->notes[line][scope]->isAccel) {
					int height = this->notes[line][scope]->GetHeight(frame);
					double accel_dist = ROWS - calcAccelNoteDist(ROWS - height);
					//printf("%d: line, %d: scope, %lf: accel_dist\n", line, scope, accel_dist);

					// �ճ�Ʈ�� ���Ͽ�
					if (this->notes[line][scope]->type == 1) {
						int bottom = 0;
						int accel_end_dist = ROWS - calcAccelNoteDist((ROWS - height) - this->notes[line][scope]->getNoteLength());

						// �ճ�Ʈ�� ���� �Է� ������� ��Ʈ�̰�, �� ��Ʈ�� �Է����� ��
						if (scope == line_input[line] && section_judgement[line] != -1) {
							bottom = JUDGE_HEIGHT;
						}

						// �Ϻ� �ճ�Ʈ�� ȭ�� �Ʒ��� ����
						if (height < 2) {
							glRectd(20.f + ((float)line * 4), bottom, 24.f + ((float)line * 4), accel_end_dist);
						}
						else {
							glRectd(20.f + ((float)line * 4), accel_dist, 24.f + ((float)line * 4), accel_end_dist);
						}
					}
					else {
						glRectd(20.f + ((float)line * 4), accel_dist, 24.f + ((float)line * 4), accel_dist + 1);
					}

				}
				// ���� ��Ʈ
				else if (this->notes[line][scope]->isSlow) {
					int height = this->notes[line][scope]->GetHeight(frame);
					double slow_dist = ROWS - calcSlowNoteDist(ROWS - height);
					//printf("%d: line, %d: scope, %lf: accel_dist\n", line, scope, slow_dist);

					// �ճ�Ʈ�� ���Ͽ�
					if (this->notes[line][scope]->type == 1) {
						int bottom = 0;
						int slow_end_dist = ROWS - calcSlowNoteDist((ROWS - height) - this->notes[line][scope]->getNoteLength());

						// �ճ�Ʈ�� ���� �Է� ������� ��Ʈ�̰�, �� ��Ʈ�� �Է����� ��
						if (scope == line_input[line] && section_judgement[line] != -1) {
							bottom = JUDGE_HEIGHT;
						}

						// �Ϻ� �ճ�Ʈ�� ȭ�� �Ʒ��� ����
						if (height < 2) {
							glRectd(20.f + ((float)line * 4), bottom, 24.f + ((float)line * 4), slow_end_dist);
						}
						else {
							glRectd(20.f + ((float)line * 4), slow_dist, 24.f + ((float)line * 4), slow_end_dist);
						}
					}
					else {
						glRectd(20.f + ((float)line * 4), slow_dist, 24.f + ((float)line * 4), slow_dist + 1);
					}
				}
				else {
					// �ٴ����κ��� ��Ʈ(�ٴ�)������ �Ÿ�
					int height = this->notes[line][scope]->GetHeight(frame);
					int noteLength = this->notes[line][scope]->getNoteLength();

					// �ճ�Ʈ�� ���Ͽ�
					if (this->notes[line][scope]->type == 1) {
						int bottom = 0;
						// �ճ�Ʈ�� ���� �Է� ������� ��Ʈ�̰�, �� ��Ʈ�� �Է����� ��
						if (scope == line_input[line] && section_judgement[line] != -1) {
							bottom = JUDGE_HEIGHT;
						}

						// �Ϻ� �ճ�Ʈ�� ȭ�� �Ʒ��� ����
						if (height < 2) {
							glRectd(20.f + ((float)line * 4), bottom, 24.f + ((float)line * 4), height + noteLength);
						}
						else {
							glRectd(20.f + ((float)line * 4), height, 24.f + ((float)line * 4), height + noteLength);
						}
					}
					else {
						glRectd(20.f + ((float)line * 4), height, 24.f + ((float)line * 4), height + noteLength);
					}
				}
				//}
				//cout << frame << " | " << line << ":" << height << "\n";

				//if (line == 0 && (0 <= height && height <= 10)) {
				////	cout << line << ":" << height << "\n";
				//}
			}
		}
	}
}
void RoundScene::renderInputEffect() {
	for (int i = 0;i < LINES;i++) {
		if (!this->renderKey[i]) continue;
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glVertex2f(20 + (i * 4), 5);
		glColor4f(0, 0, 0, 0); 
		glVertex2f(20 + (i * 4), 40.f);
		glColor4f(0, 0, 0, 0);
		glVertex2f(24 + (i * 4), 40.f);
		glColor3f(1, 1, 1);
		glVertex2f(24 + (i * 4), 5);
		glEnd();
	}
}

void RoundScene::addTime() {
	frame += 1;
	if (frame == endFrame) {
		exit(0);
	}
}

void RoundScene::getNoteDelay(int line, unsigned int i_frame)
{
	int n_frame = this->line_input[line];
	int l_frame = this->lie_input[line];

	// ���� ��Ʈ �˻� �ʿ� + ���� ��Ʈ �Է����� ����
	if (lie_notes[line].size() > 0) {
		
		// ���� ��Ʈ
		if (this->notes[line][n_frame]->createFrame > this->lie_notes[line][l_frame]->createFrame) {

			LieNote* lie_nott = (LieNote*)this->lie_notes[line][l_frame];

			// �Է°� �����Ӱ� ����
			float n_delay = lie_nott->GetHeight(i_frame) - JUDGE_HEIGHT;
			int noteType = lie_nott->type;
			int judgeType = 5;

			// ���� ���� ���� ��Ʈ�� ������
			if (n_delay <= MISS_FRAME) {
				receiveJudgement(judgeType, lie_nott);

				this->deleteNote(line, n_frame);
				this->setLieInput(line);
			}

			return;
		}
		
		
	}
	
	// �Ϲ� ��Ʈ
	Note* nott = this->notes[line][n_frame];

	float n_delay = nott->GetHeight(i_frame) - JUDGE_HEIGHT;
	int noteType = nott->type;
	int judgeType = 5;

	// ���� ���� ���� ��Ʈ�� ������
	if (n_delay <= MISS_FRAME) {

		//��Ʈ ����
		//printf("%d createFrame\n", nott->createFrame);
		//printf("%d inputFrame\n", frame);
		//printf("%f: Delay\n", n_delay);
		if (n_delay <= PERFECT_FRAME && n_delay >= -PERFECT_FRAME) {
			judgeType = 1;
		}
		else if (n_delay <= GREAT_FRAME && n_delay >= -GREAT_FRAME) {
			judgeType = 2;
		}
		else if (n_delay <= NORMAL_FRAME && n_delay >= -NORMAL_FRAME) {
			judgeType = 3;
		}
		else if (n_delay <= BAD_FRAME && n_delay >= -BAD_FRAME) {
			judgeType = 4;
		}
		receiveJudgement(judgeType, nott);

		// �ճ�Ʈ
		if (noteType == 1) {
			section_judgement[line] = judgeType;
			section_delay[line] = n_delay;
			section_input[line] = 1;
		}
		// �̿��� ��Ʈ
		else {
			// ��Ʈ ����
			this->deleteNote(line, n_frame);
			this->setLineInput(line);
		}
	}
	
}

/*�Էµ� ��Ʈ�� �����ϴ� �Լ�. ���� �������� �Ѿ ��Ʈ�� ������ ��*/
void RoundScene::deleteNote(int line, int n_frame)
{
	if (this->notes[line][n_frame] != nullptr) {
		this->notes[line][n_frame]->killNote();
		//printf("%d�� note ����\n", n_frame);
	}

}

int RoundScene::getLineInput(int line) {
	return this->line_input[line];
}

void RoundScene::setLineInput(int line) {
	this->line_input[line]++;
}

void RoundScene::deleteMissNode() {
	// 1 -> LINES�� �ٲ�� ��.
	for (int i = 0; i < LINES; i++) {
		// �Է� ���� ��Ʈ ����
		if (this->notes[i][line_input[i]]->IsMissNote(frame)) {
			Note* nott = this->notes[i][line_input[i]];
			receiveJudgement(6, nott);
			//printf("%d Miss Note ����\n", line_input[i]);
			this->notes[i][line_input[i]]->killNote();
			this->setLineInput(i);
		}
	}
}

///*��ġ�� ��Ʈ���� Miss ó���ϴ� �Լ� - ������ �ٸ� ������ �����־�� ��.*/
//void Round::deleteMissNote() 
//{
//	if (frame >= 50) {
//		if (this->notes[0][frame - 50]) {
//			printf("miss\n");
//			deleteNote(0, frame - 50);
//		}
//
//	}
//}
