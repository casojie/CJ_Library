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
 * @Descripttion: ������ļ���
 * @param {char} *filePath ���Ŀ���ļ�·��
 * @param {char} *string �������
 * @param {unsigned int} stringLen ���ݳ���
 * @param {char} *mode �ļ���ģʽ������λfopen�Ĵ򿪲���
 * @return {int} ʵ��д���ļ��ĳ���
 */
int outputStringToFile(const char *filePath, char *string, const unsigned int stringLen, const char *mode)
{
    const char *TAG = "outputStringToFile";

    if (NULL == filePath || NULL == string || NULL == mode || 0 == stringLen)
    {
        printf("[%s]: argv error\n", TAG);
        return -1;
    }

    FILE *pFile = NULL;
    pFile = fopen(filePath, mode);
    if (NULL == pFile)
    {
        printf("[%s]: fopen \"%s\" error\n", TAG, filePath);
        return -2;
    }

    int writeLen = fwrite(string, 1, stringLen, pFile);
    if (stringLen != writeLen)
    {
        printf("[%s]: write error\n", TAG);
        if (0 < writeLen)
        {
            printf("[%s]: warning: write len is nor string len\n", TAG);
        }
        fclose(pFile);
    }
    fclose(pFile);

    return writeLen;
}
// tty������=======================================================================================================
/**
 * @Descripttion: tty�豸д����ttyDeviceWrite ����������
 * @param {*}
 * @return {*}
 */
int os_get_tick()
{
    static int basic_ms = 0;
    struct timeval struTime;
    int ms = 0;

    memset(&struTime, 0, sizeof(struct timeval));

    if (basic_ms == 0)
    {
        gettimeofday(&struTime, NULL);
        basic_ms = (((int)struTime.tv_sec * 1000) + (struTime.tv_usec / 1000));
    }
    gettimeofday(&struTime, NULL);
    ms = (((int)struTime.tv_sec * 1000) + (struTime.tv_usec / 1000));

    return (ms - basic_ms);
}
/**
 * @Descripttion: open��tty�豸
 * @param {char*} devicePath tty�豸��ַ
 * @return {int} С�ڵ���0 ʧ�ܴ����� ����0���ɹ���tty�������
 */
int ttyDeviceOpen(const char *devicePath)
{
    const char *TAG = "ttyDeviceOpen";
    int devicefd = -1;

    if (NULL == devicePath)
    {
        return -1;
    }

    devicefd = open(devicePath, O_RDWR | O_NOCTTY | O_NDELAY);
    if (devicefd < 0)
    {
        printf("[%s]: \n open %s, failure:%d\n", TAG, devicePath, devicefd);
        return -2;
    }

    return devicefd;
}
/**
 * @Descripttion: close�ر�tty�豸
 * @param {int} devicefd tty�������
 * @return {*} None
 */
void ttyDeviceClose(int devicefd)
{
    if (devicefd < 0)
    {
        return;
    }

    close(devicefd);
}
/**
 * @Descripttion: ����Linux tty�豸�����ڵȣ��˺�����ʼ��tty�豸
 * @param {char*} devicePath tty�豸·��
 * @param {unsigned int} baudRate ���õĲ�����
 * @return {int} С�ڵ���0�����󣬴���0��tty�豸���
 */
int ttyDeviceInit(const char *devicePath, unsigned int baudRate)
{
    const char *TAG = "ttyDeviceInit";
    int devicefd = -1;
    int ret = -1;

    if (NULL == devicePath)
    {
        printf("[%s]: devicePath is NULL \n", TAG);
        return -1;
    }

    devicefd = ttyDeviceOpen(devicePath);

    if (devicefd < 0)
    {
        printf("[%s]: \n %s tty open error......\n", TAG, devicePath);
        return -2;
    }

    ret = ttyDeviceConfig(devicefd, baudRate, 8, 'N', 1);
    if (0 != ret)
    {
        printf("[%s]: \n set tty option failure......\n", TAG);
        ttyDeviceClose(devicefd);
        devicefd = -1;
        return -3;
    }

    return devicefd;
}
/**
 * @Descripttion: ����tty�Ĳ����������ʣ�У��λ��ֹͣλ
 * @param {int} devicefd tty�������
 * @param {unsigned int} baudRate ������
 * @param {int} dateBits ����λ 7��8
 * @param {char} event У��λ 'N','O','E'
 * @param {int} stopBits ֹͣλ 1,2
 * @return {int} 0:�ɹ� ������ʧ��
 */
int ttyDeviceConfig(int devicefd, unsigned int baudRate, int dateBits, char event, int stopBits)
{
    const char *TAG = "ttyDeviceConfig";
    struct termios ttyTermios;

    bzero(&ttyTermios, sizeof(ttyTermios));

    if (0 != tcgetattr(devicefd, &ttyTermios))
    {
        printf("[%s]: tcgetattr error......\n", TAG);
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
        printf("[%s]: tcsetattr error......\n", TAG);
        return -2;
    }

    return 0;
}

/**
 * @Descripttion: tty���ͺ���
 * @param {int} devicefd tty�������
 * @param {char} *writeBuff д������
 * @param {unsigned int} writeBuffLen д�볤��
 * @param {unsigned int} timeOut ��ʱʱ��
 * @return {int} С��0 ʧ�ܣ�����0�����ͳ���
 */
int ttyDeviceWrite(int devicefd, char *writeBuff, unsigned int writeBuffLen, unsigned int timeOut)
{
    const char *TAG = "ttyDeviceWrite";

    int tmpLen = 0;
    int leftLen = 0;
    int writeLen = 0;
    int writeTick = 0;

    if ((devicefd < 0) || (NULL == writeBuff))
    {
        printf("[%s]: devicefd or writeBuff is NULL\n", TAG);
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
 * @Descripttion: tty��ȡ����
 * @param {int} devicefd devicefd tty�������
 * @param {char} *readBuff �������ݴ洢��ַ
 * @param {unsigned int} len ������ȡ�ĳ���
 * @param {unsigned int} timeOut ��ʱʱ��
 * @return {int} С��0��ʧ�� ������ʵ�ʶ�ȡ�ĳ���
 */
int ttyDeviceRead(int devicefd, char *readBuff, unsigned int len, unsigned int timeOut)
{
    const char *TAG = "ttyDeviceRead";

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