#include<stdio.h>
int main()
{
    int a,n,i,m;
    float s,b;
    s=1;
    i=1;
    a=4;
    scanf("%d",&n);
    for(;;)
    {
        while(a<=n)
        {
            i=-i;
            b=(float)i/a;
            s=s+b;
            a+=3;
        }
        printf("%.6f\n",s);
        printf("�Ƿ�������� 1.�� 2.��\n");
        printf("���������ѡ��:");
        scanf("%d",&m);
        if(m==1)
            break;
        if(m==2)
            printf("\n");
    }
    return 0;
}

