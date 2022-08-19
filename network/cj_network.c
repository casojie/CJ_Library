/*
 * @Author       : CaoJie
 * @Date         : 2022-04-18 16:13:55
 * @LastEditors  : CaoJie
 * @LastEditTime : 2022-08-19 11:52:16
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
#include <sys/ioctl.h>
#include <net/if.h>


#include "cj_network.h"

/**
 * @Descripttion: 创建TCP服务器
 * @param {char} *port 使用的端口
 * @param {char} *ip TCP的IP:一般本地改电脑的IP
 * @param {int} maxListenLen 最长Listen监听长度
 * @return {int*} 大于0：创建成功返回的监听套接字socket 小于0：失败
 */
int CreatListenTCPSocket(const char *port, const char *ip, int maxListenLen)
{
    const char *TAG = "CreatListenTCPSocket";

    int socke = socket(AF_INET, SOCK_STREAM, 0);
    if (socke < 0)
    {
        printf("[%s]: can't creat source socke\n", TAG);
        return -1;
    }

    struct sockaddr_in local;
    memset(&local, 0, sizeof(local));
    local.sin_family = AF_INET;

    if ((local.sin_port = htons((unsigned short)atoi(port))) == 0)
    {
        printf("[%s]: can't get \"%s\" service entry\n", TAG, port);
        return -2;
    }

    if ((local.sin_addr.s_addr = inet_addr(ip)) == INADDR_NONE)
    {
        printf("[%s]: can't get \"%s\" host entry\n", TAG, ip);
        return -3;
    }

    if (bind(socke, (struct sockaddr *)&local, sizeof(local)) != 0)
    {
        printf("[%s]: can't bind socket and sockaddr\n", TAG);
        return -4;
    }

    if (listen(socke, maxListenLen) < 0)
    {
        printf("[%s]: can't listen socke\n", TAG);
        return -5;
    }

    return socke;
}

/**
 * @Descripttion: 创建UDP服务器
 * @param {char} *port 使用的端口
 * @param {char} *ip UDP的IP
 * @param {struct sockaddr_in} sockaddr_in结构体
 * @return {*} 大于0：创建成功返回的监听套接字socket 小于0：失败
 */
int CreatListenUDPSocket(const char *port, const char *ip, struct sockaddr_in *sockAddr)
{
    const char *TAG = "CreatListenUDPSocket";

    int socke = socket(AF_INET, SOCK_DGRAM, 0);
    if (socke < 0)
    {
        printf("[%s]: can't creat source socke\n", TAG);
        return -1;
    }

    memset(sockAddr, 0, sizeof(struct sockaddr_in));
    sockAddr->sin_family = AF_INET;

    if ((sockAddr->sin_port = htons((unsigned short)atoi(port))) == 0)
    {
        printf("[%s]: can't get \"%s\" service entry\n", TAG, port);
        return -2;
    }

    if ((sockAddr->sin_addr.s_addr = inet_addr(ip)) == INADDR_NONE)
    {
        printf("[%s]: can't get \"%s\" host entry\n", TAG, ip);
        return -3;
    }

    if (bind(socke, (struct sockaddr *)sockAddr, sizeof(struct sockaddr_in)) != 0)
    {
        printf("[%s]: can't bind socket and sockaddr\n", TAG);
        return -4;
    }

    return socke;
}
/**
 * @Descripttion: 获取网卡当前的IP地址
 * @param {char} *ethName 网卡名称
 * @param {char} *ip 获取到的IP
 * @return {*} 大于0：成功 小于0：失败
 */
int GetLocalIP(const char *ethName, char *ip)
{
    int sock;
    struct sockaddr_in sin;
    struct ifreq ifr;
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1)
    {
        perror("socket");
        return -1;
    }
    strncpy(ifr.ifr_name, ethName, IFNAMSIZ);
    ifr.ifr_name[IFNAMSIZ - 1] = 0;
    if (ioctl(sock, SIOCGIFADDR, &ifr) < 0)
    {
        perror("ioctl");
        return -2;
    }

    memcpy(&sin, &ifr.ifr_addr, sizeof(sin));
    strncpy(ip, inet_ntoa(sin.sin_addr),strlen(inet_ntoa(sin.sin_addr)));
    return 0;
}