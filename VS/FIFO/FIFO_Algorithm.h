/*
 * > FIFO�Ƚ��ȳ��û��㷨
 * > Author: incipe(�⻪��)
 * > Language: cpp
 * > File Name: FIFO_Algorithm.h
 * > Created Time: Mon Nov 11 18:47:04 2019
 * > Email: chaoh7461@gmail.com
 * > Description:The story has just bugun!
 */

#ifndef _FIFO_ALGORITHM_
#define _FIFO_ALGORITHM_
#include<iostream>

class FIFO {
public:
	FIFO(int pages_, int blocks_);//���캯��
	~FIFO();//��������
	void Init(int pages, int blocks);//��ʼ��
	void fifoAlgorithm(int pages, int blocks);//FIFO�㷨
	void print(int pages, int blocks);//��ӡ
private:
	int pages;//ҳ����
	int blocks;//�����
};


#endif //_FIFO_ALGORITHM_