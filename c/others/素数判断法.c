#include<stdio.h>
#include<math.h>
int main() {
	int i,j,k=0,m;
	printf("����Ϊ:\n\n");
	for(i=101; i<201; i++) {
		m=sqrt(i);
		for(j=2; j<=m; j++) {
			if(i%j==0) {
				break;
			}
		}
		if(i%j!=0) {
			printf("%-6d",i);
			k++;
			if(k%7==0)
				printf("\n");
		}
	}
	printf("\n��������Ϊ:");
	printf(" %d\n",k);
	return 0;
}
