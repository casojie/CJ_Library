/*
 * @Author       : CaoJie
 * @Date         : 2022-04-15 15:25:18
 * @LastEditors  : CaoJie
 * @LastEditTime : 2022-04-15 15:46:59
 * @Description  : file content
 */
#include <stdio.h>

/**
 * @Descripttion: ����TCP������
 * @param {char} *port ʹ�õĶ˿�
 * @param {char} *ip TCP��IP:һ�㱾�ظĵ��Ե�IP
 * @param {int} maxListenLen �Listen��������
 * @return {int*} ����0�������ɹ����صļ����׽���socket С��0��ʧ��
 */
int creatListenTCPSocket(const char *port, const char *ip, int maxListenLen);
/**
 * @Descripttion: ����UDP������
 * @param {char} *port ʹ�õĶ˿�
 * @param {char} *ip UDP��IP
 * @param {int} maxListenLen ����������
 * @return {*} ����0�������ɹ����صļ����׽���socket С��0��ʧ��
 */
int creatListenUDPSocket(const char *port, const char *ip, int maxListenLen);