/*
 * > ���мұ��������㷨
 * > Author:incipe
 * > Language:cpp
 * > File Name:Main.cpp
 * > Created Time:Mon Nov 4 21:33:04 2019
 * > Email:chaoh7461@gmail.com
 */

#include <iostream>
#include "BankerAlgorithm.h"
using namespace std;

int main() {
	cout << "-----------------------------���м��㷨----------------------------------" << endl;
	BA Banker;
	Banker.Init();
	Banker.Safe();
	Banker.Banker();
	cin.get();
	return 0;
}