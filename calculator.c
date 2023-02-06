#include<stdio.h>
#define N 10000
int main()
{
	int arr1[N],arr2[N],sum[N],mul[N];
	int i,j;
	for(i=0;i<N;i++)
	{
		arr1[i]=i;
		arr2[i]=i+1;
		sum[i]=0;
	}
	for (i=0;i<N;i++){
		sum[i]=arr1[i]+arr2[i];
	}

	for (i=0;i<N;i++){
		mul[i]=arr1[i]*arr2[i];

	}
	printf("Addition is started ....\n");
	for (i=0;i<N;i++){
		printf("sum[%d]=%d\n",i,sum[i]);
	//	printf("sub[%d]=%d\n",i,mul[i]);
	}
	
	printf("Multiplication started .....\n");
	for (i=0;i<N;i++){
		printf("Mul[%d]=%d\n",i,mul[i]);
	}
}
