#include "NetworkSocket.h"

MultiScene* globalScene;
NetworkSocket* globalSocket;

SOCKET pure_socket;

NetworkSocket::NetworkSocket(MultiScene* scene)
{
	this->scene = scene;
	globalScene = scene;
	globalSocket = this;

	this->main = new thread(Init);
}

NetworkSocket::~NetworkSocket()
{
}

void Init()
{
	WSADATA wsadata;
	WSAStartup(MAKEWORD(2, 2), &wsadata); // ���� �ʱ�ȭ
	char server_ip[40] = "192.168.177.1";
	SOCKET sock;
	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); // ���� ����
	SOCKADDR_IN servaddr = { 0 }; // ���� �ּ�
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr(server_ip); //GetDefaultMyIP();
	servaddr.sin_port = htons(PORT_NUM);
	int re;
	re = connect(sock, (SOCKADDR*)&servaddr, sizeof(servaddr)); // ���� �õ�
	if (re == -1) { return; }
	pure_socket = sock;

	// ���� ���� ����
	globalScene->state = FINDING_PLAYER;

	thread* recvT = new thread(RecvData, sock);

	recvT->join();

	closesocket(sock);
	WSACleanup(); // ���� ��üȭ
}

void NetworkSocket::sendInput(int line) {
	if (pure_socket) {
		string str = "input " + to_string(this->playerNum) + " " + to_string(line);
		char msg[MAX_MSG_LEN];
		strcpy(msg, str.c_str());
		send(pure_socket, msg, strlen(msg), 0);
	}
}

void NetworkSocket::sendUnput(int line) {
	if (pure_socket) {
		string str = "unput " + to_string(this->playerNum) + " " + to_string(line);
		char msg[MAX_MSG_LEN];
		strcpy(msg, str.c_str());
		send(pure_socket, msg, strlen(msg), 0);
	}
}

void NetworkSocket::sendNote(int line, int ����, int score, int combo)
{
	if (pure_socket) {
		string str = "note " + to_string(this->playerNum) + " " + to_string(line) + " " + to_string(����) + " " + to_string(score) + " " + to_string(combo);
		char msg[MAX_MSG_LEN];
		strcpy(msg, str.c_str());
		send(pure_socket, msg, strlen(msg), 0);
	}
}

void RecvData(SOCKET s) {
	char msg[MAX_MSG_LEN] = "";
	while (true) {
		recv(s, msg, sizeof(msg), 0);
		printf("����:%s\n", msg);

		if (strstr(msg, "start") != NULL) {
			char* token = strtok(msg, " ");
			token = strtok(NULL, " ");
			int playerNum = atoi(token);
			globalSocket->playerNum = playerNum;
			
			globalScene->state = PLAYING;
			continue;
		}
		
		
		// FORMAT: note playernum line ���� ���� �޺�
		if (strstr(msg, "note") != NULL) {
			char* token = strtok(msg, " ");
			token = strtok(NULL, " ");
			int playerNum = atoi(token);

			if (playerNum != globalSocket->playerNum) {
				token = strtok(NULL, " ");
				int line = atoi(token);
				token = strtok(NULL, " ");
				int ���� = atoi(token);
				token = strtok(NULL, " ");
				int score = atoi(token);
				token = strtok(NULL, " ");
				int combo = atoi(token);

				globalScene->opponentGameInfo->recentJudgement = (JUDGEMENT)����;
				globalScene->opponentGameInfo->score = score;
				globalScene->opponentGameInfo->combo = combo;
			}
			continue;
		}

		// FORMAT: input playernum line
		if (strstr(msg, "input") != NULL) {
			char* token = strtok(msg, " ");
			token = strtok(NULL, " ");
			int playerNum = atoi(token);

			if (playerNum != globalSocket->playerNum) {
				token = strtok(NULL, " ");
				int line = atoi(token);

				globalScene->opponentRenderKey[line] = true;
			}
			continue;
		}

		// FORMAT: unput playernum line
		if (strstr(msg, "unput") != NULL) {
			char* token = strtok(msg, " ");
			token = strtok(NULL, " ");
			int playerNum = atoi(token);

			if (playerNum != globalSocket->playerNum) {
				token = strtok(NULL, " ");
				int line = atoi(token);

				globalScene->opponentRenderKey[line] = false;
			}
			continue;
		}
	}
}