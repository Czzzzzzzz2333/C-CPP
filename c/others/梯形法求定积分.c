#include<stdio.h>
#include<math.h>
int main()
{
    printf("                                        �γ���Ƶ�37�������η����㺯���Ķ�����                                     \n\n");
    printf("��ʾ���ѻ�������[a��b]�ȷ�Ϊn�ȷ֣�a,b,n��ֵ�ɳ������롣�����ɵõ����ɸ�С���Σ���������ͽ���Ϊ��ЩС�������֮�͡�\n\n\n");
    float fun(float (*f)(float), float a, float b);//��������ָ�룬��������fun
    float F1(float x);//��������F1
    float a,b;//����a��bΪ�������͵���
    int m;
    printf("     ������x*x+2*x+1\n\n");
    while(1)//��ѭ��
    {
        printf("��������������a����������b:\n");
        scanf("%f%f",&a,&b);
        printf("����������ֶ���n\n");
        printf("�ú����Ķ�����=                      %f\n\n",fun(F1,a,b));//���ú���ָ��
        printf("�Ƿ����ѭ�����ǣ�1����2\n");
        scanf("%d",&m);
        if(m==1)
        break;
        if(m==2)
        printf("\n");
    }
    return 0;
}


float F1(float x)//���ú���F1
{
    return x*x+2*x+1;//��Ŀ�꺯��x*x+2*x+1��ֵ��Ϊ��������ֵ����fun������������ָ��
}


float fun(float (*f)(float), float a,float b)//���ú���ָ��
{
    float s,h;
    int n;//�Էֳ�n���ֽ��и�ֵ
    scanf("%d",&n);
    s=((*f)(a)+(*f)(b))/2;//���ú���F1��������
    h=(b-a)/n;//����ÿһ��С���εĸ�
    int i;
    for(i=0; i<n; i++)
    {
        s=(*f)(a + i*h)+s;
    }
    return s*h;
    //����n��С�������֮�ͣ���Ϊ����ֵ����������
}
