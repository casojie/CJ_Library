/*
 * @Author       : CaoJie
 * @Date         : 2022-04-15 15:25:18
 * @LastEditors  : CaoJie
 * @LastEditTime : 2022-08-19 11:51:58
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
int CreatListenTCPSocket(const char *port, const char *ip, int maxListenLen);
/**
 * @Descripttion: 创建UDP服务器
 * @param {char} *port 使用的端口
 * @param {char} *ip UDP的IP
 * @param {struct sockaddr_in} sockaddr_in结构体
 * @return {*} 大于0：创建成功返回的监听套接字socket 小于0：失败
 */
int CreatListenUDPSocket(const char *port, const char *ip, struct sockaddr_in *addr);
/**
 * @Descripttion: 获取网卡当前的IP地址
 * @param {char} *ethName 网卡名称
 * @param {char} *ip 获取到的IP
 * @return {*} 大于0：成功 小于0：失败
 */
int GetLocalIP(const char *ethName, char *ip);

#endif