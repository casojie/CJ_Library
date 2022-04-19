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
 * @Descripttion: ������ļ���
 * @param {char} *filePath ���Ŀ���ļ�·��
 * @param {char} *string �������
 * @param {unsigned int} stringLen ���ݳ���
 * @param {char} *mode �ļ���ģʽ������λfopen�Ĵ򿪲���
 * @return {int} ʵ��д���ļ��ĳ���
 */
int outputStringToFile(const char *filePath, char *string, const unsigned int stringLen, const char *mode);
//tty������=======================================================================================================
/**
 * @Descripttion: open��tty�豸
 * @param {char*} devicePath tty�豸��ַ
 * @return {int} С�ڵ���0 ʧ�ܴ����� ����0���ɹ���tty�������
 */
int ttyDeviceOpen(const char* devicePath);
/**
 * @Descripttion: close�ر�tty�豸
 * @param {int} devicefd tty�������
 * @return {*} None
 */
void ttyDeviceClose(int devicefd);
/**
 * @Descripttion: ����Linux tty�豸�����ڵȣ��˺�����ʼ��tty�豸
 * @param {char*} devicePath tty�豸·��
 * @param {unsigned int} baudRate ���õĲ�����
 * @return {int} С�ڵ���0�����󣬴���0��tty�豸���
 */
int ttyDeviceInit(const char* devicePath, unsigned int baudRate);
/**
 * @Descripttion: ����tty�Ĳ����������ʣ�У��λ��ֹͣλ
 * @param {int} devicefd tty�������
 * @param {unsigned int} baudRate ������ 
 * @param {int} dateBits ����λ 7��8
 * @param {char} event У��λ 'N','O','E'
 * @param {int} stopBits ֹͣλ 1,2
 * @return {int} 0:�ɹ� ������ʧ��
 */
int ttyDeviceConfig(int devicefd, unsigned int baudRate, int dateBits, char event, int stopBits);
/**
 * @Descripttion: tty���ͺ���
 * @param {int} devicefd tty�������
 * @param {char} *writeBuff д������
 * @param {unsigned int} writeBuffLen д�볤��
 * @param {unsigned int} timeOut ��ʱʱ��
 * @return {int} С��0 ʧ�ܣ�����0�����ͳ���
 */
int ttyDeviceWrite(int devicefd, char *writeBuff, unsigned int writeBuffLen, unsigned int timeOut);
/**
 * @Descripttion: tty��ȡ����
 * @param {int} devicefd devicefd tty�������
 * @param {char} *readBuff �������ݴ洢��ַ
 * @param {unsigned int} len ������ȡ�ĳ���
 * @param {unsigned int} timeOut ��ʱʱ��
 * @return {int} С��0��ʧ�� ������ʵ�ʶ�ȡ�ĳ��� 
 */
int ttyDeviceRead(int devicefd, char *readBuff, unsigned int len, unsigned int timeOut);

#endif
