
#include <iostream>
#include "BankerAlgorithm.h"
using namespace std;

int main() {
	cout << "-----------------------------���м��㷨----------------------------------" << endl;
	BA Banker;
	Banker.Init();
	Banker.Safe();
	Banker.Banker();
	cout << endl;
	cout << __DATE__<<" ";
	cout << __TIME__ << endl<<endl;
	cout << "��ʤΰ����Ʒ" << endl;
	cin.get();
	return 0;
}