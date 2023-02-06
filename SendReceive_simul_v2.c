#include<mpi.h>
#include <stdio.h>
int main (int argc, char *argv[])
{
int myrank,size, send_data,receive_data;
MPI_Init (&argc, &argv);
int tag1 = 123;
int tag2 = 321;
MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
MPI_Comm_size(MPI_COMM_WORLD, &size);    
if (myrank==0)
{
	send_data=20;
	printf("Myrank is %d, sending data %d: \n", myrank, send_data);
	MPI_Sendrecv(&send_data, 1, MPI_INT, 1, tag1 , &receive_data, 1, MPI_INT, 1, tag2 , MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	printf("Myrank is %d, received data %d: \n", myrank, receive_data);
}
else if(myrank==1)
{
	send_data=50;
	printf("Myrank is %d, sending data %d: \n", myrank, send_data);
	MPI_Sendrecv(&send_data, 1, MPI_INT, 0, tag2, &receive_data, 1, MPI_INT, 0, tag1 , MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	printf("Myrank is %d, received data %d: \n", myrank, receive_data);
}
MPI_Finalize ();
}