#include<stdio.h>
int main()
{
    int i,j,k,n=0;
    printf("\n��1��2��3��4�����֣�����ɶ��ٸ�������ͬ�����ظ����ֵ���λ�������Ƕ��٣� \n\n");
    printf("                          ���е���λ��Ϊ:\n\n");
    for(i=1;i<5;i++)
    {
        for(j=1;j<5;j++)
        {
            for(k=1;k<5;k++)
            {
                if(k!=j&&k!=i&&i!=j)
                {
                    n++;
                    printf("%d%d%d ",i,j,k);
                }
            }
        }
    }
    printf("\n\n");
    printf("                            ����Ϊ:%d\n",n);
    return 0;
}
