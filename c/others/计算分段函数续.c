#include<stdio.h>
#include<math.h>
int main()
{
    float x,y;
    int n;
    for(;;)
    {
        scanf("%f",&x);
        if(x>=0)
        {
            y=sqrt(x);
            printf("f(%.2f)=%.2f\n",x,y);
        }
        if(x<0)
        {
            y=pow((x+1),2)+2*x+1/x;
            printf("f(%.2f)=%.2f\n",x,y);
        }
        printf("�Ƿ�������� 1.�� 2.��\n");
        printf("���������ѡ��:");
        scanf("%d",&n);
        if(n==1)
            break;
        if(n==2)
            printf("\n");
    }
    return 0;
}
