#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


// Point   点のデータ関係
typedef struct {
  // 入力した順番 (バックアップ目的)
  int index;
  // 座標のデータ
  double x, y;
  // この点から伸びる道の情報
  vector<int> edges_to;
  vector<double> edges_cost;

  // ダイクストラ法のためのデータ
  int done;     // 確定フラグ
  double cost;  // この点までの最短距離
  int from;     // どの点から来たか保存
} Point;

// 関数
void setMatrix(int,int,double);
void initMatrix();
double length(Point, Point);


int N, M, P, Q;     // 座標の数, 道の数, 追加される地点の数, 経路問い合わせの数
vector<Point> p;    // 点の情報
vector<Point> c_p;  // 交差点の情報
vector< vector<int> > road(0, vector<int>(2, 0)); // 道の情報を保存
vector< vector<double> > matrix; // 隣接行列

int main(int argc, char* argv[]){
  N=4; M=2;

 Point pp;
 p = vector<Point>(N,pp);
 p[0].x=0; p[0].y=0;
 p[1].x=5; p[1].y=5;
 p[2].x=2; p[2].y=5;
 p[3].x=7; p[3].y=1;

 road = vector< vector<int> >(M, vector<int>(M,0));
 road[0][0]=1; road[0][1]=2;
 road[1][0]=3; road[1][1]=4;
 /* 初期化ここまで */

 initMatrix();
 return 0;
}

//行列の値を変更
// void setMatrix(点, 点, 長さ){//
void setMatrix(int p1, int p2, double length){//
  matrix[p1][p2]=length;
  matrix[p2][p1]=length;

}
//最初の行列を作る
void initMatrix(){
  matrix = vector< vector<double> >(N, vector<double>(N,-1)); // 行列の初期化
  for(int i=0; i<N; i++){
    matrix[i][i]=0;
  }
  for(int j=0; j<M; j++){
    setMatrix(road[j][0]-1,road[j][1]-1,length(p[road[j][0]-1],p[road[j][1]-1]));
  }
  for(int i=0; i<N ;i++){
    for(int j=0; j<N ;j++){
      printf("%f ",matrix[i][j]);
    }
    printf("\n");
  }
}
  //長さを求める
double length(Point p1, Point p2){
  return sqrt(pow(p1.x - p2.x,2)+pow(p1.y - p2.y,2));
}
