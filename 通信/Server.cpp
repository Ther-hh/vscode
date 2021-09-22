#include <stdio.h>
#include <windows.h>
#pragma comment(lib, "ws2_32.lib")

SOCKADDR_IN SockAddr = { 0 };
int length = sizeof SockAddr;
SOCKET ClientSocket[1024];
int count = 0;

void Communication(int idx)
{
	char Buff[1024];
	int rec;
	while (1)
	{
		rec = recv(ClientSocket[idx], Buff, 1023, NULL);
		if (rec > 0)
		{
			Buff[rec] = 0;
			printf("客户端%d:%s\n", idx, Buff);
			for (int i = 0; i < count; i++)
			{
				send(ClientSocket[i], Buff, strlen(Buff), NULL);
			}
		}
	}
}

int main()
{
	WSADATA WsaData;
	WSAStartup(MAKEWORD(2,2), &WsaData);
	if (LOBYTE(WsaData.wVersion) != 2||HIBYTE(WsaData.wVersion) != 2)
	{
		printf("请求协议版本失败!\n");
		return -1;
	}
	printf("请求协议成功!\n");
	SOCKET ServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (SOCKET_ERROR == ServerSocket)
	{
		printf("创建socket失败!\n");
		WSACleanup();
		return -2;
	}
	printf("创建socket成功!\n");

	SOCKADDR_IN addr = { 0 };
	addr.sin_family = AF_INET;
	addr.sin_addr.S_un.S_addr = inet_addr("10.195.127.146");
	addr.sin_port = htons(10086);  

	int rec = bind(ServerSocket, (struct sockaddr*)&addr, sizeof addr);
    if(-1 == rec)
    {   
		printf("bind失败。\n");
        closesocket(ServerSocket);
        WSACleanup();
        return -2;
    }
    printf("bind成功!\n");

	rec = listen(ServerSocket, 10);
	if (-1 == rec)
	{
		printf("listen失败!\n");
		closesocket(ServerSocket);
		WSACleanup();
		return -2;
	}
	printf("listen成功!\n");

	while (1)
	{
		ClientSocket[count] = accept(ServerSocket, (sockaddr*)&SockAddr, &length);
		if (SOCKET_ERROR == ClientSocket[count])
		{
			printf("服务器宕机了!\n");
			closesocket(ServerSocket);
			WSACleanup();
			return -2;
		}
		printf("有客户端连接到服务器了：%s!\n", inet_ntoa(SockAddr.sin_addr));
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Communication,(char*)count, NULL, NULL);
		count++;
	}
	return 0;
}
