/*
 * @Author       : CaoJie
 * @Date         : 2022-04-15 11:31:24
 * @LastEditors  : CaoJie
 * @LastEditTime : 2022-04-15 15:58:53
 * @Description  : file content
 */
// string �� array������Ϊ��stringĩβ�С�\0��
#include <stdio.h>

/**
 * @Descripttion: �ַ������򣬶��ַ�������ASII���������
 * @param {char} *string Ŀ���ַ���
 * @param {unsigned int} stringLen Ŀ���ַ������ȣ�ע�⣺����ĩβ��'\0'
 * @param {short} mode ����ģʽ 0����С���� 1:�Ӵ�С
 * @return {*}
 */
void stringSort(char *string, unsigned int stringLen, short mode);
/**
 * @Descripttion: ��desString ��ӵ�srcString�У���ȷ��srcString���㹻�Ŀռ�洢
 * @param {char} *srcString Դ�ַ���
 * @param {char} *desString Ŀ���ַ���
 * @param {unsigned int} srcStringLen Դ�ַ�������
 * @param {unsigned int} desStringLen Ŀ���ַ�������
 * @param {unsigned int} index �����±�
 * @return {*}
 */
void appendString(char *srcString, char *desString, unsigned int srcStringLen, unsigned int desStringLen, unsigned int index);