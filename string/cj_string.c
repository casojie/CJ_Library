/*
 * @Author       : CaoJie
 * @Date         : 2022-04-20 12:10:23
 * @LastEditors  : CaoJie
 * @LastEditTime : 2022-04-24 09:41:19
 * @Description  : file content
 */
#include "cj_string.h"

/**
 * @Descripttion: �ַ������򣬶��ַ�������ASII���������
 * @param {char} *string Ŀ���ַ���
 * @param {unsigned int} stringLen Ŀ���ַ������ȣ�ע�⣺����ĩβ��'\0'
 * @param {short} mode ����ģʽ 0����С���� 1:�Ӵ�С
 * @return {*}
 */
void stringSort(char *string, unsigned int stringLen, short mode)
{
    unsigned int pos = 0;
    unsigned int index = 0;
    unsigned int gap = 0;
    // gapΪ������ÿ�μ�Ϊԭ����һ�롣
    for (gap = stringLen / 2; gap > 0; gap /= 2)
    {
        // ��gap���飬��ÿһ�鶼ִ��ֱ�Ӳ�������
        for (pos = 0; pos < gap; pos++)
        {
            for (index = pos + gap; index < stringLen; index += gap)
            {
                // ���string[index] < string[index-gap]����Ѱ��string[index]λ�ã������������ݵ�λ�ö����ơ�
                if (0 == mode)
                {
                    if (string[index] < string[index - gap])
                    {
                        int tmp = string[index];
                        int tmep = index - gap;
                        while (tmep >= 0 && string[tmep] > tmp)
                        {
                            string[tmep + gap] = string[tmep];
                            tmep -= gap;
                        }
                        string[tmep + gap] = tmp;
                    }
                }
                else
                {
                    if (string[index] > string[index - gap])
                    {
                        int tmp = string[index];
                        int tmep = index - gap;
                        while (tmep >= 0 && string[tmep] < tmp)
                        {
                            string[tmep + gap] = string[tmep];
                            tmep -= gap;
                        }
                        string[tmep + gap] = tmp;
                    }
                }
            }
        }
    }
}

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
{
    const char *TAG = "appendString";

    char *newString = NULL;

    if (NULL == desString || NULL == srcString)
    {
        printf("[%s]: pointer is NULL\n", TAG);
        return -1;
    }

    unsigned int srcStringLenRet = 0; //�ϲ��󳤶�
    //����ϲ���ĳ���, �Ȳ�����maxDesStringLen
    if (index <= desStringLen)
    {
        srcStringLenRet = desStringLen + srcStringLen;
    }
    else
    {
        srcStringLenRet = index + srcStringLen;
    }

    //�Ƿ���Ҫ���·����ڴ�
    if (1 == mode) // malloc���ɵ�ָ��
    {
        if (srcStringLenRet > maxDesStringLen) //���賤���Ѵ���desԭ�����洢����, ��Ҫ���·��䳤��
        {
            newString = (char *)realloc(desString, srcStringLenRet * sizeof(char));
            if (NULL == newString)
            {
                printf("[%s]: realloc return NULL\n", TAG);
                return -2;
            }
            memset(newString + maxDesStringLen, 0, srcStringLenRet - maxDesStringLen); //���¶���Ŀռ��ʼ��
            maxDesStringLen = srcStringLenRet;
        }
    }
    else
    {
        newString = desString;
        if (srcStringLenRet > maxDesStringLen)
        {
            printf("[%s]: out of srcString array\n", TAG);
            return -3;
        }
    }

    // �ϲ��ַ���
    if (index <= maxDesStringLen)
    {
        int pos = 0;
        for (pos = maxDesStringLen - 1 - srcStringLen; pos >= index; pos--)
        {
            newString[pos + srcStringLen] = newString[pos];
        }
    }
    memcpy(newString + index, srcString, srcStringLen);
    *newStringPinter = newString; //�����´��ַ���ָ��

    return srcStringLenRet;
}