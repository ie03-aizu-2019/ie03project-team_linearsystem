#pragma once

#include "vector"
using namespace std;

#define BUF_SIZE 8

// Point   点のデータ関係
typedef struct {
  // 入力した順番 (バックアップ目的)
  int index;
  // 座標のデータ
  double x, y;
  // この点から伸びる道の情報
  // vector<int> next;
  vector<int> edges_to;
  // vector<double> road_len;
  vector<double> edges_cost;
  vector<int> edges_from;

  // ダイクストラ法のためのデータ
  int done;
  double cost;
} Point;

// RouteData   道の詳細情報
typedef struct {
  double cost;  // 道の長さ
  vector<int> route_detail; // 経路の詳細
} RouteData;

// Route   経路情報
typedef struct {
  // 始点終点のデータ
  int start, goal, want_num;
  char C[2][BUF_SIZE];

  // 経路のデータ
  vector<RouteData> route_data;
} Route;

// prototype deeclation
Point init_point(double, double);
Point init_point(double, double, int);
Route init_route();

void get_route(int *);
void add_connect(vector<Point>&, int, int);

Point cross_p(Point, Point, Point, Point);
void length(std::vector<Point>&);
void shortest(vector<Point>&,Route*);


// global variable
extern int N, M, P, Q;   // 座標の数, 道の数, 追加される地点の数, 経路問い合わせの数
