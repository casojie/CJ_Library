#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <string.h>
#include <strings.h>
#include <sys/stat.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>

#include "cj_file.h"

/**
 * @Descripttion: 将string 输出到文件上
 * @param {char*} filePath
 * @param {char*} string
 * @param {unsigned int} stringLen
 * @param {short} mode
 * @return {*}
 */
int outputStringToFile(const char *filePath, char *string, const unsigned int stringLen, const short mode);
// tty操作类=======================================================================================================
/**
 * @Descripttion: open打开tty设备
 * @param {char*} devicePath tty设备地址
 * @return {int} 小于等于0 失败错误码 大于0，成功，tty操作句柄
 */
int ttyDeviceOpen(const char *devicePath)
{
    int devicefd = -1;

    if (NULL == devicePath)
    {
        return -1;
    }

    devicefd = open(devicePath, O_RDWR | O_NOCTTY | O_NDELAY);
    if (devicefd < 0)
    {
        printf("\n open %s, failure:%d\n", devicePath, devicefd);
        return -2;
    }

    return devicefd;
}
/**
 * @Descripttion: close关闭tty设备
 * @param {int} devicefd tty操作句柄
 * @return {*} None
 */
void ttyDeviceClose(int devicefd)
{
    if (devicefd < 0)
    {
        return;
    }

    return close(devicefd);
}
/**
 * @Descripttion: 操作Linux tty设备，串口等，此函数初始化tty设备
 * @param {char*} devicePath tty设备路径
 * @param {unsigned int} baudRate 设置的波特率
 * @return {int} 小于等于0，错误，大于0：tty设备句柄
 */
int ttyDeviceInit(const char *devicePath, unsigned int baudRate)
{
    int devicefd = -1;
    int ret = -1;

    if (NULL == devicePath)
    {
        printf("devicePath is NULL \n");
        return -1;
    }

    devicefd = ttyDeviceOpen(devicePath);

    if (devicefd < 0)
    {
        printf("\n %s tty open error......\n", devicePath);
        return -2;
    }

    ret = ttyDeviceConfig(devicefd, baudRate, 8, 'N', 1);
    if (0 != ret)
    {
        printf("\n set tty option failure......\n");
        ttyDeviceClose(devicefd);
        devicefd = -1;
        return -3;
    }

    return devicefd;
}
/**
 * @Descripttion: 设置tty的参数，波特率，校验位，停止位
 * @param {int} devicefd tty操作句柄
 * @param {unsigned int} baudRate 波特率
 * @param {int} dateBits 数据位 7，8
 * @param {char} event 校验位 'N','O','E'
 * @param {int} stopBits 停止位 1,2
 * @return {int} 0:成功 其他：失败
 */
int ttyDeviceConfig(int devicefd, unsigned int baudRate, int dateBits, char event, int stopBits)
{
    struct termios ttyTermios;

    bzero(&ttyTermios, sizeof(ttyTermios));

    if (0 != tcgetattr(devicefd, &ttyTermios))
    {
        printf("tcgetattr error......\n");
        return -1;
    }

    ttyTermios.c_cflag |= (CLOCAL | CREAD);
    ttyTermios.c_cflag &= ~CSIZE;

    ttyTermios.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);

    ttyTermios.c_iflag &= ~(INLCR | ICRNL);
    ttyTermios.c_iflag &= ~(IXON | IXOFF | IXANY);

    ttyTermios.c_oflag &= ~OPOST;
    ttyTermios.c_oflag &= ~(ONLCR | OCRNL);
    ttyTermios.c_oflag &= ~(IXON | IXOFF | IXANY);

    switch (dateBits)
    {
    case 7:
        ttyTermios.c_cflag |= CS7;
        break;
    case 8:
        ttyTermios.c_cflag |= CS8;
        break;
    default:
        ttyTermios.c_cflag |= CS8;
        break;
    }

    switch (event)
    {
    case 'O':
        ttyTermios.c_cflag |= PARENB;
        ttyTermios.c_cflag |= PARODD;
        ttyTermios.c_iflag |= (INPCK | ISTRIP);
        break;
    case 'E':
        ttyTermios.c_iflag |= (INPCK | ISTRIP);
        ttyTermios.c_cflag |= PARENB;
        ttyTermios.c_cflag &= ~PARODD;
        break;
    case 'N':
        ttyTermios.c_cflag &= ~PARENB;
        break;
    default:
        ttyTermios.c_cflag &= ~PARENB;
        break;
    }

    switch (baudRate)
    {
    case 600:
        cfsetispeed(&ttyTermios, B600);
        cfsetospeed(&ttyTermios, B600);
        break;
    case 1200:
        cfsetispeed(&ttyTermios, B1200);
        cfsetospeed(&ttyTermios, B1200);
        break;
    case 2400:
        cfsetispeed(&ttyTermios, B2400);
        cfsetospeed(&ttyTermios, B2400);
        break;
    case 4800:
        cfsetispeed(&ttyTermios, B4800);
        cfsetospeed(&ttyTermios, B4800);
        break;
    case 9600:
        cfsetispeed(&ttyTermios, B9600);
        cfsetospeed(&ttyTermios, B9600);
        break;
    case 19200:
        cfsetispeed(&ttyTermios, B19200);
        cfsetospeed(&ttyTermios, B19200);
        break;
    case 38400:
        cfsetispeed(&ttyTermios, B38400);
        cfsetospeed(&ttyTermios, B38400);
        break;
#ifdef B76800
    case 76800:
        cfsetispeed(&ttyTermios, B76800);
        cfsetospeed(&ttyTermios, B76800);
        break;
#endif
    case 1800:
        cfsetispeed(&ttyTermios, B1800);
        cfsetospeed(&ttyTermios, B1800);
        break;
#ifdef B3600
    case 3600:
        cfsetispeed(&ttyTermios, B3600);
        cfsetospeed(&ttyTermios, B3600);
        break;
#endif
#ifdef B7200
    case 7200:
        cfsetispeed(&ttyTermios, B7200);
        cfsetospeed(&ttyTermios, B7200);
        break;
#endif
#ifdef B14400
    case 14400:
        cfsetispeed(&ttyTermios, B14400);
        cfsetospeed(&ttyTermios, B14400);
        break;
#endif
#ifdef B28800
    case 28800:
        cfsetispeed(&ttyTermios, B28800);
        cfsetospeed(&ttyTermios, B28800);
        break;
#endif
    case 57600:
        cfsetispeed(&ttyTermios, B57600);
        cfsetospeed(&ttyTermios, B57600);
        break;
    case 115200:
        cfsetispeed(&ttyTermios, B115200);
        cfsetospeed(&ttyTermios, B115200);
        break;
    case 230400:
        cfsetispeed(&ttyTermios, B230400);
        cfsetospeed(&ttyTermios, B230400);
        break;
    case 460800:
        cfsetispeed(&ttyTermios, B460800);
        cfsetospeed(&ttyTermios, B460800);
        break;
    default:
        cfsetispeed(&ttyTermios, B9600);
        cfsetospeed(&ttyTermios, B9600);
        break;
    }

    if (stopBits == 1)
    {
        ttyTermios.c_cflag &= ~CSTOPB;
    }
    else if (stopBits == 2)
    {
        ttyTermios.c_cflag |= CSTOPB;
    }

    ttyTermios.c_cc[VTIME] = 1;
    ttyTermios.c_cc[VMIN] = 0;
    tcflush(devicefd, TCIFLUSH);

    if (tcsetattr(devicefd, TCSANOW, &ttyTermios) != 0)
    {
        printf("tcsetattr error......\n");
        return -2;
    }

    return 0;
}

/**
 * @Descripttion: tty发送函数
 * @param {int} devicefd tty操作句柄
 * @param {char} *writeBuff 写入内容
 * @param {unsigned int} writeBuffLen 写入长度
 * @param {unsigned int} timeOut 超时时间
 * @return {int} 小于0 失败，大于0：发送长度
 */
int ttyDeviceWrite(int devicefd, char *writeBuff, unsigned int writeBuffLen, unsigned int timeOut)
{
    int tmpLen = 0;
    int leftLen = 0;
    int writeLen = 0;
    int writeTick = 0;

    if ((devicefd < 0) || (NULL == writeBuff))
    {
        printf("devicefd or writeBuff is NULL\n");
        return -1;
    }

    leftLen = writeBuffLen;
    writeTick = os_get_tick();

    while ((leftLen > 0) && ((os_get_tick() - writeTick) < timeOut))
    {
        tmpLen = write(devicefd, (writeBuff + writeLen), leftLen);
        if (tmpLen == 0)
        {
            tmpLen = 0;
            usleep(2000);
            continue;
        }
        else if (tmpLen < 0)
        {
            return -2;
        }

        leftLen -= tmpLen;
        writeLen += tmpLen;
    }

    return writeLen;
}
/**
 * @Descripttion: tty读取函数
 * @param {int} devicefd devicefd tty操作句柄
 * @param {char} *readBuff 读入内容存储地址
 * @param {unsigned int} len 期望读取的长度
 * @param {unsigned int} timeOut 超时时间
 * @return {int} 小于0：失败 其他：实际读取的长度 
 */
int ttyDeviceRead(int devicefd, char *readBuff, unsigned int len, unsigned int timeOut)
{
    int ret = -1;
    int readLen = 0;
    fd_set FDS;
    struct timeval t;

    if ((devicefd < 0) || (NULL == readBuff))
    {
        return -1;
    }

    t.tv_sec = (timeOut / 1000);
    t.tv_usec = ((timeOut % 1000) * 1000);

    FD_ZERO(&FDS);
    FD_SET(devicefd, &FDS);

    ret = select(devicefd + 1, &FDS, NULL, NULL, &t);
    if (-1 == ret)
    {
        return -2;
    }

    if (ret > 0)
    {
        readLen = read(devicefd, readBuff, len);
        if (readLen < 0)
        {
            return -3;
        }
    }

    return readLen;
}