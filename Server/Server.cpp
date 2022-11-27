#include "common.h"
#define PORT_NUM	10200
#define BLOG_SIZE	5
#define MAX_MSG_LEN	256

SOCKET SetTCPServer(short pnum, int blog);
void Dolt(SOCKET dosock);
void AcceptLoop(SOCKET sock);


vector <thread*> threadList;
vector <SOCKET> clientList;

int main() {
	WSADATA wsadata;
	WSAStartup(MAKEWORD(2, 2), &wsadata); // ���� �ʱ�ȭ
	SOCKET sock = SetTCPServer(PORT_NUM, BLOG_SIZE); // ��� ���� ����
	AcceptLoop(sock); // Accept Loop
	closesocket(sock);// ���� ����
	WSACleanup(); // ���� ��üȭ
	return 0;
}

SOCKET SetTCPServer(short pnum, int blog) {
	SOCKET sock;
	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); // ���� ����
	SOCKADDR_IN servaddr = { 0 }; // ���� �ּ�
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr = GetDefaultMyIP();
	servaddr.sin_port = htons(pnum);

	int re = 0;
	re = bind(sock, (SOCKADDR*)&servaddr, sizeof(servaddr));
	if (re == -1) { return -1; } // ���� ����
	re = listen(sock, blog);
	if (re == -1) { return -1; } // ���� ����
	printf("%s:%d Setup\n", inet_ntoa(servaddr.sin_addr), pnum);

	return sock;
}

void AcceptLoop(SOCKET sock) {
	SOCKADDR_IN cliaddr = { 0 };
	int len = sizeof(cliaddr);
	int playerId = 1;
	while (true) {
		SOCKET dosock = accept(sock, (SOCKADDR*)&cliaddr, &len); // ���� ����
		if (dosock == -1) {
			perror("Accept ����");
			break;
		}
		printf("%s:%d�� ���� ��û ����\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
		clientList.push_back(dosock);

		thread* t = new thread(Dolt, dosock);
		threadList.push_back(t);

		
		if (clientList.size() == 2) {
			for (auto c : clientList) {
				string str = "start " + to_string(playerId++);
				char msg[MAX_MSG_LEN];
				strcpy(msg, str.c_str());
				send(c, msg, sizeof(msg), 0);
			}
		}
	}
	for (auto t : threadList) {
		t->join();
	}
}

void Dolt(SOCKET dosock) {
	char msg[MAX_MSG_LEN] = "";
	while (recv(dosock, msg, sizeof(msg), 0) > 0) {
		printf("recv:%s\n", msg);
		for (auto c : clientList) {
			send(c, msg, sizeof(msg), 0);
		}
		memset(msg, 0, MAX_MSG_LEN);
	}
	closesocket(dosock);
}
