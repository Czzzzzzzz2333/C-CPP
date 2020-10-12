#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

/*
	read_bmp����: ��ȡbmp�ļ��е�����
		@bmp_file: BMP�ļ����ļ���
	����ֵ:
		�ɹ�����0
		ʧ�ܷ���-1
*/
int read_bmp(char *bmp_file)
{
	int fd = 0;
	int file_len = 0;
	int width=0,hight=0,pix_bit=0;
	ssize_t ret = 0;
	unsigned char ch[100] = {0};

	/* 1.���ļ� */
	fd = open(bmp_file,O_RDONLY);
	if(-1 == fd)
	{
		perror("open bmp file error");
		return -1;
	}
	
	/* 2.��ȡ�ļ����� */
	ret = read(fd,ch,32);
	if(-1 == ret)
	{
		perror("read bmp error");
		return -1;
	}
	else if(0 == ret)
	{
		printf("no read data or file end\n");
		return 0;
	}

	/* 3.�������� */
	//�ļ���С  	2~5�ֽ�
	//printf("%x %x %c %c\n",ch[0],ch[1],ch[0],ch[1]);
	//printf("%x %x %x %x\n",ch[2],ch[3],ch[4],ch[5]);
						//  0x36  0x94  0x11  0x00  ==>   0x00119436
						/*
																0x36  ==> 0x00000036
															  0x94<<8 ==> 0x00009400
															0x11<<16  ==> 0x00110000
														  0x00<<24	  ==> 0x00000000
												==>��λ���������ĸ���:      		  0x00119436==>1152054

						*/
	file_len = ch[2] | ch[3]<<8 | ch[4]<<16 | ch[5]<<24;
	printf("file_len:0x%x  %d\n",file_len,file_len);

	width = ch[0x12] | ch[0x13]<<8 | ch[0x14]<<16 | ch[0x15]<<24;
	hight = ch[0x16] | ch[0x17]<<8 | ch[0x18]<<16 | ch[0x19]<<24;
	pix_bit = ch[0x1c] | ch[0x1d]<<8; 
	printf("width: %d\n",width);
	printf("higth: %d\n",hight);
	printf("pix_bit: %d\n",pix_bit);
	
		
	/* END.�ر��ļ� */
	close(fd);

	return 0;
}



