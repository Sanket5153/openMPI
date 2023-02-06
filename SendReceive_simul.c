#include<stdio.h>
#include<mpi.h>
int main(int argc, char *argv[])
{
    int num1=10,num2,num3=30,num4,rank,size;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    printf("RANK : %d | Total processes : %d \n",rank,size);

    if (rank == 0){
        MPI_Sendrecv(&num1,1,MPI_INT,1,123,&num4,1,MPI_INT,1,321,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        printf("Data send : %d | Data received : %d \n",num1,num4);
    }
    else if (rank == 1){
        MPI_Sendrecv(&num3,1,MPI_INT,0,321,&num2,1,MPI_INT,0,123,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        printf("Data sent : %d | Data Received : %d\n",num3,num2);
    }

    MPI_Finalize();
    return 0;



}