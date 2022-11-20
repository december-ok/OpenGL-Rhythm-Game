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
	WSAStartup(MAKEWORD(2, 2), &wsadata); // 윈속 초기화
	char server_ip[40] = "172.30.208.1";
	SOCKET sock;
	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); // 소켓 생성
	SOCKADDR_IN servaddr = { 0 }; // 서버 주소
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr(server_ip); //GetDefaultMyIP();
	servaddr.sin_port = htons(PORT_NUM);
	int re;
	re = connect(sock, (SOCKADDR*)&servaddr, sizeof(servaddr)); // 연결 시도
	if (re == -1) { return; }
	pure_socket = sock;

	// 서버 접속 성공
	globalScene->state = FINDING_PLAYER;

	thread* recvT = new thread(RecvData, sock);

	recvT->join();

	closesocket(sock);
	WSACleanup(); // 윈속 해체화
}

void NetworkSocket::sendInput(int line, int 판정, int score)
{
	if (pure_socket) {
		string str = "input " + to_string(this->playerNum) + " " + to_string(line) + " " + to_string(판정) + " " + to_string(score);
		char msg[MAX_MSG_LEN];
		strcpy(msg, str.c_str());
		send(pure_socket, msg, strlen(msg), 0);
	}
}

void RecvData(SOCKET s) {
	char msg[MAX_MSG_LEN] = "";
	while (true) {
		recv(s, msg, sizeof(msg), 0);
		printf("수신:%s\n", msg);

		// check "start" is included
		if (strstr(msg, "start") != NULL) {
			char* token = strtok(msg, " ");
			token = strtok(NULL, " ");
			int playerNum = atoi(token);
			globalSocket->playerNum = playerNum;
			
			globalScene->state = PLAYING;
		}
		
		// check "input" is included
		if (strstr(msg, "input") != NULL) {
			char* token = strtok(msg, " ");
			token = strtok(NULL, " ");
			int playerNum = atoi(token);

			if (playerNum != globalSocket->playerNum) {
				token = strtok(NULL, " ");
				int line = atoi(token);
				token = strtok(NULL, " ");
				int 판정 = atoi(token);
				token = strtok(NULL, " ");
				int score = atoi(token);

			}
		}
	}
}