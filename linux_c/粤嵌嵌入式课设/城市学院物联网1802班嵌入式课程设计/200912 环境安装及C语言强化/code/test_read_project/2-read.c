#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h> //unix std

/* 
	read_file ��ָ�����ļ��ж�ȡ����
		@file: ָ���ļ���
	����ֵ:
		�ɹ� ����0
		ʧ�� ����-1
*/
int read_file(char * file)
{
	int fd = 0;
	ssize_t ret_val = 0;
	char buf[128]  = {0};
	
	/* 1.���ļ� */
	fd = open(file,O_RDONLY);
	if(-1 == fd)
	{
		perror("open file error");
		return -1;
	}

	/* 2.���ļ��ж�ȡ���� */
	ret_val = read(fd,buf,100);
	if(-1 == ret_val)
	{
		perror("read errpr");
	}
	else if(0 == ret_val)
	{
		printf("read zero or read file end\n");
	}
	else
	{
		printf("read size is: %lu Byte\n",ret_val);
		printf("read data is: %s\n",buf);
	}
	
	/* END.�ر��ļ� */
	close(fd);
	
	return 0;
}

