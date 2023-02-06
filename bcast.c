#include<stdio.h>
#include<mpi.h>
int main(int argc,char **argv)
{
	int rank;
	int data;
	const int root = 0;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	if (rank== root){
		data = 1000;
	}
	MPI_Bcast(&data,1,MPI_INT,root,MPI_COMM_WORLD);
	printf("rank = %d | data : %d \n",rank,data);
	MPI_Finalize();
	return 0;


}
