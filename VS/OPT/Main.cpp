/*
 * > OPT����û��㷨
 * > Author: incipe(�⻪��)
 * > Language: cpp
 * > File Name: Main.cpp
 * > Created Time: Sat Nov 9 18:47:04 2019
 * > Email: chaoh7461@gmail.com
 * > Description:The story has just bugun!
 */


#include<iostream>
#include<vector>
#include<algorithm>
#include"OPT_Algorithm.h"

using namespace std;

extern int cnt;

int main() {
	cout << "--------------------------------OPT����û��㷨-------------------------------------" << endl;
	int pages_, blocks_;
	cout << "������ҳ����: ";
	cin >> pages_;
	cout << "�������������: ";
	cin >> blocks_;
	OPT OPT(pages_, blocks_);
	OPT.Init(pages_, blocks_);
	OPT.splAlgorithm(pages_, blocks_);
	cout << "�û�����Ϊ:" << cnt - 1 << endl << endl;
	cout << "ȱҳ����Ϊ:" << cnt + blocks_ - 1 << endl << endl;
	cout << "ƽ��ȱҳ��Ϊ:" << static_cast<double>(cnt + blocks_- 1) / static_cast<double>(pages_) << endl << endl;
	return 0;
}
