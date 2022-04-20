#include "cj_array.h"

/**
 * @Descripttion: ������Ԫ�ؽ��п������� ��ע���޸�����Ԫ�����ͣ�Ĭ��Ϊint
 * @param {void} *array ��������
 * @param {int} start ���ÿ�������Ҫ��ʼ������±�
 * @param {int} end ���ÿ�������Ҫֹͣ������±�
 * @param {char} mode ����ģʽ 0: ��С���� 1���Ӵ�С
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
        quickSort(array_tmp, start, left_tmp - 1, mode); // �ݹ����
        quickSort(array_tmp, left_tmp + 1, end, mode);
    }
}
/**
 * @Descripttion: �������в����ض�Ԫ��, ��ע���޸�����Ԫ�����ͣ�Ĭ��Ϊint
 * @param {void} *array Ŀ������
 * @param {unsigned int} arrayLen ���鳤��
 * @param {void} *element  Ŀ��Ԫ��
 * @return {int} Ŀ��Ԫ���±꣺С��0������ʧ�ܣ�����0��Ŀ��Ԫ���±�
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
 * @Descripttion: �������в���ֵ���Ԫ�� ��ע���޸�����Ԫ�����ͣ�Ĭ��Ϊint
 * @param {void} *array Ŀ������
 * @param {unsigned int} arrayLen Ŀ�����鳤��
 * @param {void} *maxElement ���ҵ�ֵ���Ԫ��
 * @return {unsigned int} Ŀ��Ԫ���±꣺С��0������ʧ�ܣ�����0��Ŀ��Ԫ���±�
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
 * @Descripttion: �������в���ֵ��СԪ�� ��ע���޸�����Ԫ�����ͣ�Ĭ��Ϊint
 * @param {void} *array Ŀ������
 * @param {unsigned int} arrayLen Ŀ�����鳤��
 * @param {void} *maxElement ���ҵ�ֵ���Ԫ��
 * @return {unsigned int} Ŀ��Ԫ���±꣺С��0������ʧ�ܣ�����0��Ŀ��Ԫ���±�
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
 * @Descripttion: ��������16�������
 * @param {void} *array ���������
 * @param {unsigned int} arrayLen ��������鳤��
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