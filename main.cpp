#include <stdio.h>

#include "main.h"
#include "initialize.h"
#include "matrix.h"
#include "cross_point.h"
#include "shortest_path.h"

#include "output.h"

int N, M, P, Q;     // 座標の数, 道の数, 追加される地点の数, 経路問い合わせの数
vector<Point> p(1,init_point(-1,-1,-1));    // 点の情報
vector<Point> inp_p(1,init_point(-1,-1,-1));    // 入力した点の情報
vector<Point> add_p(1,init_point(-1,-1,-1));    // 入力した点の情報
vector<Point> c_p(1,init_point(-1,-1,-1));  // 交差点の情報(追加情報)
vector< vector<int> > road(1, vector<int>(2, -1)); // 道の情報を保存
vector<Route> route(1,init_route0());  // 経路の情報を保存
vector< vector<double> > matrix; // 隣接行列

int main(int argc, char* argv[]){
  //データの取得
  data_input();

  // 隣接行列の作成
  initMatrix();

  // 交差点の検出
  int count = search_cross_point();

  // 隣接行列に交差点の情報を追加
  addCrossPointMatrix();

  // 点の情報に隣接行列のデータをセット
  set_edge_data();

  // 最短経路を求める
  for(int i=1; i<route.size(); i++) {
    shortest(&route[i]);

    phase1_4_out(route[i]);
  }



  return 0;
}
