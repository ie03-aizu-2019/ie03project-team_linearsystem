#include "stdio.h"
#include "main.h"
#include "stdlib.h"

#include "debug.h"

int N, M, P, Q;   // 座標の数, 道の数, 追加される地点の数, 経路問い合わせの数

int main(){
  vector<Point> p;  // 点のデータを保存
  vector<Point> c_p;  // 交差点のデータを保存
  vector<Point> a_p;  // すべての点のデータを保存
  vector< vector<int> > road(0, vector<int>(2, 0)); // 道の情報を保存
  vector<Route> route; // 経路の視点終点を保存

// データの取得
  scanf("%d %d %d %d",&N,&M,&P,&Q); // メタ情報を取得
  for(int i=0; i<N; i++){ // 点の座標を取得
    int x, y;
    scanf("%d %d",&x, &y);
    p.push_back(init_point(x,y,i));
  }
  for(int i=0; i<M; i++){ // 道の情報を取得
    int input[2];
    scanf("%d %d",&input[0], &input[1]);
    road.push_back(vector<int>(input, input+2));
    add_connect(p, road[i][0]-1, road[i][1]-1);
  }
  for(int i=0; i<P; i++){ // 追加の点の座標を取得
    int x, y;
    scanf("%d %d",&x, &y);
    p.push_back(init_point(x,y,N+i));
  }
  for(int i=0; i<Q; i++){ // 経路の情報を取得
    route.push_back(init_route());
  }

  // すべての点をまとめる
  a_p = p;

  //交差点を求める
  int cp_num = 0; //　交差点の数
  vector< vector<int> > cp_where(road.size(), vector<int>(0, 0)); // 道にできた交差点
  for(int i=0; i<road.size(); i++){
    for(int j=i+1; j<road.size(); j++){
      Point p1 = p[road[i][0]-1];
      Point p2 = p[road[j][0]-1];
      Point q1 = p[road[i][1]-1];
      Point q2 = p[road[j][1]-1];
      Point tmp = cross_p(p1, p2, q1, q2);
      // printf("(%d:%d)\t(%f %f)\n",i,j,tmp.x, tmp.y);
      if(tmp.x != -1 && tmp.y != -1 &&
        (tmp.x != p1.x && tmp.x != q1.x && tmp.x != p2.x && tmp.x != q2.x) ){
          // printf("(%d:%d)\t(%f %f)\n",i,j,tmp.x, tmp.y);
          tmp.index = cp_num++;
          c_p.push_back(tmp);

          tmp.index += N + P;
          a_p.push_back(tmp);
          add_connect(a_p,tmp.index,road[i][0]-1);
          add_connect(a_p,tmp.index,road[i][1]-1);
          add_connect(a_p,tmp.index,road[j][0]-1);
          add_connect(a_p,tmp.index,road[j][1]-1);

          cp_where[i].push_back(tmp.index);
          cp_where[j].push_back(tmp.index);
        }
      }
    }
    // 交差点同士をつなげる
    for(int i=0; i<cp_where.size(); i++){
      for(int j=0; j<cp_where[i].size();j++){
        for(int k=j+1; k<cp_where[i].size(); k++){
          add_connect(a_p,cp_where[i][j],cp_where[i][k]);
        }
      }
    }

    // 長さを求める
    length(a_p);

    // 最短経路を求める
    for(int i=0; i<route.size(); i++){
      printf("route:%d\t",i);
      // shortest(a_p, &route[i]);
    }

    print_for_debug(p, false, c_p, false, a_p, 2, road, false, route ,true);

    return 0;
  }