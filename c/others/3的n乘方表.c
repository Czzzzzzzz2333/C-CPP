#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,s;
    scanf("%d",&n);
    while(1)
    {
        for(i=0; i<=n; i++)
        {
            s=pow(3,i);
            printf("pow(3,%d)=%d\n",i,s);
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
