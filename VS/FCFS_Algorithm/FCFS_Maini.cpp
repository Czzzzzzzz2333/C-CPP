/*
* > FCFS�����㷨
* > Author:incipe(�⻪��)
* > Language:cpp
* > File Name:FCFS_Main.cpp
* > Created Time:Sat Nov 2 21:33:04 2019
* > Email:chaoh7461@gmail.com
*/

#include <bits/stdc++.h>
#include"FCFS_Algorithm.h"
using std::cin;
using std::cout;
using std::endl;

int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);
	FCFS FC[N];
	cout << "-------------------------FCFS�����㷨-----------------------------" << endl
		<< endl;
	cout << "�������������";
	int ProgressNumbers;
	cin >> ProgressNumbers;
	for (int i = 0; i < ProgressNumbers; i++) {
		cout << "�����������\t����ʱ��\t����ʱ��" << endl;
		cin >> FC[i].Progress >> FC[i].ArriveTime >> FC[i].ServerTime;
	}
	return 0;
}