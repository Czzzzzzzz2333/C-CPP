/*hdu1008*/

#include<stdio.h>

int main()
{
    int n,time,start;
    while(~scanf("%d",&n))
    {
        int f[n];//ͣ���Ĳ���
        time=start=0;//��ʱ���һ��ʼ�Ĳ���
        if(n==0)break;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&f[i]);//��ֵ
        }
        for(int i=1;i<=n;i++)
        {
            if(f[i]>start)
                time+=(f[i]-start)*6;
            else
                time+=(start-f[i])*4;
            start=f[i];
            time+=5;
        }//��������
        printf("%d\n",time);
    }
    return 0;
}
