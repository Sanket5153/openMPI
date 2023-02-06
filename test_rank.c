#include<stdio.h>
#include<mpi.h>
int main(int argc,char *argv[])
{	
	int a=10,b=5,c=0;
	int process,rank,len;
	char hostname[MPI_MAX_PROCESSOR_NAME];
	MPI_Init(&argc,&argv);
	MPI_Get_processor_name(hostname, &len);
	MPI_Comm_size(MPI_COMM_WORLD,&process);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	printf("Process : %d | rank : %d \n | name of host = %s",process,rank,hostname);
	if (rank == 0){
		c=a+b;
		printf("sum = %d\n",c);
	}
	else if (rank ==1){
		c = a-b;
		printf("sub = %d \n",c);
	}
	else {
		c= a*b;
		printf("mul = %d\n",c);
	}


	MPI_Finalize();


}
