/*hdu1008*/

#include<stdio.h>

int main()
{
    int n,time,start,temp;
    while(~scanf("%d",&n))
    {
        int f[n];//ͣ���Ĳ���
        time=start=0;//��ʱ���һ��ʼ�Ĳ���
        if(n==0)
            break;
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&f[i]);//��ֵ
        }
        temp=f[1];
        temp=temp*6+5;
        if(n==1)
            printf("%d\n",temp);
        else
        {
            for(int i=1; i<n; i++)
            {
                if(f[i]>f[i+1])
                    time+=(f[i]-f[i+1])*4+5;
                else
                    time+=(f[i+1]-f[i])*6+5;
            }//��������
            printf("%d\n",time+temp);
        }
    }
    return 0;
}
