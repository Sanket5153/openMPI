#include<stdio.h>
#include<mpi.h>
int main(int argc, char *argv[])
{
    int rank,size;
    int data=50,new_data;
    MPI_Request request;
    MPI_Status status;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);

    if (rank ==0){
        MPI_Send(&data,1,MPI_INT,1,123,MPI_COMM_WORLD);
        printf("RANK : %d | Data sent : %d  \n",rank,data);
    }
    else if (rank == 1){
        MPI_Irecv(&new_data,1,MPI_INT,0,123,MPI_COMM_WORLD,&request);
        MPI_Wait(&request,&status);
        printf("RANK : %d | data received : %d \n",rank,new_data);
    }
    MPI_Finalize();

}