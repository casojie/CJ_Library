/*
 * @Author       : CaoJie
 * @Date         : 2022-04-18 16:13:55
 * @LastEditors  : CaoJie
 * @LastEditTime : 2022-04-19 17:07:47
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
 * @Descripttion: ����TCP������
 * @param {char} *port ʹ�õĶ˿�
 * @param {char} *ip TCP��IP:һ�㱾�ظĵ��Ե�IP
 * @param {int} maxListenLen �Listen��������
 * @return {int*} ����0�������ɹ����صļ����׽���socket С��0��ʧ��
 */
int creatListenTCPSocket(const char *port, const char *ip, int maxListenLen)
{
    const char *TAG = "creatListenTCPSocket";

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