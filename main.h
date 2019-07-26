#pragma once

#include <vector>
using std::vector;

#define BUF_SIZE 8

// Point (地点の情報)
typedef struct{
  // 入力した順番 (バックアップ目的)
  int index;
  // 座標
  double x, y;

  // 点から伸びる情報
  vector<int> edges_to;
  vector<double> edges_cost;

  // ダイクストラ法のためのデータ
  int done;     // 確定フラグ
  double cost;  // この点までの最短距離
  int from;     // どこの点から来たか
}Point;


// Route (経路情報)
typedef struct{
  // 始点、終点、問い合わせ数
  int s, d, k;
  char start[BUF_SIZE], goal[BUF_SIZE];

  // 経路の詳細データ
  vector<double> cost;
  vector< vector<int> > course;
}Route;

// グローバル変数
extern int N, M, P, Q;
extern vector<Point> p;
extern vector<Point> inp_p;
extern vector<Point> add_p;
extern vector<Point> c_p;
extern vector< vector<int> > road;
extern vector<Route> route;
extern vector< vector<double> > matrix;
