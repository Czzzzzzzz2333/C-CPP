#include<stdio.h>
int main()
{
    int a,n,s=0,m;
    printf("����������a��");
    scanf("%d",&a);
    printf("���������n��");
    scanf("%d",&n);
    m=a;
    for(int i=1;i<=n;i++)
    {
       s=s+m;
       m=10*m+a;
    }
    printf("���Ϊ��");
    printf("%d",s);
    return 0;
}
