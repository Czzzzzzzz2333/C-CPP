/*
 * > OPT����û��㷨
 * > Author: incipe(�⻪��)
 * > Language: cpp
 * > File Name: OPT_Algorithm.h
 * > Created Time: Sat Nov 9 18:47:04 2019
 * > Email: chaoh7461@gmail.com
 * > Description:The story has just bugun!
 */

#ifndef OPT_ALGORITHM_H_INCLUDED
#define OPT_ALGORITHM_H_INCLUDED

#include<iostream>
#include<array>
#include<algorithm>

class OPT {
public:
	OPT(int _pages, int _blocks);//���캯��
	~OPT();//��������
	void Init(int pages, int blocks);//��ʼ��
	void splAlgorithm(int pages, int blocks);//OPT����û��㷨
	void print(int pages, int blocks);//���
private:
	int pages;//ҳ����
	int blocks;//�������
};


#endif // OPT_ALGORITHM_H_INCLUDED
