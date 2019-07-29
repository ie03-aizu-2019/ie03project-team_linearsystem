#include "main.h"
#include "initialize.h"
#include "cross_point.h"


/************************************************************/
// search_cross_pointで使う

static Point cross_p(Point P1,Point P2,Point Q1,Point Q2){
  double step1=0;
  double s=0,t=0;
  double x=0,y=0;//交差点の座標
  step1=(Q1.x-P1.x)*(P2.y-Q2.y)+(Q2.x-P2.x)*(Q1.y-P1.y); //(5)式

  //check EPS and check cross
  if(step1==0 || (1/10000000<=step1 && step1<=1/100000000)){

    return init_point(-1,-1,-1);//交差なし

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
    return init_point(-1,-1,-1);//交差なし
  }

}



static bool check_cross_point(Point check){
  // check.index == -1 → 交差点が無い
  if(check.index == -1) return false;
  // すでにある交差点は無視
  for(const auto& e: p){
    if(check.x == e.x && check.y == e.y) return false;
  }

  return true;
}

/************************************************************/


int search_cross_point(){
  int cp_num = 0; // 交差点の数

  for(int i=1; i<road.size(); i++){
    for(int j=i+1; j<road.size(); j++){

      Point p1 = p[road[i][0]];
      Point p2 = p[road[j][0]];
      Point q1 = p[road[i][1]];
      Point q2 = p[road[j][1]];

      Point tmp = cross_p(p1, p2, q1, q2);
      if(check_cross_point(tmp)){

        tmp.index = N + ++cp_num;
        c_p.push_back(tmp);
        p.push_back(tmp);
      }

    }
  }

  return cp_num;
}
