#include<stdio.h>
int main()
{
    int lower,upper,n,F;
    double C;
    while(1)
    {
        scanf("%d %d",&lower,&upper);
        if(lower>upper)
            printf("����������");
        else
        {
            printf("ת�����¶�Ϊ:\n");
            for(F=lower; F<=upper; F++)
            {
                C=5*(F*1.0-32)/9;
                printf("%d  %.1f\n",F,C);
                F=F+1;
            }
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
