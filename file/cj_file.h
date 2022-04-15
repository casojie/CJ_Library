/*
 * @Author       : CaoJie
 * @Date         : 2022-04-15 15:48:48
 * @LastEditors  : CaoJie
 * @LastEditTime : 2022-04-15 15:52:28
 * @Description  : file content
 */
#include <stdio.h>

/**
 * @Descripttion: 将string 输出到文件上
 * @param {char*} filePath
 * @param {char*} string
 * @param {unsigned int} stringLen
 * @param {short} mode
 * @return {*}
 */
int outputStringToFile(const char *filePath, char *string, const unsigned int stringLen, const short mode);