#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

unordered_map<int, int> Track1;
unordered_map<int, int> Move;
double Average;

void FCFS(unordered_map<int, int> Track, int Track_head, int Request) {
  int sum = 0;
  Move[0] = abs(Track_head - Track[0]);
  for (int i = 1; i < Request; i++) {
    Move[i] = abs(Track[i] - Track[i - 1]);
    sum += Move[i];
  }
  cout << "�ŵ���ʼλ��:" << Track_head << endl;
  cout << "�����ʵ���һ���ŵ���"
       << "\t"
       << "�ƶ�����" << endl;
  for (int i = 0; i < Request; i++) {
    cout << "  " << Track[i] << "\t\t\t" << Move[i] << endl;
  }
  cout << "ƽ��Ѱ������:" << static_cast<double>(sum) / Request << endl;
  cout << endl;
}

void S_STF(unordered_map<int, int> Track, int Track_head, int Request) {
  cout << "�ŵ���ʼλ��:" << Track_head << endl;
  cout << "�����ʵ���һ���ŵ���"
       << "\t"
       << "�ƶ�����" << endl;
  int temp[Request], tmp, sum = 0;
  Move[0] = 0x3f3f3f3f;
  for (int j = 0; j < Request; j++) {
    for (int i = 0; i < Request; i++) {
      temp[i] = abs(Track[i] - Track_head); //����������ŵ����ʼ�ŵ��ŵľ���
    }
    for (int i = 0; i < Request; i++) {
      //�����ǰi�±�Ĵŵ���ʱ��С��,��ôd�����Request,�൱��һ����������
      int d = 0;
      for (int k = 0; k < Request; k++) {
        //�ҵ�������С�Ĵŵ�
        if (temp[i] <= temp[k]) {
          d++;
        }
      }
      if (d == Request) {
        cout << "  " << Track[i] << "\t\t\t";
        Move[j] = temp[i];
        cout << Move[j] << endl;
        Track_head = Track[i];
        Track[i] = 0x3f3f3f3f; //ʹ�ù���,����Ҫʹ����.
      }
    }
    sum += Move[j];
  }
  cout << "ƽ��Ѱ������:" << static_cast<double>(sum) / Request << endl;
  cout << endl;
}

void SCAN(unordered_map<int, int> Track, int Track_head, int Request) {
  cout << "�ŵ���ʼλ��:" << Track_head << endl;
  cout << "�����ʵ���һ���ŵ���"
       << "\t"
       << "�ƶ�����" << endl;
  //��ǰ�ŵ���������Ŀ,�ŵ�������Ĵŵ�
  //�жϵ�ǰ�ŵ����������Ŀ
  int inside = 0, outside = 0, in[Request], out[Request], tmp = 0;
  int temp[Request], sum = 0;
  for (int i = 0; i < Request; i++) {
    if (Track[i] >= Track_head) {
      out[outside++] = Track[i];
    } else {
      in[inside++] = Track[i];
    }
  }
  for (int p = 0; p < outside; p++) {
    for (int i = 0; i < outside; i++) {
      temp[i] = abs(out[i] - Track_head);
    }
    for (int i = 0; i < outside; i++) {
      int d = 0;
      for (int j = 0; j < outside; j++) {
        if (temp[i] <= temp[j]) {
          d++;
        }
      }
      if (d == outside) {
        cout << "  " << out[i] << "\t\t\t";
        Move[p] = temp[i];
        cout << Move[i] << endl;
        Track_head = out[i];
        out[i] = 0x3f3f3f3f;
      }
    }
    sum += Move[p];
  }
  for (int p = outside; p < Request; p++) {
    for (int i = 0; i < inside; i++) {
      temp[i] = abs(in[i] - Track_head);
    }
    for (int i = 0; i < inside; i++) {
      int d = 0;
      for (int j = 0; j < inside; j++) {
        if (temp[i] <= temp[j]) {
          d++;
        }
      }
      if (d == inside) {
        cout << "  " << in[i] << "\t\t\t";
        Move[p] = temp[i];
        cout << Move[p] << endl;
        Track_head = in[i];
        in[i] = 0x3f3f3f3f;
      }
    }
    sum += Move[p];
  }
  cout << "ƽ��Ѱ������:" << static_cast<double>(sum) / Request << endl;
  cout << endl;
}

void CSCAN(unordered_map<int, int> Track, int Track_head, int Request) {
  cout << "�ŵ���ʼλ��:" << Track_head << endl;
  cout << "�����ʵ���һ���ŵ���"
       << "\t"
       << "�ƶ�����" << endl;
  //��ǰ�ŵ���������Ŀ,�ŵ�������Ĵŵ�
  //�жϵ�ǰ�ŵ����������Ŀ
  int inside = 0, outside = 0, in[Request], out[Request], tmp = 0;
  int temp[Request], sum = 0;
  for (int i = 0; i < Request; i++) {
    if (Track[i] >= Track_head) {
      out[outside++] = Track[i];
    } else {
      in[inside++] = Track[i];
    }
  }
  for (int p = 0; p < outside; p++) {
    for (int i = 0; i < outside; i++) {
      temp[i] = abs(out[i] - Track_head);
    }
    for (int i = 0; i < outside; i++) {
      int d = 0;
      for (int j = 0; j < outside; j++) {
        if (temp[i] <= temp[j]) {
          d++;
        }
      }
      if (d == outside) {
        cout << "  " << out[i] << "\t\t\t";
        Move[p] = temp[i];
        cout << Move[i] << endl;
        Track_head = out[i];
        out[i] = 0x3f3f3f3f;
      }
    }
    sum += Move[p];
  }
  for (int p = outside; p < Request; p++) {
    for (int i = 0; i < inside; i++) {
      temp[i] = in[i];
    }
    for (int i = 0; i < inside; i++) {
      int d = 0;
      for (int j = 0; j < inside; j++) {
        if (temp[i] <= temp[j]) {
          d++;
        }
      }
      if (d == inside) {
        cout << "  " << in[i] << "\t\t\t";
        Move[p] = abs(Track_head - temp[i]);
        cout << Move[p] << endl;
        Track_head = in[i];
        in[i] = 0x3f3f3f3f;
      }
    }
    sum += Move[p];
  }
  cout << "ƽ��Ѱ������:" << static_cast<double>(sum) / Request << endl;
  cout << endl;
}

int main() {
  cout << "----------------���̵����㷨------------------" << endl;
  int Request; //������
  cout << "������������:";
  cin >> Request;
  srand((unsigned)time(nullptr));
  for (int i = 0; i < Request; i++) {
    Track1[i] = rand() % 201; //����0~200֮��������
  }
  int Track_head; //�ŵ�ͷ,��ʼλ��
  cout << "������ŵ���ʼֵ:";
  cin >> Track_head;
  cout << endl;
  cout << "----------------FCFS���̵����㷨----------------" << endl;
  FCFS(Track1, Track_head, Request);
  cout << "----------------SSTF���̵����㷨----------------" << endl;
  S_STF(Track1, Track_head, Request);
  cout << "----------------SCAN���̵����㷨----------------" << endl;
  SCAN(Track1, Track_head, Request);
  cout << "----------------CSCAN���̵����㷨---------------" << endl;
  CSCAN(Track1, Track_head, Request);
  cout << "\n��лʹ�ã�ף��������죡" << endl;
  return 0;
}