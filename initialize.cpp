#include <stdio.h>

#include "main.h"
#include "initialize.h"

Point init_point(double _x, double _y){
  Point point;
  point.index = 0;
  point.x = _x;
  point.y = _y;
  point.done = false;
  point.cost = -1.0;
  point.from = -1;
  return point;
}



Point init_point(double _x, double _y, int _index){
  Point point;
  point.index = _index;
  point.x = _x;
  point.y = _y;
  point.done = false;
  point.cost = -1.0;
  point.from = -1;
  return point;
}



Route init_route0(){
  Route r = {-1,-1,-1};
  return r;
}



Route init_route(){
  Route r;

  scanf("%s %s %d ",r.start, r.goal, &r.k);

  r.s = ((r.start[0] == 'C') ? (atoi(&r.start[1])+N+P) : atoi(r.start));
  r.d = ((r.goal[0] == 'C') ? (atoi(&r.goal[1])+N+P) : atoi(r.goal));

  for(int i=0; i<r.k; i++){
    vector<int> v;
    r.cost.push_back(-1);
    r.course.push_back(v);
  }

  return r;
}



void data_input(){
  // メタ情報を取得
  scanf("%d %d %d %d",&N,&M,&P,&Q);

  // 点の座標を取得
  for(int i=1; i<=N; i++){
    int x, y;
    scanf("%d %d",&x, &y);

    p.push_back(init_point(x,y,i));
    inp_p.push_back(init_point(x,y,i));
  }

  // 道の情報を取得
  for(int i=1; i<=M; i++){
    int input[2];
    scanf("%d %d",&input[0], &input[1]);
    road.push_back(vector<int>(input, input+2));
  }

  // 追加の点の座標を取得
  for(int i=1; i<=P; i++){
    int x, y;
    scanf("%d %d",&x, &y);
    add_p.push_back(init_point(x,y,i));
  }

  // 経路の情報を取得
  for(int i=1; i<=Q; i++){
    route.push_back(init_route());
  }
}
