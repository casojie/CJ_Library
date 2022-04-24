/*
 * @Author       : CaoJie
 * @Date         : 2022-04-15 11:31:24
 * @LastEditors  : CaoJie
 * @LastEditTime : 2022-04-24 09:42:03
 * @Description  : file content
 */
#ifndef _CJ_STRING_H_
#define _CJ_STRING_H_
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
 * @Descripttion: ���ַ������в���ϲ����������µ��ַ���
 * @param {char} *desString ����Ŀ��string
 * @param {char} *srcString ��������
 * @param {int} desStringLen ����Ŀ��stringԭ����Ч����
 * @param {int} maxDesStringLen Ŀ��string����ܴ洢���ֽ���
 * @param {int} srcStringLen �������ݳ���
 * @param {int} index ����λ���±�
 * @param {short} mode �Ƿ�����ʹ��relloc ��desString�������ݣ���malloc�Ⱥ������ɵ�destring����ʹ�� 0:������ 1������
 * @param {char} ** ���غϲ���ɵ�ָ�룬ԭ��desstring��������ʹ��
 * @return {int} �ϲ���ĳ���
 */
int appendString(char *desString, char *srcString, int desStringLen, int maxDesStringLen, int srcStringLen, int index, short mode, char **newStringPinter)
#endif