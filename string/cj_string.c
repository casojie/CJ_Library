/*
 * @Author       : CaoJie
 * @Date         : 2022-04-20 12:10:23
 * @LastEditors  : CaoJie
 * @LastEditTime : 2022-04-20 14:38:56
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
 * @Descripttion: ��desString ��ӵ�srcString�У���ȷ��srcString���㹻�Ŀռ�洢
 * @param {char} *srcString Դ�ַ���
 * @param {char} *desString Ŀ���ַ���
 * @param {unsigned int} srcStringLen Դ�ַ�������
 * @param {unsigned int} desStringLen Ŀ���ַ�������
 * @param {unsigned int} index �����±�
 * @return {*}
 */
void appendString(char *srcString, char *desString, unsigned int srcStringLen, unsigned int desStringLen, unsigned int index)
{
    
}