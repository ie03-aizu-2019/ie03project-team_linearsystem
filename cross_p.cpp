#include<stdio.h>
#include<math.h>
#include"main.h"

Point cross_p(Point P1,Point P2,Point Q1,Point Q2){
  double s=0,t=0;
  double x=0,y=0;//交差点の座標
  double step1=(Q1.x-P1.x)*(P2.y-Q2.y)+(Q2.x-P2.x)*(Q1.y-P1.y); //(5)式

  //check EPS and check cross
  if(step1==0 || (1/10000000<=step1 && step1<=1/100000000)){
    return init_point(-1,-1);//交差なし
  }else{
    //(6)式
    s=((P2.y-Q2.y)*(P2.x-P1.x)+(Q2.x-P2.x)*(P2.y-P1.y))/step1;
    t=((P1.y-Q1.y)*(P2.x-P1.x)+(Q1.x-P1.x)*(P2.y-P1.y))/step1;
  }
  //step3
  if(0<s && s<1 && 0<t && t<1){
    //step4
    x=P1.x+(Q1.x-P1.x)*s; //(1)式
    y=P1.y+(Q1.y-P1.y)*s; //(2)式
    return init_point(x,y);//交差あり
  }else{
    return init_point(-1,-1);//交差なし
  }

}
