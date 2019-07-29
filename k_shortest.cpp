#include <stdio.h>
#include <cmath>

#include "main.h"

/************************************************************/

typedef struct {
  double cost;
  vector<int> course;
} TMP_ROUTE;

static vector<TMP_ROUTE> tmp_route; // n番目の最短経路の候補

static void tmp_route_insert(TMP_ROUTE);
static void dijkstra(vector<Point>&,Route);
static void search_path(vector<Point>,Route,vector<int>&);
static void set_path(Route*,int,double,vector<int>);
static void set_1st_shortest_path(vector<Point>,Route);

static void delete_edge(Point&, int);
static void set_super_node(vector<Point>&, int, Route, int);

/************************************************************/

static void tmp_route_insert(TMP_ROUTE tmp){
  if(tmp.cost == -1.0) return;
  for(const auto& e: tmp_route) if(tmp.cost == e.cost) return;

  for(int i=0; i<tmp_route.size(); i++){
    if(tmp.cost < tmp_route[i].cost){
      tmp_route.insert(tmp_route.begin() + i, tmp);
      return;
    }
  }
  tmp_route.push_back(tmp);
}


static void dijkstra(vector<Point>& node, Route r_p){
  // 初期化
  for(int i=1; i<node.size();i++){
    node[i].done = false;
    node[i].cost = -1.0;
    node[i].from = -1;
  }
  node[r_p.s].cost = 0.0;
  node[r_p.s].from = r_p.s;

  while(1){
    Point doneNode = {-1};

    // 確定ノードの探索
    for(int i=1; i<node.size(); i++){
      if(node[i].done || node[i].cost == -1.0) continue;
      if(doneNode.index==-1 || node[i].cost<doneNode.cost) doneNode=node[i];
    }
    // 確定ノードが無い　→　終了
    if(doneNode.index == -1) break;
    //確定フラグを立てる
    node[doneNode.index].done=true;

    //接続ノードの情報を更新する
    for(int i=0; i<doneNode.edges_to.size(); i++){
      int    next = doneNode.edges_to[i];
      double cost = doneNode.cost + doneNode.edges_cost[i];
      int    from = doneNode.index;

      if(node[next].cost == -1.0 || cost < node[next].cost){
        node[next].cost = cost;
        node[next].from = from;
      }
    }

  }

}


static void search_path (vector<Point> node, Route r_p, vector<int>& course){
  course.push_back(r_p.d);

  int while_count = 0, from;
  while(1){
    from = node[course.front()].from;
    course.insert(course.begin(), from);

    if(from == r_p.s) return;
    if(++while_count > node.size()){
      vector<int> v;
      course.swap(v);
      return;
    }
  }
}


static void set_path(Route *r_p, int n, double cost, vector<int> course){
  r_p->cost[n] = cost;
  r_p->course[n] = course;
}


static void set_1st_shortest_path(vector<Point> node, Route *r_p){
  vector<int> course;
  search_path(node, *r_p, course);
  if(course.size() != 0) set_path(r_p, 0, node[r_p->d].cost, course);

}


static void delete_edge(Point& node, int delete_index){
  for(int i=0; i<node.edges_to.size(); i++){
    if(node.edges_to[i] == delete_index){
      node.edges_to.erase(node.edges_to.begin()+i);
      node.edges_cost.erase(node.edges_cost.begin()+i);
    }
  }
}


static void set_super_node
(vector<Point>& sp, int spNode, Route r_p, int num){
  vector<int> spNodeList(r_p.course[num-1]);
  vector<int> spRoot;


  // set super_root
  for(int i=0; i<spNodeList.size()-1; i++){
    spRoot.push_back(spNodeList[i]);
    if(spNodeList[i] == spNode) break;


    double tmp_cost;
    for(int j=0; j<sp[spNodeList[i]].edges_to.size(); j++){
      if(sp[spNodeList[i]].edges_to[j] == spNodeList[i+1]){
        tmp_cost = sp[spNodeList[i]].edges_cost[j];
      }
    }

    sp[spNodeList[i]].edges_to.clear();
    sp[spNodeList[i]].edges_to.shrink_to_fit();
    sp[spNodeList[i]].edges_to.push_back(spNodeList[i+1]);

    sp[spNodeList[i]].edges_cost.clear();
    sp[spNodeList[i]].edges_cost.shrink_to_fit();
    sp[spNodeList[i]].edges_cost.push_back(tmp_cost);
  }

  // set super_node
  for(const auto& e: r_p.course){
    if(e.empty()) break;

    for(int i=0; i<spRoot.size(); i++){
      if(e.size() <= i && spRoot[i] != e[i]) break;
      if(i == spRoot.size()-1) delete_edge(sp[spRoot[i]], e[i+1]);
    }
  }

}

/************************************************************/

void k_shortest(Route *r_p){
  // 開始地点が不正な値なとき
  if(r_p->s > p.size()) {
    return;
  }

  // 第１最短経路
  dijkstra(p, *r_p);
  set_1st_shortest_path(p, r_p);



  for(int i=1; i<r_p->k; i++){
    if(r_p->cost[i-1] == -1.0) return;

    vector<int> spNodeList(r_p->course[i-1].begin(),r_p->course[i-1].end()-1);
    for(const auto& spNode: spNodeList){
      // spur node 適応済みのノード sp
      vector<Point> sp(p);
      set_super_node(sp, spNode, *r_p, i);

      dijkstra(sp, *r_p);

      TMP_ROUTE tmp = {sp[r_p->d].cost};
      search_path(sp, *r_p, tmp.course);
      tmp_route_insert(tmp);
    }

    // tmp_routeの中でcostが最小のやつをr_pに入れる
    if(tmp_route.empty()) break;
    if(tmp_route.size() != 0){
      TMP_ROUTE tmp = tmp_route.front();

      tmp_route.erase(tmp_route.begin());
      set_path(r_p, i, tmp.cost, tmp.course);

    }

  }


  tmp_route.clear();
  tmp_route.shrink_to_fit();

  return;
}
