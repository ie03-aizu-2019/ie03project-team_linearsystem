#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int func(int*,int*,int*,int*,double*);

int main(){
  int N=0;  // 座標の数
  int M=0;  // 道の数
  int P=0;  // 追加される地点の座標の数
  int Q=0;  // 経路の問い合わせの数
  int **A;  // 座標を保存
  int **B;  // 道の数を保存

  int cross_point = 0; // 交差点の数
  double **C;  // 交差点の座標を保存


  scanf("%d %d %d %d",&N,&M,&P,&Q);
  // 座標の読み込み
  A = malloc(sizeof(int*) * N);
  for(int i=0; i<N; i++){
    A[i]=malloc(sizeof(int) * 2);

    scanf("%d %d",&A[i][0],&A[i][1]);
    // printf("%d %d\n",A[i][0],A[i][1]);
  }

  // printf("\n");

  // 道の読み込み
  B = malloc(sizeof(int*) * M);
  for(int i=0; i<M; i++){
    B[i] = malloc(sizeof(int) * 2);

    scanf("%d %d",&B[i][0], &B[i][1]);
    // printf("%d %d\n",B[i][0] ,B[i][1]);
  }


  // 交差地点の検出
  M = 5;
  for(int i=0; i<M-1; i++){
    for(int j=i+1; j<M; j++){
      // printf("i:%d j:%d\n",i,j);
      double point[2];
      if(func(A[B[i][0]-1], A[B[i][1]-1], A[B[j][0]-1], A[B[j][1]-1], point)){
        // 交差点の座標を表示
        printf("%.5f %.5f\n",point[0] ,point[1]);


        // // 交差点の座標を追加
        if(cross_point == 0){
          double **tmp;
          tmp = malloc(sizeof(double)*cross_point*2);
          memcpy(tmp, C, sizeof(double)*cross_point*2);
          C = malloc(sizeof(double*) * (cross_point+1));
          memcpy(C, tmp, sizeof(double)*cross_point*2);
          C[cross_point] = malloc(sizeof(double) * 2);
          memcpy(C[cross_point], point, sizeof(point));
          free(tmp);
        }

        // // 交差点の数を追加
        cross_point += 1;
      }
    }
  }

  // for(int i=0; i<cross_point; i++){
  //   printf("%f %f\n",C[i][0], C[i][1]);
  // }

  free(A);
  free(B);
  return 0;
}


int func(int *P1,int *P2, int *Q1, int *Q2, double *point){
  point[0] = 0.0;
  point[1] = 2.0;
  // printf("P1:%d %d\n",P1[0],P1[1]);
  // printf("P2:%d %d\n",P2[0],P2[1]);
  // printf("Q1:%d %d\n",Q1[0],Q1[1]);
  // printf("Q2:%d %d\n",Q2[0],Q2[1]);
  return 1;
}
