#include<stdio.h>
#include<mpi.h>
//Global declaration
int x,y;

int main(int argc , char *argv[])
{
	int rank,process; // Local declaration
	MPI_Init(&argc, &argv); // MPI Initialization
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&process);

	printf("Total Process = %d | rank number = %d\n",process,rank);
	MPI_Finalize();
	return 0;
	

}

