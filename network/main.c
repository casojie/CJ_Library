/*
 * @Author       : CaoJie
 * @Date         : 2022-04-18 16:39:01
 * @LastEditors  : CaoJie
 * @LastEditTime : 2022-04-18 16:39:02
 * @Description  : file content
 */
#include <stdio.h>
#include "cj_network.h"
int main()
{
    if(0 >= creatListenTCPSocket("65531", "127.0.0.1", 20))
    {
        printf("error");
    }
    while ((1))
    {
        /* code */
    }
    
    return 0;
}