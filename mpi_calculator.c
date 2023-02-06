#include<stdio.h>
#include<mpi.h>
#define N 10000
int main(int argc,char *argv[])
{
	int arr1[N],arr2[N],sum[N],mul[N];
	int i,process,rank;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&process);

	printf("Total process : %d | rank is : %d",process,rank);

	for(i=0;i<N;i++)
	{
		arr1[i]=i;
		arr2[i]=i+1;
		sum[i]=0;
	}
	
	if (rank == 0){
	for (i=0;i<N;i++){
		sum[i]=arr1[i]+arr2[i];
	}
	}
	else if (rank==1){

	for (i=0;i<N;i++){
		mul[i]=arr1[i]*arr2[i];

	}
	}
	printf("Addition is started ....\n");
	
	for (i=0;i<N;i++){
//		printf("sum[%d]=%d\n",i,sum[i]);
	//	printf("sub[%d]=%d\n",i,mul[i]);
	}
	
	
	printf("Multiplication started .....\n");
	for (i=0;i<N;i++){
//		printf("Mul[%d]=%d\n",i,mul[i]);
	}

	MPI_Finalize();	
}
