/*
 * @Author       : CaoJie
 * @Date         : 2022-04-18 16:13:55
 * @LastEditors  : CaoJie
 * @LastEditTime : 2022-04-18 16:52:30
 * @Description  : file content
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#include "cj_network.h"

/**
 * @Descripttion: 创建TCP服务器
 * @param {char} *port 使用的端口
 * @param {char} *ip TCP的IP:一般本地改电脑的IP
 * @param {int} maxListenLen 最长Listen监听长度
 * @return {int*} 大于0：创建成功返回的监听套接字socket 小于0：失败
 */
int creatListenTCPSocket(const char *port, const char *ip, int maxListenLen)
{
    int socke = socket(AF_INET, SOCK_STREAM, 0);
    if (socke < 0)
    {
        printf("can't creat source socke\n");
        return -1;
    }

    struct sockaddr_in local;
    memset(&local, 0, sizeof(local));
    local.sin_family = AF_INET;

    if ((local.sin_port = htons((unsigned short)atoi(port))) == 0)
    {
        printf("can't get \"%s\" service entry\n", port);
        return -2;
    }

    if ((local.sin_addr.s_addr = inet_addr(ip)) == INADDR_NONE)
    {
        printf("can't get \"%s\" host entry\n", ip);
        return -3;
    }

    if (bind(socke, (struct sockaddr *)&local, sizeof(local)) != 0)
    {
        printf("can't bind socket and sockaddr\n");
        return -4;
    }

    if (listen(socke, maxListenLen) < 0)
    {
        printf("can't listen socke\n");
        return -5;
    }

    return socke;
}