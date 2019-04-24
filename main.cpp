#include "stdio.h"
#include "vector"
#include "main.h"

int main(){
  int N, M, P, Q;   // 座標の数, 道の数, 追加される地点の数, 経路問い合わせの数
  vector<Point> p;  // 点のデータを保存


  scanf("%d %d %d %d",&N,&M,&P,&Q); // メタ情報を取得
  for(int i=0; i<N; i++){ // 点の座標を取得
    int x, y;
    scanf("%d %d",&x, &y);
    p.push_back(init_point(x,y));

    // printf("(x, y) = (%f, %f)\n",p[i].x, p[i].y);
  }
  for(int i=0; i<M; i++){

  }
  for(int i=0; i<Q; i++){

  }
  
  return 0;
}


Point init_point(double _x, double _y){
  Point point;
  point.x = _x;
  point.y = _y;
  point.done = false;
  point.cost = -1;
  return point;
}
