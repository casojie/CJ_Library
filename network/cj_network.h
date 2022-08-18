/*
 * @Author       : CaoJie
 * @Date         : 2022-04-15 15:25:18
 * @LastEditors  : CaoJie
 * @LastEditTime : 2022-04-19 16:56:31
 * @Description  : file content
 */
#ifndef _CJ_NETWORK_H_
#define _CJ_NETWORK_H_
#include <stdio.h>

/**
 * @Descripttion: 创建TCP服务器
 * @param {char} *port 使用的端口
 * @param {char} *ip TCP的IP:一般本地改电脑的IP
 * @param {int} maxListenLen 最长Listen监听长度
 * @return {int*} 大于0：创建成功返回的监听套接字socket 小于0：失败
 */
int creatListenTCPSocket(const char *port, const char *ip, int maxListenLen);
/**
 * @Descripttion: 创建UDP服务器
 * @param {char} *port 使用的端口
 * @param {char} *ip UDP的IP
 * @param {int} maxListenLen 最大监听长度
 * @return {*} 大于0：创建成功返回的监听套接字socket 小于0：失败
 */
int creatListenUDPSocket(const char *port, const char *ip, int maxListenLen);

#endif