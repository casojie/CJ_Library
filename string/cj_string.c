/*
 * @Author       : CaoJie
 * @Date         : 2022-04-20 12:10:23
 * @LastEditors  : CaoJie
 * @LastEditTime : 2022-04-24 09:41:19
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
 * @Descripttion: 对字符串进行插入合并操作产生新的字符串
 * @param {char} *desString 插入目标string
 * @param {char} *srcString 插入内容
 * @param {int} desStringLen 插入目标string原本有效长度
 * @param {int} maxDesStringLen 目标string最大能存储的字节数
 * @param {int} srcStringLen 插入内容长度
 * @param {int} index 插入位置下标
 * @param {short} mode 是否允许使用relloc 对desString进行扩容，由malloc等函数生成的destring可以使用 0:不允许 1：允许
 * @param {char} ** 返回合并完成的指针，原来desstring可以抛弃使用
 * @return {int} 合并后的长度
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

    unsigned int srcStringLenRet = 0; //合并后长度
    //计算合并后的长度, 先不考虑maxDesStringLen
    if (index <= desStringLen)
    {
        srcStringLenRet = desStringLen + srcStringLen;
    }
    else
    {
        srcStringLenRet = index + srcStringLen;
    }

    //是否需要重新分配内存
    if (1 == mode) // malloc生成的指针
    {
        if (srcStringLenRet > maxDesStringLen) //所需长度已大于des原本最大存储长度, 需要重新分配长度
        {
            newString = (char *)realloc(desString, srcStringLenRet * sizeof(char));
            if (NULL == newString)
            {
                printf("[%s]: realloc return NULL\n", TAG);
                return -2;
            }
            memset(newString + maxDesStringLen, 0, srcStringLenRet - maxDesStringLen); //将新多出的空间初始化
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

    // 合并字符串
    if (index <= maxDesStringLen)
    {
        int pos = 0;
        for (pos = maxDesStringLen - 1 - srcStringLen; pos >= index; pos--)
        {
            newString[pos + srcStringLen] = newString[pos];
        }
    }
    memcpy(newString + index, srcString, srcStringLen);
    *newStringPinter = newString; //返回新创字符串指针

    return srcStringLenRet;
}