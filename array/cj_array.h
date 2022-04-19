/*
 * @Author       : CaoJie
 * @Date         : 2022-04-15 11:33:52
 * @LastEditors  : CaoJie
 * @LastEditTime : 2022-04-19 16:55:37
 * @Description  : file content
 */
#ifndef _CJ_ARRAY_H_
#define _CJ_ARRAY_H_
#include <stdio.h>

/**
 * @Descripttion: ������Ԫ�ؽ��п�������
 * @param {void*} array ��������
 * @param {unsigned int} arrayLen ��������ĳ���
 * @param {short} mode ����ģʽ 0: ��С���� 1���Ӵ�С
 * @return {void}
 */
void quickSort(void *array, unsigned int arrayLen, short mode);
/**
 * @Descripttion: �������в����ض�Ԫ��
 * @param {void} *array Ŀ������
 * @param {unsigned int} arrayLen ���鳤��
 * @param {void} *element  Ŀ��Ԫ��
 * @return {int} Ŀ��Ԫ���±꣺С��0������ʧ�ܣ�����0��Ŀ��Ԫ���±�
 */
int findElement(void *array, unsigned int arrayLen, void *element);
/**
 * @Descripttion: �������в���ֵ���Ԫ��
 * @param {void} *array Ŀ������
 * @param {unsigned int} arrayLen Ŀ�����鳤��
 * @param {void} *maxElement ���ҵ�ֵ���Ԫ��
 * @return {unsigned int} Ŀ��Ԫ���±꣺С��0������ʧ�ܣ�����0��Ŀ��Ԫ���±�
 */
unsigned int findMaxElement(void *array, unsigned int arrayLen, void *maxElement);
/**
 * @Descripttion: �������в���ֵ��СԪ��
 * @param {void} *array Ŀ������
 * @param {unsigned int} arrayLen Ŀ�����鳤��
 * @param {void} *maxElement ���ҵ�ֵ���Ԫ��
 * @return {unsigned int} Ŀ��Ԫ���±꣺С��0������ʧ�ܣ�����0��Ŀ��Ԫ���±�
 */
unsigned int findMinElement(void *array, unsigned int arrayLen, void *minElement);
#endif