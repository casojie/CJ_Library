/*
 * @Author       : CaoJie
 * @Date         : 2022-04-15 11:31:24
 * @LastEditors  : CaoJie
 * @LastEditTime : 2022-04-15 15:58:53
 * @Description  : file content
 */
// string 与 array的区别为：string末尾有‘\0’
#include <stdio.h>

/**
 * @Descripttion: 字符串排序，对字符串按照ASII码进行排序
 * @param {char} *string 目标字符串
 * @param {unsigned int} stringLen 目标字符串长度，注意：包括末尾的'\0'
 * @param {short} mode 排序模式 0：从小到大 1:从大到小
 * @return {*}
 */
void stringSort(char *string, unsigned int stringLen, short mode);
/**
 * @Descripttion: 将desString 添加到srcString中，请确保srcString有足够的空间存储
 * @param {char} *srcString 源字符串
 * @param {char} *desString 目标字符串
 * @param {unsigned int} srcStringLen 源字符串长度
 * @param {unsigned int} desStringLen 目标字符串长度
 * @param {unsigned int} index 插入下标
 * @return {*}
 */
void appendString(char *srcString, char *desString, unsigned int srcStringLen, unsigned int desStringLen, unsigned int index);