/*
 * @Author       : CaoJie
 * @Date         : 2022-04-15 15:48:48
 * @LastEditors  : CaoJie
 * @LastEditTime : 2022-04-19 16:55:01
 * @Description  : file content
 */
#ifndef _CJ_FILE_H_
#define _CJ_FILE_H_
#include <stdio.h>

/**
 * @Descripttion: 输出到文件上
 * @param {char} *filePath 输出目标文件路径
 * @param {char} *string 输出内容
 * @param {unsigned int} stringLen 内容长度
 * @param {char} *mode 文件打开模式，参数位fopen的打开参数
 * @return {int} 实际写入文件的长度
 */
int outputStringToFile(const char *filePath, char *string, const unsigned int stringLen, const char *mode);
//tty操作类=======================================================================================================
/**
 * @Descripttion: open打开tty设备
 * @param {char*} devicePath tty设备地址
 * @return {int} 小于等于0 失败错误码 大于0，成功，tty操作句柄
 */
int ttyDeviceOpen(const char* devicePath);
/**
 * @Descripttion: close关闭tty设备
 * @param {int} devicefd tty操作句柄
 * @return {*} None
 */
void ttyDeviceClose(int devicefd);
/**
 * @Descripttion: 操作Linux tty设备，串口等，此函数初始化tty设备
 * @param {char*} devicePath tty设备路径
 * @param {unsigned int} baudRate 设置的波特率
 * @return {int} 小于等于0，错误，大于0：tty设备句柄
 */
int ttyDeviceInit(const char* devicePath, unsigned int baudRate);
/**
 * @Descripttion: 设置tty的参数，波特率，校验位，停止位
 * @param {int} devicefd tty操作句柄
 * @param {unsigned int} baudRate 波特率 
 * @param {int} dateBits 数据位 7，8
 * @param {char} event 校验位 'N','O','E'
 * @param {int} stopBits 停止位 1,2
 * @return {int} 0:成功 其他：失败
 */
int ttyDeviceConfig(int devicefd, unsigned int baudRate, int dateBits, char event, int stopBits);
/**
 * @Descripttion: tty发送函数
 * @param {int} devicefd tty操作句柄
 * @param {char} *writeBuff 写入内容
 * @param {unsigned int} writeBuffLen 写入长度
 * @param {unsigned int} timeOut 超时时间
 * @return {int} 小于0 失败，大于0：发送长度
 */
int ttyDeviceWrite(int devicefd, char *writeBuff, unsigned int writeBuffLen, unsigned int timeOut);
/**
 * @Descripttion: tty读取函数
 * @param {int} devicefd devicefd tty操作句柄
 * @param {char} *readBuff 读入内容存储地址
 * @param {unsigned int} len 期望读取的长度
 * @param {unsigned int} timeOut 超时时间
 * @return {int} 小于0：失败 其他：实际读取的长度 
 */
int ttyDeviceRead(int devicefd, char *readBuff, unsigned int len, unsigned int timeOut);

#endif
