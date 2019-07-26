#include <math.h>
#include <utility>

#include "main.h"
#include "matrix.h"

using std::swap;

/************************************************************/
// addCrossPointMatrixで使う

const double EPS = 1/100000000;

static int in_cross_point(Point P1,Point P2,Point Q1,Point Q2){
  double det=(Q1.x-P1.x)*(P2.y-Q2.y)+(Q2.x-P2.x)*(Q1.y-P1.y);
  if(det==0 || (EPS<=det && det<=EPS)) return -1;

  double s=((P2.y-Q2.y)*(P2.x-P1.x)+(Q2.x-P2.x)*(P2.y-P1.y))/det;
  double t=((P1.y-Q1.y)*(P2.x-P1.x)+(Q1.x-P1.x)*(P2.y-P1.y))/det;

  if(0<=s && s<=1 && 0<=t && t<=1){
    double x=P1.x+(Q1.x-P1.x)*s;
    double y=P1.y+(Q1.y-P1.y)*s;

    for(int i=1; i<p.size(); i++){
      if(p[i].x == x && p[i].y == y) return i;
    }
  }

  return -1;
}



static bool include_in_vector(vector<int> v, int e){
  for(int i=0; i<v.size(); i++) if(v[i] == e) return true;
  return false;
}



static void sort_line(vector<int>& line){
  for(int i=0; i<line.size()-1; i++){
    for(int j=i+1; j>0; j--){
      if(p[line[j-1]].x > p[line[j]].x) {
        swap(line[j-1],line[j]);
      }
      else if(p[line[j-1]].x == p[line[j]].x && p[line[j-1]].y > p[line[j]].y){
        swap(line[j-1],line[j]);
      }
    }
  }
}

/************************************************************/


//長さを求める
double length(Point p1, Point p2){
  return sqrt(pow(p1.x - p2.x,2)+pow(p1.y - p2.y,2));
}



//行列の値を変更
void setMatrix(int p1, int p2, double length){
  matrix[p1][p2]=length;
  matrix[p2][p1]=length;
}



//最初の行列を作る
void initMatrix(){
  matrix = vector< vector<double> >(N+1, vector<double>(N+1,-1)); // 行列の初期化
  for(int i=1; i<=N; i++){
    matrix[i][i]=0;
  }
  for(int j=1; j<=M; j++){
    setMatrix(road[j][0],road[j][1],length(p[road[j][0]],p[road[j][1]]));
  }
}



// 交差点を追加
void addCrossPointMatrix(){
  // 交差点が無いとき、隣接行列の更新は必要ない
  if(c_p.size() == 1) return;

  vector< vector<int> > line(road);

  // すべての交わる点を道ごとに保存
  for(int i=1; i<road.size(); i++){
    for(int j=i+1; j<road.size(); j++){
      Point p1 = p[road[i][0]];
      Point p2 = p[road[j][0]];
      Point q1 = p[road[i][1]];
      Point q2 = p[road[j][1]];

      int tmp = in_cross_point(p1, p2, q1, q2);

      if(tmp != -1){
        if(!include_in_vector(line[i], tmp)) line[i].push_back(tmp);
        if(!include_in_vector(line[j], tmp)) line[j].push_back(tmp);
      }

    }
  }

  // 道ごとの点をx座標の小さい順に並べる
  for(int i=1; i<line.size(); i++) sort_line(line[i]);
  // 隣接行列を再構築
  int c_num = c_p.size()-1;
  vector< vector<double> > v(c_num, vector<double>(N+1,-1));
  matrix.insert(matrix.end(), v.begin(), v.end());

  for(int i=0; i<matrix.size(); i++){
    matrix[i].insert(matrix[i].end(), v[0].begin(), v[0].begin()+c_num);
  }

  for(int i=1; i<line.size(); i++){
    for(int j=0; j<line[i].size(); j++){
      for(int k=0; k<line[i].size(); k++){
        int ij = line[i][j];
        int ik = line[i][k];

        if(j == k) setMatrix(ij, ik, 0);
        else if(k == j+1 || k == j-1) setMatrix(ij,ik,length(p[ij], p[ik]));
        else setMatrix(ij, ik, -1.0);
      }
    }
  }

}


// 点の情報に隣接行列のデータをセット
void set_edge_data(){
  for(int i=1; i<p.size(); i++){
    for(int j=1; j<matrix[i].size(); j++){
      if(matrix[i][j] != -1.0){
        p[i].edges_to.push_back(j);
        p[i].edges_cost.push_back(matrix[i][j]);
      }
    }
  }
}
