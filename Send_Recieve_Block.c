#include<stdio.h>
#include<mpi.h>
int main(int argc , char *argv[])
{
	int rank,pro,len;
	int a,b;
	char hostname[MPI_MAX_PROCESSOR_NAME];
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&pro);
	MPI_Get_processor_name(hostname,&len);
	printf("Total processor : %d running on %s| current processor : %d  \n",pro,hostname,rank);
	if (rank ==0){
		a=10;
		printf("Sending message ...\n");
		MPI_Send(&a,1,MPI_INT,1,123,MPI_COMM_WORLD);
		printf("Data send : %d\n",a);
	}
	else if (rank == 1){
		printf("Recieveing the Message ..\n");
		MPI_Recv(&b,1,MPI_INT,0,123,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		printf("Recieved data : %d\n",b);
	}
//	return 0;
	MPI_Finalize();

}
