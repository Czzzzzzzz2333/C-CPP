#include<stdio.h>
int main()
{
    int s=0,i=0,j=0,n;
    printf("������:");
    while((n=getchar())!='\n')
    {
        if(n>='0'&&n<='9')
            s++;
        else if((n>='a'&&n<='z')||(n>='A'&&n<='Z'))
            i++;
        else if(n==' ')
            j++;
    }
    printf("��ĸΪ:%d\n",i);
    printf("����Ϊ:%d\n",s);
    printf("�ո�Ϊ:%d\n",j);
    return 0;
}
