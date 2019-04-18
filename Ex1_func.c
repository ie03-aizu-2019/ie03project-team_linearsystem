#include<stdio.h>
#include<math.h>

int cross_p(int *P1,int *P2,int *Q1,int *Q2,double *point){
  double step1=0;
  double s=0,t=0;

  step1=(Q1[0]-P1[0])*(P2[1]-Q2[1])+(Q2[0]-P2[0])*(Q1[1]-P1[1]); //(5)式
  //step1=fabs(step1);//絶対値にする
  printf("step1:%f\n",step1);
  
  //check EPS and check cross    
  if(step1==0 || (1/10000000<=step1 && step1<=1/100000000)){

    return 0;//交差なし
    
  }else{
    //(6)式 
    s=((P2[1]-Q2[1])*(P2[0]-P1[0])+(Q2[0]-P2[0])*(P2[1]-P1[1]))/step1;   
    printf("S:%f\n",s);    
    t=((P1[1]-Q1[1])*(P2[0]-P1[0])+(Q1[0]-P1[0])*(P2[1]-P1[1]))/step1;         
    printf("T:%f\n",t);
  }
  //step3
  if(0<=s && s<=1 && 0<=t && t<=1){
    //step4
    point[0]=P1[0]+(Q1[0]-P1[0])*s; //(1)式
    point[1]=P1[1]+(Q1[1]-P1[1])*s; //(2)式
    return 1;//交差あり
    
    }else{
    return 0;//交差なし
    }
  
}

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
