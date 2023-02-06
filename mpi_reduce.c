#include<stdio.h>
#include<mpi.h>
int main(int argc,char **argv)
{
int sndcnt,rcvcnt,rank,process;
int s_data,r_data;
const int root = 0;
sndcnt = 1;
rcvcnt = 1;

MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&process);
s_data = 100 + rank;

printf("TOtal process : %d | rank : %d | data sent : %d\n",process,rank,s_data);
MPI_Reduce(&s_data,&r_data,rcvcnt,MPI_INT,MPI_SUM,root,MPI_COMM_WORLD);
if (rank == 0){
	printf("Rank : %d | received data : %d\n",rank,r_data);
}

MPI_Finalize();

}
