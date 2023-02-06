#include<stdio.h>
#include<mpi.h>
int main(int argc,char *argv[])
{
int sndcnt , rcvcnt , rank , process, i ;
int s_data,r_data[5];
const int root = 0;
sndcnt = 1;
rcvcnt = 1;

MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&process);
s_data = 100 + rank ;
printf("Total process : %d | rank : %d | before sending data : %d\n",process,rank, s_data);
MPI_Gather(&s_data,sndcnt,MPI_INT,&r_data,rcvcnt,MPI_INT,root,MPI_COMM_WORLD);

if (rank == 0){
printf("rank : %d after receiving data : \n",rank);
for (i=0;i<5;i++){
	printf("%d \t",r_data[i]);
}
}

//printf("rank : %d | data : %d",rank,r_data); //garbage value

MPI_Finalize();

return 0;
}
