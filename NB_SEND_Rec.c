#include<stdio.h>
#include<mpi.h>
int main(int argc,char *argv[])
{
    int rank,size,a=100,b;
    MPI_Request request;
    MPI_Status status;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    if (rank == 0){
        MPI_Isend(&a,1,MPI_INT,1,123,MPI_COMM_WORLD,&request);
        //MPI_Wait(&request,&status);
        printf("Rank : %d | Data sent : %d\n",rank,a);
    }

    else if (rank ==1){
        MPI_Irecv(&b,1,MPI_INT,0,123,MPI_COMM_WORLD,&request);
        MPI_Wait(&request,&status);
        printf("Rank : %d | Data received : %d\n",rank,b);
    }
    MPI_Finalize();
  //  MPI_Comm_rank(MPI_COMM_WORLD,&rank);
   // printf("Rank : %d | Data sent : %d\n",rank,a);
}