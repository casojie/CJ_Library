/*
 * @Author       : CaoJie
 * @Date         : 2022-04-19 16:33:34
 * @LastEditors  : CaoJie
 * @LastEditTime : 2022-04-19 16:49:43
 * @Description  : file content
 */
#include <stdio.h>

#include "cj_file.h"
int main()
{
    char *string = "CaoJie\n";
    int stringLen = strlen(string)+1;
    if(stringLen != outputStringToFile("test.txt", string, stringLen, "wb"))
    {
        printf("error\n");
    }

    return 0;
}