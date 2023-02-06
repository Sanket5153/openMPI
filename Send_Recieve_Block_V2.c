#include<mpi.h>
#include <stdio.h>
int main (int argc, char *argv[])
{
	int myrank,size, data;
	double start,end,total_time;
	start =MPI_Wtime ();
	MPI_Init (&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);    
	if (myrank==0)
	{
		data=50;
		printf("Myrank is %d, sending data %d: \n", myrank, data);
		MPI_Send(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
	}
	else if(myrank==1)
	{
		MPI_Recv(&data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("Myrank is %d, received data %d: \n", myrank, data);
	}
	MPI_Finalize ();
	end =MPI_Wtime ();
	total_time = end - start;
	printf("Total time taken : %lf\n",total_time);
}

