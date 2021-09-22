/*
 * @Author: your name
 * @Date: 2020-12-13 10:28:54
 * @LastEditTime: 2020-12-13 10:58:29
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \vscode\clinet.cpp
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
SOCKET socket(int af,int type,int protocol)
{
//af:指定网络地址类型
//type:用于指定套接字类型
//protocol:指定网络协议
    return;
}
//socket 套接字
int sockfd = socket(AF_INEF,SOCK_STREAM,0);
if (sockfd>=0)
{
    printf("create socket successfully\n");
}
else
{
    printf("create Socket Error!\n");
}


struct sockaddr_in
{
    short sin_family;
    u_short sin_port;
    struct in_addr sin_addr;
    char sin_zero[8];
}

int bind(SOCKET s，struct sockaddr_in *name，int namelen);

int main()
{
    return 0;
}
