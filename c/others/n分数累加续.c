#include<stdio.h>
int main()
{
    int m,n,i;
    float s,b;
    s=1;
    for(;;)
    {
        scanf("%d",&m);
        for(i=3; i<=m; i+=2)
        {
			b=1.0/i;
            s=s+b;
        }
        printf("%.6f\n",s);
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

