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
 * @Descripttion: 对数组元素进行快速排序
 * @param {void*} array 排序数组
 * @param {unsigned int} arrayLen 排序数组的长度
 * @param {short} mode 排序模式 0: 从小到大 1：从大到小
 * @return {void}
 */
void quickSort(void *array, unsigned int arrayLen, short mode);
/**
 * @Descripttion: 在数组中查找特定元素
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
#endif