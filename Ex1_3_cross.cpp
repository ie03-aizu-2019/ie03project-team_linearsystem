#include<stdio.h>
#include<math.h>
#include "main.h"
/*//構造体
using namespace std;

typedef struct {
  // 座標のデータ
  double x, y;
  // この点から伸びる道の情報
  vector<int> next;
  vector<int> road;

  // ダイクストラ法のためのデータ
  int done;
  int cost;
} Point;

Point init_point(double, double);
//構造体終わり
*/


Point cross_p(Point P1,Point P2,Point Q1,Point Q2){
  double step1=0;
  double s=0,t=0;
  double x=0,y=0;//交差点の座標
  step1=(Q1.x-P1.x)*(P2.y-Q2.y)+(Q2.x-P2.x)*(Q1.y-P1.y); //(5)式
  //step1=fabs(step1);//絶対値にする
  //  printf("step1:%f\n",step1);

  //check EPS and check cross
  if(step1==0 || (1/10000000<=step1 && step1<=1/100000000)){

    return init_point(-1,-1);//交差なし

  }else{
    //(6)式
    s=((P2.y-Q2.y)*(P2.x-P1.x)+(Q2.x-P2.x)*(P2.y-P1.y))/step1;
    //    printf("S:%f\n",s);
    t=((P1.y-Q1.y)*(P2.x-P1.x)+(Q1.x-P1.x)*(P2.y-P1.y))/step1;
    //   printf("T:%f\n",t);
  }
  //step3
  if(0<=s && s<=1 && 0<=t && t<=1){
    //step4
    x=P1.x+(Q1.x-P1.x)*s; //(1)式
    y=P1.y+(Q1.y-P1.y)*s; //(2)式
    return init_point(x,y);//交差あり

    }else{
    return init_point(-1,-1);//交差なし
    }

}
/*
  int main(){
    int a=0;
    int P1[2],P2[2],Q1[2],Q2[2];
    double point[2];

    P1[0]=0;
    P1[1]=0;

    Q1[0]=5;
    Q1[1]=5;

    P2[0]=2;
    P2[1]=5;

    Q2[0]=7;
    Q2[1]=1;


    a=cross_p(P1,P2,Q1,Q2,point);

    printf("%d,%f,%f \n",a,point[0],point[1]);

  return 0;
  }
*/
