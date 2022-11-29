#include "common.h"
#define PORT_NUM	10200
#define BLOG_SIZE	5
#define MAX_MSG_LEN	256

SOCKET SetTCPServer(short pnum, int blog);
void Dolt(SOCKET , SOCKET);
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
	
	SOCKET p1 = NULL;
	SOCKET p2 = NULL;
	while (true) {
		SOCKET dosock = accept(sock, (SOCKADDR*)&cliaddr, &len); // ���� ����
		if (dosock == -1) {
			perror("Accept ����");
			break;
		}
		printf("%s:%d�� ���� ��û ����\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

		if (p1 == NULL) {
			p1 = dosock;
		}
		else if (p2 == NULL) {
			p2 = dosock;
			
			char msg[MAX_MSG_LEN];
			string str1 = "start " + to_string(playerId++);
			string str2 = "start " + to_string(playerId++);

			strcpy(msg, str1.c_str());
			send(p1, msg, sizeof(msg), 0);
			memset(msg, 0, MAX_MSG_LEN);

			strcpy(msg, str2.c_str());
			send(p2, msg, sizeof(msg), 0);

			thread* t1 = new thread(Dolt, p1, p2);
			thread* t2 = new thread(Dolt, p2, p1);
			threadList.push_back(t1);
			threadList.push_back(t2);

			p1 = NULL;
			p2 = NULL;
		}
	}
	
	for (auto t : threadList) {
		t->join();
	}
}

void Dolt(SOCKET dosock, SOCKET target) {
	char msg[MAX_MSG_LEN] = "";
	while (recv(dosock, msg, sizeof(msg), 0) > 0) {
		printf("recv:%s\n", msg);
		send(target, msg, sizeof(msg), 0);	
		memset(msg, 0, MAX_MSG_LEN);
	}
	closesocket(dosock);
}
