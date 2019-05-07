#include "stdio.h"
#include "vector"
#include "main.h"
#include "stdlib.h"

void print_for_debug(vector<Point>, vector< vector<int> >, vector< vector<int> >, vector<Point>);

int main(){
  int N, M, P, Q;   // 座標の数, 道の数, 追加される地点の数, 経路問い合わせの数
  vector<Point> p;  // 点のデータを保存
  vector< vector<int> > road(0, vector<int>(2, 0)); // 道の情報を保存
  vector< vector<int> > route(0, vector<int>(3, 0)); // 経路の視点終点を保存
  vector<Point> c_p;  // 交差点のデータを保存

  scanf("%d %d %d %d",&N,&M,&P,&Q); // メタ情報を取得
  for(int i=0; i<N; i++){ // 点の座標を取得
    int x, y;
    scanf("%d %d",&x, &y);
    p.push_back(init_point(x,y));
  }
  for(int i=0; i<M; i++){ // 道の情報を取得
    int input[2];
    scanf("%d %d",&input[0], &input[1]);
    road.push_back(vector<int>(input, input+2));
  }
  for(int i=0; i<P; i++){ // 追加の点の座標を取得
    int x, y;
    scanf("%d %d",&x, &y);
    p.push_back(init_point(x,y));
  }
  for(int i=0; i<Q; i++){ // 経路の情報を取得
    int tmp[3];
    for(int j=0; j<2; j++){
      char input[8];
      scanf("%s",input);
      if(input[0] == 'C'){
        tmp[j] = atoi(&input[1]) + M + P;
      }else{
          tmp[j] = atoi(input);
      }
    }
    scanf("%d",&tmp[2]);
    route.push_back(vector<int>(tmp, tmp+3));
  }
  

    print_for_debug(p, road, route, c_p);

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
