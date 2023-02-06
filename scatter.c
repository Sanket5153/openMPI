#include<stdio.h>
#include<mpi.h>
int main(int argc , char *argv[])
{
	int rank,sndcnt,rcvcnt,i;
	int arr[5],data;
	const int root = 0;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	sndcnt = 1;
	rcvcnt = 1;
	if (rank == root)
	{
		for (i=0;i<5;i++)
		{
			arr[i]=10+i;
		}
		printf("rank [%d] : \n",rank);
		for (i=0;i<5;i++)
		{
			printf("%d\t",arr[i]);
		}
		printf("\n");

	}
	MPI_Scatter(arr,sndcnt,MPI_INT,&data,rcvcnt,MPI_INT,0,MPI_COMM_WORLD);
	printf("rank : %d | data : %d\n",rank,data);
	MPI_Finalize();
	return 0;

}
