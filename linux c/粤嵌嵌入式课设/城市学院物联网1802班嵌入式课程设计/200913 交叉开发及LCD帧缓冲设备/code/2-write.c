#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

/*
	��д����,��"hello world"д��2.txt�ļ���
*/
int write_data(void)
{
	int fd = 0;
	ssize_t ret = 0;
	char buf[100] = "hello world";  //Ҫд�������

	//���ļ�
	fd = open("./2.txt",O_RDWR);
	if(-1 == fd)
	{
		perror("open file error");
		return -1;
	}

	//д������
	ret = write(fd,buf,11);
	if(-1 == ret || 0==ret)
	{
		perror("write error or no write");
		return -1;
	}

	//�ر��ļ�
	close(fd);

	return 0;
}


