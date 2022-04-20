#include "cj_array.h"

/**
 * @Descripttion: 对数组元素进行快速排序 请注意修改数组元素类型，默认为int
 * @param {void} *array 排序数组
 * @param {int} start 采用快速排序，要开始排序的下标
 * @param {int} end 采用快速排序，要停止排序的下标
 * @param {char} mode 排序模式 0: 从小到大 1：从大到小
 * @return {*} None
 */
void quickSort(void *array, int start, int end, char mode)
{
    int *array_tmp = (int *)array;

    if (start < end)
    {
        unsigned int left_tmp = start;
        unsigned int right_tmp = end;
        unsigned int temp = array_tmp[start];

        while (left_tmp < right_tmp)
        {
            if (0 == mode)
            {
                while (left_tmp < right_tmp && array_tmp[right_tmp] >= temp)
                    right_tmp--;
                if (left_tmp < right_tmp)
                {
                    array_tmp[left_tmp] = array_tmp[right_tmp];
                    left_tmp++;
                }
                while (left_tmp < right_tmp && array_tmp[left_tmp] < temp)
                    left_tmp++;
                if (left_tmp < right_tmp)
                {
                    array_tmp[right_tmp] = array_tmp[left_tmp];
                    right_tmp--;
                }
            }
            else
            {
                while (left_tmp < right_tmp && array_tmp[right_tmp] <= temp)
                    right_tmp--;
                if (left_tmp < right_tmp)
                {
                    array_tmp[left_tmp] = array_tmp[right_tmp];
                    left_tmp++;
                }
                while (left_tmp < right_tmp && array_tmp[left_tmp] > temp)
                    left_tmp++;
                if (left_tmp < right_tmp)
                {
                    array_tmp[right_tmp] = array_tmp[left_tmp];
                    right_tmp--;
                }
            }
        }
        array_tmp[left_tmp] = temp;
        quickSort(array_tmp, start, left_tmp - 1, mode); // 递归调用
        quickSort(array_tmp, left_tmp + 1, end, mode);
    }
}
/**
 * @Descripttion: 在数组中查找特定元素, 请注意修改数组元素类型，默认为int
 * @param {void} *array 目标数组
 * @param {unsigned int} arrayLen 素组长度
 * @param {void} *element  目标元素
 * @return {int} 目标元素下标：小于0，查找失败，大于0：目标元素下标
 */
int findElement(void *array, unsigned int arrayLen, void *element)
{
    const char *TAG = "findElement";

    int *array_tmp = (int *)array;
    int element_tmp = (*(int *)(element));

    unsigned int pos = 0;
    for (pos = 0; pos < arrayLen; pos++)
    {
        if (array_tmp[pos] == element_tmp)
        {
            return pos;
        }
    }
    return -1;
}
/**
 * @Descripttion: 在数组中查找值最大元素 请注意修改数组元素类型，默认为int
 * @param {void} *array 目标数组
 * @param {unsigned int} arrayLen 目标素组长度
 * @param {void} *maxElement 查找的值最大元素
 * @return {unsigned int} 目标元素下标：小于0，查找失败，大于0：目标元素下标
 */
unsigned int findMaxElement(void *array, unsigned int arrayLen, void *maxElement)
{
    const char *TAG = "findMaxElement";

    int *array_tmp = (int *)array;
    int *maxElement_tmp = (int *)maxElement;

    unsigned int pos = 0;
    unsigned int maxIndex = 0;

    for (pos = 0; pos < arrayLen; pos++)
    {
        if (array_tmp[pos] > array_tmp[maxIndex])
        {
            maxIndex = pos;
        }
    }

    (*maxElement_tmp) = array_tmp[maxIndex];

    return maxIndex;
}
/**
 * @Descripttion: 在数组中查找值最小元素 请注意修改数组元素类型，默认为int
 * @param {void} *array 目标数组
 * @param {unsigned int} arrayLen 目标素组长度
 * @param {void} *maxElement 查找的值最大元素
 * @return {unsigned int} 目标元素下标：小于0，查找失败，大于0：目标元素下标
 */
unsigned int findMinElement(void *array, unsigned int arrayLen, void *minElement)
{
    const char *TAG = "findMinElement";

    int *array_tmp = (int *)array;
    int *minElement_tmp = (int *)minElement;

    unsigned int pos = 0;
    unsigned int minIndex = 0;

    for (pos = 0; pos < arrayLen; pos++)
    {
        if (array_tmp[pos] < array_tmp[minIndex])
        {
            minIndex = pos;
        }
    }

    (*minElement_tmp) = array_tmp[minIndex];

    return minIndex;
}
/**
 * @Descripttion: 将数组以16进制输出
 * @param {void} *array 待输出数组
 * @param {unsigned int} arrayLen 待输出数组长度
 * @return {*} None
 */
void printfHex(void *array, unsigned int arrayLen)
{
    const char *TAG = "printfHex";
    unsigned int pos = 0;
    int *array_tmp = (int *)array;

    printf("[%s]: ", TAG);
    for (pos = 0; pos < arrayLen; pos++)
    {
        printf("0x%04X ", array_tmp[pos]);
    }
    printf("\n");
}