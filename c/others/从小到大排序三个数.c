#include<stdio.h>
int main()
{
    int x,y,z,n;
    printf("������ԭʼ��������:");
    scanf("%d%d%d",&x,&y,&z);
    if(x>y)
    {
       n=x;
       x=y;
       y=n;
    }
    if(x>z)
    {
        n=x;
        x=z;
        z=n;
    }
    if(y>z)
    {
        n=y;
        y=z;
        z=n;
    }
    printf("��������λ��:");
    printf("%d,%d,%d\n",x,y,z);
    return 0;
}
