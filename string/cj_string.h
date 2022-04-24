/*
 * @Author       : CaoJie
 * @Date         : 2022-04-15 11:31:24
 * @LastEditors  : CaoJie
 * @LastEditTime : 2022-04-24 09:42:03
 * @Description  : file content
 */
#ifndef _CJ_STRING_H_
#define _CJ_STRING_H_
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
#endif