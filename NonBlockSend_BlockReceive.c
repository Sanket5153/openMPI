#include<stdio.h>
#include<mpi.h>
#define N 10
int main(int argc,char * argv[])
{
    int rank,pro,len,i;
    int src_arr[N],dest_arr[N];
    
    MPI_Request request;
    MPI_Status status;
    char hostname[MPI_MAX_PROCESSOR_NAME];
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&pro);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Get_processor_name(hostname,&len);
    
    
    if (rank==0){
        printf("Hostname : %s | Total process : %d | rank number : %d \n",hostname,pro,rank);
        for (i=0;i<N;i++){
        src_arr[i]=i+1;
    }
    printf("Sending data form rank : 0 \n");
        MPI_Isend(&src_arr,N,MPI_INT,1,123,MPI_COMM_WORLD,&request);
        
    }
    else if (rank == 1){
        printf("Hostname : %s | Total process : %d | rank number : %d \n",hostname,pro,rank);
        MPI_Recv(&dest_arr,10,MPI_INT,0,123,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
        for (i=0; i< N; i++){
            printf("dest side arr[%d] = %d \n",i,dest_arr[i]);
        }        
    }
    




}