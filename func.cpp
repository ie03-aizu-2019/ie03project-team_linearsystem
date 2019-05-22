#include "main.h"
#include"debug.h"
Point init_point(double _x, double _y){
  Point point;
  point.x = _x;
  point.y = _y;
  point.done = false;
  point.cost = -1.0;
  return point;
}

Point init_point(double _x, double _y, int _index){
  Point point;
  point.index = _index;
  point.x = _x;
  point.y = _y;
  point.done = false;
  point.cost = -1.0;
  return point;
}

Route init_route(){
  Route r;
  scanf("%s",r.C[0]);
  if(r.C[0][0] == 'C'){
    r.start = atoi(&r.C[0][1]) + N + P - 1;
  }else{
    r.start = atoi(r.C[0]) - 1;
  }
  scanf("%s",r.C[1]);
  if(r.C[1][0] == 'C'){
    r.goal = atoi(&r.C[1][1]) + N + P - 1;
  }else{
    r.goal = atoi(r.C[1]) - 1;
  }
  scanf("%d",&r.want_num);

  r.route_data.reserve(r.want_num);
  {
    RouteData rd;
    rd.cost = -1;
    rd.route_detail = vector<int>(0,0);

    for(int i=0; i<r.want_num; i++){
      r.route_data.push_back(rd);
    }
  }


  return r;
}


void add_connect(vector<Point> &v, int n1, int n2){
  v[n1].edges_to.push_back(n2);
  v[n2].edges_to.push_back(n1);
}
