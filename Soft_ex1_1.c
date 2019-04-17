#include <stdio.h>
#include <stdlib.h>

int main(){

  int N=0;
  int M=0;
  int **A;

  int P=0;
  int Q=0;

  //  int i;
  scanf("%d %d %d %d",&N,&M,&P,&Q);
  //メモリ確保
  A=malloc(N * sizeof(int*));
    for(int i=0;i<N;i++){
    
    A[i]=malloc(2*sizeof(int));
    
    scanf("%d %d",&A[i][0],&A[i][1]);
    
    printf("%d %d",A[i][0],A[i][1]);

  }
    printf("\n");


  return 0;
}
