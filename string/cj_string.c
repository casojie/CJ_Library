/*
 * @Author       : CaoJie
 * @Date         : 2022-04-20 12:10:23
 * @LastEditors  : CaoJie
 * @LastEditTime : 2022-04-20 14:38:56
 * @Description  : file content
 */
#include "cj_string.h"

/**
 * @Descripttion: 字符串排序，对字符串按照ASII码进行排序
 * @param {char} *string 目标字符串
 * @param {unsigned int} stringLen 目标字符串长度，注意：包括末尾的'\0'
 * @param {short} mode 排序模式 0：从小到大 1:从大到小
 * @return {*}
 */
void stringSort(char *string, unsigned int stringLen, short mode)
{
    unsigned int pos = 0;
    unsigned int index = 0;
    unsigned int gap = 0;
    // gap为步长，每次减为原来的一半。
    for (gap = stringLen / 2; gap > 0; gap /= 2)
    {
        // 共gap个组，对每一组都执行直接插入排序
        for (pos = 0; pos < gap; pos++)
        {
            for (index = pos + gap; index < stringLen; index += gap)
            {
                // 如果string[index] < string[index-gap]，则寻找string[index]位置，并将后面数据的位置都后移。
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
 * @Descripttion: 将desString 添加到srcString中，请确保srcString有足够的空间存储
 * @param {char} *srcString 源字符串
 * @param {char} *desString 目标字符串
 * @param {unsigned int} srcStringLen 源字符串长度
 * @param {unsigned int} desStringLen 目标字符串长度
 * @param {unsigned int} index 插入下标
 * @return {*}
 */
void appendString(char *srcString, char *desString, unsigned int srcStringLen, unsigned int desStringLen, unsigned int index)
{
    
}