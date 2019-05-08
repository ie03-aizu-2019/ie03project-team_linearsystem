#include "stdio.h"

#include "main.h"
#include "stdlib.h"

#include "debug.h"


int main(){
  int N, M, P, Q;   // 座標の数, 道の数, 追加される地点の数, 経路問い合わせの数
  vector<Point> p;  // 点のデータを保存
  vector<Point> c_p;  // 交差点のデータを保存
  vector<Point> a_p;  // すべての点のデータを保存
  vector< vector<int> > road(0, vector<int>(2, 0)); // 道の情報を保存
  vector< vector<int> > route(0, vector<int>(3, 0)); // 経路の視点終点を保存


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
        tmp[j] = atoi(&input[1]) + N + P;
      }else{
        tmp[j] = atoi(input);
      }
    }
    scanf("%d",&tmp[2]);
    route.push_back(vector<int>(tmp, tmp+3));
  }
  // print_for_debug(p, c_p, a_p, road, route);


  //交差点を求める
  for(int i=0; i<road.size(); i++){
    for(int j=i+1; j<road.size(); j++){
      Point p1 = p[road[i][0]-1];
      Point p2 = p[road[j][0]-1];
      Point q1 = p[road[i][1]-1];
      Point q2 = p[road[j][1]-1];
      Point tmp = cross_p(p1, p2, q1, q2);
      printf("",i,j);
      // printf("(%d:%d)\t(%f %f)\n",i,j,tmp.x, tmp.y);
      if(tmp.x != -1 && tmp.y != -1 &&
        (tmp.x != p1.x && tmp.x != q1.x && tmp.x != p2.x && tmp.x != q2.x) ){
          printf("(%f %f)\n",tmp.x, tmp.y);
          c_p.push_back(tmp);
        }
      }
    }

    // 点の情報をまとめる
    a_p = p;
    a_p.insert(a_p.end(), c_p.begin(), c_p.end());


    // 最短経路を求める
    for(int i=0; i<route.size(); i++){
      shortest(a_p, route[i][0], route[i][1]);
    }


    // print_for_debug(p, c_p, a_p, road, route);


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
