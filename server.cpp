/*
 * @Author: your name
 * @Date: 2020-12-13 10:36:00
 * @LastEditTime: 2020-12-13 10:58:20
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \vscode\server.cpp
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"winsock.h"


WSADATA WSAdata;
if(WSAStartup(MAKEWORD(2,2),&WSAdata)!=0)
{
    printf("winsock init failed");
    return(-1);
}

struct sockaddr_in
{
    short sin_family;
    u_short sin_port;
    struct in_addr sin_addr;
    char sin_zero[8];
}


/*初始化服务器地址*/
address.sin_family = AF_INET;
address.sin_port = htons(PORT);
address.sin_addr.s_addr = INADDR_ANY;
/*绑定*/
int ret = bind(sockfd,(struct sockaddr*)&address,sizeof(address))
if(ret< 0)
    printf("bind failed\n" );
else
    printf( "bind successfully\n");

int main()
{
    return 0;
}
