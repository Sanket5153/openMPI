#include<mpi.h>
#include<stdio.h>
int main (int argc, char *argv[])
{
int myrank,size, data;
MPI_Request request;
MPI_Status status;
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
	MPI_Irecv(&data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &request);
	//MPI_Wait(&request,&status);
	printf("Myrank is %d, received data %d: \n", myrank, data);
}
MPI_Finalize ();
}
