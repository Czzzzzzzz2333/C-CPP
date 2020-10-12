#include<stdio.h>
#include<time.h>//�����������������ʱ���ͷ�ļ�
#include<stdlib.h>//�������������ͷ�ļ�
#include<math.h>

#define _COUNT 30000 //��Ϊrand()�ķ���ֵ�ķ�Χֻ��0~(2^15)-1��,��˿��Բ���30000�������

unsigned int idex = 0;
unsigned int array[_COUNT], array1[_COUNT], array2[_COUNT], array3[_COUNT], array4[_COUNT], array5[_COUNT], array6[_COUNT], array7[_COUNT];//ȫ�ֱ���
clock_t start[8], stop[8];//clock_t��clock()�������ص�����
double duration[8];//ȫ�ֱ���,��¼ÿ�������ʱ��

void initArray();//��������,����30000�������
void Creatrandnum();//��������,��������
void saveArray();//���������
void Select(int number);//��ѡ��������������
int contains(unsigned int num);//���ĳ�����Ƿ��Ѿ�����������
unsigned int CopyArray(unsigned int arrayn[]);//��ʱ��������������
void saveArray1(unsigned int array1[]);//�����������ı����ַ
void saveArray2(unsigned int array2[]);//ϣ���������ı����ַ
void saveArray3(unsigned int array3[]);//ð���������ı����ַ
void saveArray4(unsigned int array4[]);//�����������ı����ַ
void saveArray5(unsigned int array5[]);//ѡ���������ı����ַ
void saveArray6(unsigned int array6[]);//���������ı����ַ
void saveArray7(unsigned int array7[]);//�鲢�������ı����ַ
void InserSort(unsigned int array1[]);//ֱ�Ӳ���
void BubbleSort(unsigned int array2[]);//ð������
void Shellsort(unsigned int array3[]);//ϣ������
void quicksort(unsigned int array4[], int low, int high);//��������
int split(unsigned int array4[], int low, int high);//��������
void SelectSort(unsigned int array5[]);//ѡ������
void HeapSort(unsigned int array6[]);//������
void Swap(unsigned int* num_a, unsigned int* num_b);//������
void HeapAdjust(unsigned int array6[], int i, int nLength);//������
void MergeSort(unsigned int array7[], int start, int end);//�鲢����
void Merge(unsigned int array7[], int left, int m, int right);//�鲢����

int main()
{
	int number;
	printf("                                      ��ӭ��������ʮ���������о�ϵͳ                   \n\n");
	Creatrandnum();
	for (number = 1; number <= 7; number++) //�ж��ǲ���Ҫ��������,Ŀ����һ���Բ������⼸�������ʱ��,����һ��һ���Ĳ���
	{
		Select(number);
		if (number == 7)
		{
			printf("\n");
			printf("------------------------------------------------------------------\n");
			printf("|ֱ������|ϣ������|ð������|����������|ѡ������| ������ |�鲢����|\n");
			printf("------------------------------------------------------------------\n");
			printf("|%lf|%lf|%lf| %lf |%lf|%lf|%lf|\n", duration[1], duration[2], duration[3], duration[4], duration[5], duration[6], duration[7]);
			printf("------------------------------------------------------------------\n");
		}
	}
	system("pause");
	return 0;
}

void Select(int number)
{
	switch (number)
	{
	case 1:
	{
		CopyArray(array1);
		printf("\n1.��������\n");
		start[1] = clock();//���ڲ��Է�Χ�ڵ�׼������д��clock()����
		InserSort(array1);
		stop[1] = clock();//ֱ�Ӳ����������
		saveArray1(array1);
		printf("ֱ�Ӳ��������%d�����������Ѿ�����\n\n", _COUNT);
		duration[1] = ((double)(stop[1] - start[1])) / CLK_TCK;//CLK_TCK�ǳ���,ÿ�����Զ���ͬ
		printf("%d���������ֱ�Ӳ����������ķѵ�ʱ��Ϊ��ticksΪ:%lf\n", _COUNT, (double)(stop[1] - start[1]));
		printf("%d���������ֱ�Ӳ����������ķѵ�ʱ��Ϊ��durationΪ:%lf\n", _COUNT, duration[1]);//duration�ĵ�λ����
		break;
	}
	case 2:
	{
		CopyArray(array2);
		printf("\n2.ϣ������\n");
		start[2] = clock();//���ڲ��Է�Χ�ڵ�׼������д��clock()����
		Shellsort(array2);
		stop[2] = clock();
		printf("ϣ�������%d�����������Ѿ�����\n\n", _COUNT);
		saveArray2(array2);
		duration[2] = ((double)(stop[2] - start[2])) / CLK_TCK;
		printf("%d���������ϣ�������������ķѵ�ʱ��Ϊ��ticksΪ:%lf\n", _COUNT, (double)(stop[2] - start[2]));
		printf("%d���������ϣ���������ķѵ�ʱ��Ϊ:%lf\n", _COUNT, duration[2]);
		break;
	}
	case 3:
	{
		CopyArray(array3);
		printf("\n3.ð������\n");
		start[3] = clock();//���ڲ��Է�Χ�ڵ�׼������д��clock()����
		BubbleSort(array3);
		stop[3] = clock();
		printf("ð�������%d�����������Ѿ�����\n\n", _COUNT);
		saveArray3(array3);
		duration[3] = ((double)(stop[3] - start[3])) / CLK_TCK;
		printf("%d���������ð�ݲ����������ķѵ�ʱ��Ϊ��ticksΪ:%lf\n", _COUNT, (double)(stop[3] - start[3]));
		printf("%d���������ð���������ķѵ�ʱ��Ϊ:%lf\n", _COUNT, duration[3]);
		break;
	}
	case 4:
	{
		CopyArray(array4);
		printf("\n4.��������\n");
		start[4] = clock();//���ڲ��Է�Χ�ڵ�׼������д��clock()����
		quicksort(array4, 0, _COUNT - 1);
		stop[4] = clock();
		printf("ֱ�Ӳ��������%d�����������Ѿ�����\n\n", _COUNT);
		saveArray4(array4);
		duration[4] = ((double)(stop[4] - start[4])) / CLK_TCK;
		printf("%d��������ÿ����������ķѵ�ʱ��Ϊ��ticksΪ:%lf\n", _COUNT, (double)(stop[4] - start[4]));
		printf("%d��������ÿ����������ķѵ�ʱ��Ϊ:%lf\n", _COUNT, duration[4]);
		break;
	}
	case 5:
	{
		CopyArray(array5);
		printf("\n5.ѡ������\n");
		start[5] = clock();//���ڲ��Է�Χ�ڵ�׼������д��clock()����
		SelectSort(array5);
		stop[5] = clock();
		printf("ѡ�������%d���������Ѿ�����\n\n", _COUNT);
		saveArray5(array5);
		duration[5] = ((double)(stop[5] - start[5])) / CLK_TCK;
		printf("%d���������ѡ���������ķѵ�ʱ��Ϊ��ticksΪ:%lf\n", _COUNT, (double)(stop[5] - start[5]));
		printf("%d���������ѡ���������ķѵ�ʱ��Ϊ:%lf\n", _COUNT, duration[5]);
		break;
	}
	case 6:
	{
		CopyArray(array6);
		printf("\n6.������\n");
		start[6] = clock();//���ڲ��Է�Χ�ڵ�׼������д��clock()����
		HeapSort(array6);
		stop[6] = clock();
		printf("�������%d���������Ѿ�����\n\n", _COUNT);
		saveArray6(array6);
		duration[6] = ((double)(stop[6] - start[6])) / CLK_TCK;
		printf("%d��������ö��������ķѵ�ʱ��Ϊ��ticksΪ:%lf\n", _COUNT, (double)(stop[6] - start[6]));
		printf("%d��������ö��������ķѵ�ʱ��Ϊ:%lf\n", _COUNT, duration[6]);
		break;
	}
	case 7:
	{
		CopyArray(array7);
		printf("\n7.�鲢����\n");
		start[7] = clock();//���ڲ��Է�Χ�ڵ�׼������д��clock()����
		MergeSort(array7, 0, _COUNT - 1);
		stop[7] = clock();
		printf("�鲢�����%d���������Ѿ�����\n\n", _COUNT);
		saveArray7(array7);
		duration[7] = ((double)(stop[7] - start[7])) / CLK_TCK;
		printf("%d��������ù鲢�������ķѵ�ʱ��Ϊ��ticksΪ:%lf\n", _COUNT, (double)(stop[7] - start[7]));
		printf("%d��������ù鲢�������ķѵ�ʱ��Ϊ:%lf\n", _COUNT, duration[7]);
		break;
	}
	}
}
void Creatrandnum()
{
	initArray();
	printf("\n%d��������Ѿ�����\n", _COUNT);
	saveArray();
}
int contains(unsigned int num)//���ĳ�����Ƿ��Ѿ���������
{
	for (unsigned int i = 0; i <= idex; i++)
	{
		if (num == array[i])
			return 1;
	}
	return 0;
}
void initArray()
{
	srand(time(NULL));
	while (idex != _COUNT)
	{
		unsigned int t = rand() % 32768;//���������
		if (!contains(t))
		{
			array[idex++] = t;
		}
	}
}
unsigned int CopyArray(unsigned int arrayn[])
{
	int i;
	for (i = 0; i < _COUNT; i++)
		arrayn[i] = array[i];//�����������ÿ����������
	return *arrayn;//����
}
void saveArray()//�����ݴ�ӡ���ļ�ϵͳ
{
	FILE* fp = fopen("E:\\generates\\randnum30000.txt", "wt");//�������ǰ����Ŀ¼�������
	if (fp)
	{
		for (unsigned int i = 0; i < _COUNT; i++)
		{
			fprintf(fp, "%d\n", array[i]);
		}
		fclose(fp);
	}
}
void saveArray1(unsigned int array1[])//�����ݴ�ӡ���ļ�ϵͳ
{
	FILE* fp = fopen("E:\\generates\\InserSort30000.txt", "wt");
	if (fp)
	{
		for (unsigned int i = 0; i < _COUNT; i++)
		{
			fprintf(fp, "%d\n", array1[i]);
		}
		fclose(fp);
	}
}
void saveArray2(unsigned int array2[])//�����ݴ�ӡ���ļ�ϵͳ
{
	FILE* fp = fopen("E:\\generates\\ShellSort30000.txt", "wt");
	if (fp)
	{
		for (unsigned int i = 0; i < _COUNT; i++)
		{
			fprintf(fp, "%d\n", array2[i]);
		}
		fclose(fp);
	}
}
void saveArray3(unsigned int array3[])//�����ݴ�ӡ���ļ�ϵͳ
{
	FILE* fp = fopen("E:\\generates\\BubbleSort30000.txt", "wt");
	if (fp)
	{
		for (unsigned int i = 0; i < _COUNT; i++)
		{
			fprintf(fp, "%d\n", array3[i]);
		}
		fclose(fp);
	}
}
void saveArray4(unsigned int array4[])//�����ݴ�ӡ���ļ�ϵͳ
{
	FILE* fp = fopen("E:\\generates\\quickSort30000.txt", "wt");
	if (fp)
	{
		for (unsigned int i = 0; i < _COUNT; i++)
		{
			fprintf(fp, "%d\n", array4[i]);
		}
		fclose(fp);
	}
}
void saveArray5(unsigned int array5[])//�����ݴ�ӡ���ļ�ϵͳ
{
	FILE* fp = fopen("E:\\generates\\SelectSort30000.txt", "wt");
	if (fp)
	{
		for (unsigned int i = 0; i < _COUNT; i++)
		{
			fprintf(fp, "%d\n", array5[i]);
		}
		fclose(fp);
	}
}
void saveArray6(unsigned int array6[])//�����ݴ�ӡ���ļ�ϵͳ
{
	FILE* fp = fopen("E:\\generates\\HeapSort30000.txt", "wt");
	if (fp)
	{
		for (unsigned int i = 0; i < _COUNT; i++)
		{
			fprintf(fp, "%d\n", array6[i]);
		}
		fclose(fp);
	}
}
void saveArray7(unsigned int array7[])//�����ݴ�ӡ���ļ�ϵͳ
{
	FILE* fp = fopen("E:\\generates\\MSort30000.txt", "wt");
	if (fp)
	{
		for (unsigned int i = 0; i < _COUNT; i++)
		{
			fprintf(fp, "%d\n", array7[i]);
		}
		fclose(fp);
	}
}
void InserSort(unsigned int array1[])//��array1�����봦��
{
	int j, i;
	for (i = 1; i < _COUNT; ++i)
		if (array1[i] < array1[i - 1])
		{
			array1[_COUNT] = array1[i];//������array[-COUNT]
			array1[i] = array1[i - 1];
			for (j = i - 1; array1[_COUNT] < array1[j]; --j)//�Ӻ���ǰѰ�Ҳ���λ��
				array1[j + 1] = array1[j];//�������,ֱ���ҵ�����λ��
			array1[j + 1] = array1[_COUNT];//��ԭ,���뵽��ȷλ��
		}
}
void BubbleSort(unsigned int array2[])
{
	//ð�ݷ�����ʵ�ִ�С��������
	for (int i = 0; i < _COUNT; i++) //����10��ѭ��
	{
		for (int j = i + 1; j < _COUNT; j++) //ѭ���Ƚ�ʣ��ı���
		{
			if (array2[i] > array2[j]) //���ǰ��һ�����Ⱥ������󣬽�����������ֵ
			{
				array2[i] ^= array2[j];
				array2[j] ^= array2[i];
				array2[i] ^= array2[j];//λ����,������ʱ����,��ѧ��.
			}
		}
	}
}
void Shellsort(unsigned int array3[])
{
	int j, dk;
	for (dk = _COUNT / 2; dk > 0; dk /= 2)
		for (j = dk; j < _COUNT; j++)//�������dk��Ԫ�ؿ�ʼ
			if (array3[j] < array3[j - dk])//ÿ��Ԫ�����Լ����ڵ����ݽ���ֱ�Ӳ�������
			{
				int temp = array3[j];
				int k = j - dk;
				while (k >= 0 && array3[k] > temp)
				{
					array3[k + dk] = array3[k];//��¼����,ֱ���ҵ�����λ��
					k -= dk;
				}
				array3[k + dk] = temp;//��ԭ
			}
}
void quicksort(unsigned int array4[], int low, int high)
{
	int middle;
	if (low >= high)
		return;//low>high�ͽ�����
	middle = split(array4, low, high);//
	quicksort(array4, low, middle - 1);
	quicksort(array4, middle + 1, high);//�ݹ����
}
int split(unsigned int array4[], int low, int high)
{
	int part_element = array4[low];//����array4[low]
	for (;;)
	{
		while (low < high && part_element <= array4[high])
			high--;//�ȸ�Ԫ��array4[high]���,high�ͼ�1
		if (low >= high)
			break;//low���ڵ���high,˵���������Ѿ�ȫ����������
		array4[low++] = array4[high];//����

		while (low < high && array4[low] <= part_element)
			low++;//�ȸ�Ԫ��array4[high]С��,low�ͼ�1
		if (low >= high)
			break;
		array4[high--] = array4[low];//����
	}
	array4[high] = part_element;//��ԭ
	return high;
}
void SelectSort(unsigned int array5[])
{
	int i, j;
	for (i = 0; i < _COUNT - 1; i++)
	{
		int k = i;
		for (j = i + 1; j <= _COUNT - 1; ++j)//������������С�ؼ���
			if (array5[j] < array5[k])
				k = j;//k��¼
		if (k != i)
		{
			array5[i] ^= array5[k];
			array5[k] ^= array5[i];
			array5[i] ^= array5[k];//λ����,������ֵ
		}
	}
}
void Swap(unsigned int* num_a, unsigned int* num_b)
{
	*num_a ^= *num_b;
	*num_b ^= *num_a;
	*num_a ^= *num_b;//��֤�������Ǵ����
}

// array�Ǵ������Ķ�����,i�Ǵ�����������Ԫ�ص�λ��,nlength������ĳ���
void HeapAdjust(unsigned int array6[], int i, int nLength)
{
	int nChild, nTemp;
	for (nTemp = array6[i]; 2 * i + 1 < nLength; i = nChild)
	{
		// nChild:���ӽ���λ���� �����λ��*2+1
		nChild = 2 * i + 1;
		// �õ��ӽ���нϴ�Ľ��
		if (nChild != nLength - 1 && array6[nChild + 1] > array6[nChild])
			++nChild;
		// ����ϴ���ӽ����ڸ������ô�ѽϴ���ӽ�������ƶ�,�滻���ĸ����
		if (nTemp < array6[nChild])
		{
			array6[i] = array6[nChild];
		}
		else  // �����˳�ѭ��
		{
			break;
		}
	}
	// ������Ҫ������Ԫ��ֵ�ŵ����ʵ�λ��
	array6[i] = nTemp;
}
// �������㷨
void HeapSort(unsigned int array6[])
{
	// �������е�ǰ�벿��Ԫ��,����ÿ���к��ӵĽڵ㣩������֮����һ���󶥶ѣ���һ��Ԫ�������е�����Ԫ��
	for (int i = _COUNT / 2 - 1; i >= 0; --i)
	{
		HeapAdjust(array6, i, _COUNT);
	}
	// �����һ��Ԫ�ؿ�ʼ�����н��е���,���ϵ���С�����ķ�Χֱ����һ��Ԫ��
	for (int i = _COUNT - 1; i > 0; --i)
	{
		// �ѵ�һ��Ԫ�غ͵�ǰ�����һ��Ԫ�ؽ���,
		// ��֤��ǰ�����һ��λ�õ�Ԫ�ض��������ڵ��������֮������
		Swap(&array6[0], &array6[i]);
		// ������С����heap�ķ�Χ,ÿһ�ε�����ϱ�֤��һ��Ԫ���ǵ�ǰ���е����ֵ
		HeapAdjust(array6, 0, i);
	}
}
// �鲢�����еĺϲ��㷨
void Merge(unsigned int array7[], int left, int m, int right)
{
	int aux[_COUNT] = { 0 }; // ��ʱ����,����ʹ����ʱ���飬��������������ϲ�Ϊһ����������Ƚ��鷳
	int i; //��һ����������
	int j; //�ڶ�����������
	int k; //��ʱ��������

	for (i = left, j = m + 1, k = 0; k <= right - left; k++) // �ֱ� i, j, k ָ�����������ײ�
	{
		//�� i �����һ�������β�������ڶ�����������Ԫ�ظ��Ƶ� ��ʱ������
		if (i == m + 1)
		{
			aux[k] = array7[j++];
			continue;
		}
		//�� j ����ڶ��������β��������һ����������Ԫ�ظ��Ƶ� ��ʱ������
		if (j == right + 1)
		{
			aux[k] = array7[i++];
			continue;
		}
		//�����һ������ĵ�ǰԪ�� �� �ڶ�������ĵ�ǰԪ��С���� ��һ������ĵ�ǰԪ�ظ��Ƶ� ��ʱ������
		if (array7[i] < array7[j])
		{
			aux[k] = array7[i++];
		}
		//����ڶ�������ĵ�ǰԪ�� �� ��һ������ĵ�ǰԪ��С���� �ڶ�������ĵ�ǰԪ�ظ��Ƶ� ��ʱ������
		else
		{
			aux[k] = array7[j++];
		}
	}
	//���������ʱ���� Ԫ�� ˢ�� ����������� array �У�
	//i = left , �����������array ����ʼλ��
	//j = 0�� ��ʱ�������ʼλ��
	for (i = left, j = 0; i <= right; i++, j++)
	{
		array7[i] = aux[j];
	}
}
// �鲢����
void MergeSort(unsigned int array7[], int low, int high)
{
	if (low < high)
	{
		int i;
		i = (high + low) / 2;
		// ��ǰ�벿�ֽ�������
		MergeSort(array7, low, i);
		// �Ժ�벿�ֽ�������
		MergeSort(array7, i + 1, high);
		// �ϲ�ǰ��������
		Merge(array7, low, i, high);
	}
}
