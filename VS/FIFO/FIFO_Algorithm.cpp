#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
#include"FIFO_Algorithm.h"
using namespace std;

vector<int>s;
vector<int>a;
int cnt = 0;

FIFO::FIFO(int _pages, int _blocks) :pages{ _pages }, blocks{ _blocks }{}

FIFO::~FIFO() {
	cout << "��ӭʹ��" << endl;
}

void FIFO::Init(int pages, int blocks) {
	cout << "������ҳ��:" << endl;
	int tmp;
	for (int i = 0; i < pages; i++) {
		cin >> tmp;
		s.push_back(tmp);
	}
	cout << "ҳ��Ϊ:" << endl;
	vector<int>::iterator it;
	for (it = s.begin(); it != s.end(); it++) {
		cout << *it << " ";
	}
	for (int i = 0; i < blocks; i++) {
		a.push_back(s[i]);
	}
	FIFO::print(pages, blocks);
}

void FIFO::fifoAlgorithm(int pages, int blocks) {
	for()
}

void FIFO::print(int pages, int blocks) {
	cnt++;
	cout << endl;
	cout << "�����Ϊ:" << endl;
	vector<int>::iterator it_;
	for (it_ = a.begin(); it_ != a.end(); it_++) {
		cout << *it_ << " ";
	}
	cout << endl;//��ӡ
}