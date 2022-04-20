/*
 * @Author       : CaoJie
 * @Date         : 2022-04-15 11:33:52
 * @LastEditors  : CaoJie
 * @LastEditTime : 2022-04-20 11:30:40
 * @Description  : file content
 */
#ifndef _CJ_ARRAY_H_
#define _CJ_ARRAY_H_
#include <stdio.h>

/**
 * @Descripttion: 对数组元素进行快速排序 请注意修改数组元素类型，默认为int
 * @param {void} *array 排序数组
 * @param {int} start 采用快速排序，要开始排序的下标
 * @param {int} end 采用快速排序，要停止排序的下标
 * @param {char} mode 排序模式 0: 从小到大 1：从大到小
 * @return {*} None
 */
void quickSort(void *array, int start, int end, char mode);
/**
 * @Descripttion: 在数组中查找特定元素, 请注意修改数组元素类型，默认为int
 * @param {void} *array 目标数组
 * @param {unsigned int} arrayLen 素组长度
 * @param {void} *element  目标元素
 * @return {int} 目标元素下标：小于0，查找失败，大于0：目标元素下标
 */
int findElement(void *array, unsigned int arrayLen, void *element);
/**
 * @Descripttion: 在数组中查找值最大元素
 * @param {void} *array 目标数组
 * @param {unsigned int} arrayLen 目标素组长度
 * @param {void} *maxElement 查找的值最大元素
 * @return {unsigned int} 目标元素下标：小于0，查找失败，大于0：目标元素下标
 */
unsigned int findMaxElement(void *array, unsigned int arrayLen, void *maxElement);
/**
 * @Descripttion: 在数组中查找值最小元素
 * @param {void} *array 目标数组
 * @param {unsigned int} arrayLen 目标素组长度
 * @param {void} *maxElement 查找的值最大元素
 * @return {unsigned int} 目标元素下标：小于0，查找失败，大于0：目标元素下标
 */
unsigned int findMinElement(void *array, unsigned int arrayLen, void *minElement);
/**
 * @Descripttion: 将数组以16进制输出
 * @param {void} *array 待输出数组
 * @param {unsigned int} arrayLen 待输出数组长度
 * @return {*} None
 */
void printfHex(void *array, unsigned int arrayLen);
#endif