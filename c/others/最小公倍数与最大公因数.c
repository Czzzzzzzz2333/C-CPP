#include<stdio.h>
int main()
{
    int n,m,temp,a,b;
    printf("��С���������������\n");
    printf("    ������������:");
    scanf(" %d %d",&n,&m);
    if(n<m)
    {
        temp=n;
        n=m;
        m=temp;
    }
    a=n;
    b=m;
    while(b!=0)
    {
        temp=a%b;
        a=b;
        b=temp;
    }
    printf("    ��С������Ϊ:%d\n",n*m/a);
    printf("    �������Ϊ:%d",a);
    return 0;
}
