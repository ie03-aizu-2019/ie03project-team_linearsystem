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
  double **C, *base_C;  // 交差点の座標を保存
  C = (double **)malloc(sizeof(double *));


  scanf("%d %d %d %d",&N,&M,&P,&Q);

  // 座標の読み込み
  A = (int **)malloc(sizeof(int*) * N);
  for(int i=0; i<N; i++){
    A[i]=(int *)malloc(sizeof(int) * 2);

    scanf("%d %d",&A[i][0],&A[i][1]);
    // printf("%d %d\n",A[i][0],A[i][1]);
  }

  // printf("\n");

  // 道の読み込み
  B = (int **)malloc(sizeof(int*) * M);
  for(int i=0; i<M; i++){
    B[i] = (int *)malloc(sizeof(int) * 2);

    scanf("%d %d",&B[i][0], &B[i][1]);
    // printf("%d %d\n",B[i][0] ,B[i][1]);
  }


  // 交差地点の検出
  for(int i=0; i<M-1; i++){
    for(int j=i+1; j<M; j++){
      // printf("i:%d j:%d\n",i,j);
      double point[2];  // 交差点の座標を一時保存
      if(func(A[B[i][0]-1], A[B[i][1]-1], A[B[j][0]-1], A[B[j][1]-1], point)){
        // 交差点の座標を表示
        // printf("%.5f %.5f\n",point[0] ,point[1]);

        // // 交差点の座標を追加
        if(cross_point != 0){ // 配列を拡張
          double *tmp;
          tmp = (double *)malloc(sizeof(double)*cross_point*2);
          // puts("malloc tmp");
          memcpy(tmp, C, sizeof(double)*cross_point*2);
          // puts("memcpy C->tmp");
          C = (double **)malloc(sizeof(double*) * (cross_point+1)*2);
          // puts("malloc C");
          memcpy(C, tmp, sizeof(double)*cross_point*2);
          // puts("memcpy tmp->C");
          free(tmp);
          // puts("free tmp");
        }
        C[cross_point] = (double *)malloc(sizeof(double) * 2);
        memcpy(C[cross_point], point, sizeof(point));

        // printf("\nArray C (%d)\n",cross_point);
        // for(int k=0; k<=cross_point; k++){
        //   printf("%d: %f %f\n",k,C[k][0], C[k][1]);
        // }
        // puts("-----------------------------------");

        // // 交差点の数を追加
        cross_point += 1;
      }
      else{ // 交差点がないとき
        puts("NA");
      }
    }
  }
  // printf("cross_point:%d\n",cross_point);
  for(int i=0; i<cross_point-2; i++){
    for(int j=cross_point-1; j>i; j--){
      // printf("i:%d j:%d   ",i,j);
      // printf("%f %f\n",C[i][0],C[j][0]);
      if(C[i][0] > C[j][0]){
        double *tmp;
        memcpy(tmp, C[i], sizeof(double)*2);
        memcpy(C[i], C[j], sizeof(double)*2);
        memcpy(C[j],tmp, sizeof(double)*2);
      }
      else if(C[i][0] == C[j][0] && C[i][1] > C[j][1]){
        double *tmp;
        memcpy(tmp, C[i], sizeof(double)*2);
        memcpy(C[i], C[j], sizeof(double)*2);
        memcpy(C[j],tmp, sizeof(double)*2);
      }

    }
  }
  for(int i=0; i<cross_point; i++){
    printf("%f %f\n",C[i][0], C[i][1]);
  }

  // メモリ解放
  for(int i=0; i<N; i++) free(A[i]);
  free(A);
  // puts("free A");
  for(int i=0; i<M; i++) free(B[i]);
  free(B);
  // puts("free B");
  for(int i=0; i<N; i++) free(C[i]);
  free(C);
  // puts("free C");

  return 0;
}


int func(int *P1,int *P2, int *Q1, int *Q2, double *point){
  static int num = 0;
  point[0] = (double)(rand()%2)+num;
  point[1] = (double)(rand()%2)+num;
  // printf("P1:%d %d\n",P1[0],P1[1]);
  // printf("P2:%d %d\n",P2[0],P2[1]);
  // printf("Q1:%d %d\n",Q1[0],Q1[1]);
  // printf("Q2:%d %d\n",Q2[0],Q2[1]);
  num += 10;
  if(point[1] == 12.0) return 0;
  return 1;
}