/*
 * @Author: your name
 * @Date: 2020-12-24 15:34:08
 * @LastEditTime: 2020-12-25 19:08:17
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \vscode\通信\Client.cpp
 */
#include <stdio.h>
#include <windows.h>
#pragma comment(lib, "ws2_32.lib")

SOCKET ClientSocket;
HWND Hwnd;
int count = 0;

void Communication()
{
	char RecvBuff[1024];
	int rec;
	while (1)
	{
		rec = recv(ClientSocket, RecvBuff, 1023, NULL);
		if (rec > 0)
		{
			RecvBuff[rec] = '\0';
			printf("%s\n",RecvBuff);
			count++;
		}
	}
}

int main()
{
	WSADATA WsaData;
	WSAStartup(MAKEWORD(2, 2), &WsaData);
	if (LOBYTE(WsaData.wVersion) != 2||HIBYTE(WsaData.wVersion) != 2)
	{
		printf("����Э��汾ʧ��!\n");
		return -1;
	}
	printf("����Э��ɹ�!\n");
	
	ClientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (SOCKET_ERROR == ClientSocket)
	{
		printf("����socketʧ��!\n");
		WSACleanup();
		return -2;
	}
	printf("����socket�ɹ�!\n");

	SOCKADDR_IN addr = { 0 };
	addr.sin_family = AF_INET;
	addr.sin_addr.S_un.S_addr = inet_addr("10.195.127.146");
	addr.sin_port = htons(10086); 

	int rec = connect(ClientSocket, (sockaddr*)&addr, sizeof addr);
	if (rec == -1)
	{
		printf("���ӷ�����ʧ��!\n");
		return -1;
	}
	printf("���ӷ������ɹ�!\n");

	char Buff[1024];
	CreateThread(NULL, NULL,(LPTHREAD_START_ROUTINE)Communication,NULL, NULL, NULL);
	while (1)
	{
		memset(Buff, 0, 1024);
		printf("��������������:");
		scanf("%s", Buff);
		send(ClientSocket, Buff, strlen(Buff), NULL);
	}
	return 0;
}
