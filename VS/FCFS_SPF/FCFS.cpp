#include<bits/stdc++.h>
using namespace std;

class FCFS_SPF {
public:
	std::string Progress{ "" }; //������
	int ArriveTime{ 0 };        //����ʱ��
	int ServerTime{ 0 };        //����ʱ��
	int StartTime{ 0 };         //��ʼִ��ʱ��
	int EndTime{ 0 };           //����ʱ��
	int TT{ 0 };                //��תʱ��
	double ATT{ 0.0 };          //ƽ����תʱ��
	double QTT{ 0.0 };          //��Ȩ��תʱ��
	double A_QTT{ 0.0 };        //ƽ����Ȩ��תʱ��
};

const int N = 24;
FCFS_SPF FC[N];

void Print(int ProgressNumbers) {
	cout << fixed;
	cout << setprecision(3);
	double ATT;   //ƽ����תʱ��
	double A_QTT; //ƽ����Ȩ��תʱ��
	int sum1 = 0;
	for (int i = 0; i < ProgressNumbers; i++) {
		sum1 += FC[i].TT;
	}
	ATT = static_cast<double>(sum1) / N;
	double sum2 = 0;
	for (int i = 0; i < ProgressNumbers; i++) {
		sum2 += FC[i].QTT;
	}
	A_QTT = static_cast<double>(sum2) / N;
	cout << "\n������  ����ʱ��  ����ʱ��  ��ʼִ��ʱ��  ���ʱ��  ��תʱ��  "
		"��Ȩ��תʱ��\n"
		<< endl;
	for (int i = 0; i < ProgressNumbers; i++) {
		cout << "  " << FC[i].Progress << "\t    " << FC[i].ArriveTime << "\t   "
			<< FC[i].ServerTime << "\t\t" << FC[i].StartTime << "\t   "
			<< FC[i].EndTime << "\t\t" << FC[i].TT << "\t  " << FC[i].QTT << "\t"
			<< endl;
	}
	cout << "\n"
		<< "ƽ����תʱ��Ϊ:" << ATT << endl;
	cout << "ƽ����Ȩ��תʱ��Ϊ:" << A_QTT << endl;
}

void SPF(int ProgressNumbers) {
	cout << "------------------------------------------------SPF�㷨---------------------------------------" << endl;
	// ������ʱ������
	for (int i = 0; i < ProgressNumbers - 1; i++) {
		for (int j = 0; j < ProgressNumbers - i - 1; j++) {
			if (FC[j].ArriveTime > FC[j + 1].ArriveTime) {
				swap(FC[j].ArriveTime, FC[j + 1].ArriveTime);
				swap(FC[j].Progress, FC[j + 1].Progress);
				swap(FC[j].ServerTime, FC[j + 1].ServerTime);
			}
		}
	}
	FC[0].StartTime = FC[0].ArriveTime;
	FC[0].EndTime = FC[0].ServerTime + FC[0].StartTime;
	FC[0].TT = FC[0].EndTime - FC[0].ArriveTime;
	FC[0].QTT =
		static_cast<double>(FC[0].TT) / static_cast<double>(FC[0].ServerTime);
	//������ʱ������
	for (int i = 0; i < ProgressNumbers - 1; i++) {
		for (int j = 1; j < ProgressNumbers - i - 1; j++) {
			if (FC[j].ServerTime > FC[j + 1].ServerTime) {
				swap(FC[j].ServerTime, FC[j + 1].ServerTime);
				swap(FC[j].ArriveTime, FC[j + 1].ArriveTime);
				swap(FC[j].Progress, FC[j + 1].Progress);
			}
		}
	}
	//�����0ʱ����Ľ��̵Ŀ�ʼִ��ʱ��
	for (int i = 1; i < ProgressNumbers; i++) {
		//�����̵Ŀ�ʼִ��ʱ��
		FC[i].StartTime = FC[i - 1].ServerTime + FC[i - 1].StartTime;
		//�����̵Ľ���ʱ��
		FC[i].EndTime = FC[i].ServerTime + FC[i].StartTime;
		//�����̵���תʱ��
		FC[i].TT = FC[i].EndTime - FC[i].ArriveTime;
		FC[i].QTT =
			static_cast<double>(FC[i].TT) / static_cast<double>(FC[i].ServerTime);
	}
	Print(ProgressNumbers);
}

void FCFS(int ProgressNumbers) {
	cout << "------------------------------------------------FCFS�㷨---------------------------------------" << endl;
	// ������ʱ������
	for (int i = 0; i < ProgressNumbers - 1; i++) {
		for (int j = 0; j < ProgressNumbers - i - 1; j++) {
			if (FC[j].ArriveTime > FC[j + 1].ArriveTime) {
				swap(FC[j].ArriveTime, FC[j + 1].ArriveTime);
				swap(FC[j].Progress, FC[j + 1].Progress);
				swap(FC[j].ServerTime, FC[j + 1].ServerTime);
			}
		}
	}
	FC[0].StartTime = FC[0].ArriveTime;
	for (int i = 1; i < ProgressNumbers; i++) {
		FC[i].StartTime = FC[i - 1].ServerTime + FC[i - 1].StartTime;
		//����������̵Ŀ�ʼִ��ʱ��
	}
	for (int i = 0; i < ProgressNumbers; i++) {
		FC[i].EndTime = FC[i].ServerTime + FC[i].StartTime;
		// ��������������ʱ��
	}
	for (int i = 0; i < ProgressNumbers; i++) {
		FC[i].TT = FC[i].EndTime - FC[i].ArriveTime;
		//�������������תʱ��
	}
	for (int i = 0; i < ProgressNumbers; i++) {
		FC[i].QTT =
			static_cast<double>(FC[i].TT) / static_cast<double>(FC[i].ServerTime);
	}
	Print(ProgressNumbers);
}

int main() {
	cout << "-------------------------------SPF��FCFS�����㷨--------------------------"
		"----------"
		<< endl
		<< endl;
	int ProgressNumbers; //������
	cout << "�����������:";
	cin >> ProgressNumbers;
	for (int i = 0; i < ProgressNumbers; i++) {
		cout << "�����������\t����ʱ��\t����ʱ��" << endl;
		cin >> FC[i].Progress >> FC[i].ArriveTime >> FC[i].ServerTime;
	}
	while (1) {
		cout << "��ѡ���㷨1.SPF 2.FCFS 3.�˳� :";
		int choice;
		cin >> choice;
		if (choice == 1) {
			SPF(ProgressNumbers);
		}
		else if (choice == 2) {
			FCFS(ProgressNumbers);
		}
		else if (choice == 3) {
			cout << "ף���������!" << endl;
			break;
		}
		else
			cout << "����Ƿ�,����������!";
	}
	return 0;
}