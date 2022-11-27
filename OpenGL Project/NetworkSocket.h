#pragma once
#include <WinSock2.h>
#include <Windows.h>
#include <process.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <thread>
#include <vector>
#include "MultiScene.h"

#pragma comment(lib,"ws2_32")
#pragma warning(disable:4996)
#define PORT_NUM	10200
#define MAX_MSG_LEN	256
IN_ADDR GetDefaultMyIP();

using namespace std;


void RecvData(SOCKET);
void Init();
	

class NetworkSocket
{
	MultiScene* scene;
	thread* main;
public:
	int playerNum = -1;
	NetworkSocket(MultiScene* scene);
	~NetworkSocket();

	void sendInput(int line);
	void sendUnput(int line);
	void sendNote(int ÆÇÁ¤, int score, int combo);
};
