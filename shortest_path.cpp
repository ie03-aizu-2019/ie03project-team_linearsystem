#include "main.h"
#include "shortest_path.h"


void shortest(Route *r_p){
  // 開始地点が不正な値なとき
  if(r_p->s > p.size()) {
    return;
  }

  // 初期化
  for(int i=1; i<p.size();i++){
    p[i].done = false;
    p[i].cost = -1.0;
    p[i].from = -1;
  }
  p[r_p->s].cost = 0.0;
  p[r_p->s].from = 0;

  while(1){
    Point doneNode;
    doneNode.x = -1;

    for(int i=1; p.size()>i;i++){
      if((p[i].done || p[i].cost<0)) continue;
      if(doneNode.x==-1 || p[i].cost<doneNode.cost) doneNode=p[i];
    }
    if(doneNode.x==-1) break;
    //確定フラグを立てる
    p[doneNode.index].done=true;

    //接続ノードの情報を更新する
    for(int j=0;doneNode.edges_to.size()>j;j++){
      int next=doneNode.edges_to[j];
      double cost=doneNode.cost+doneNode.edges_cost[j];
      int from=doneNode.index;

      if(p[next].cost<0 || cost<p[next].cost){
        p[next].cost=cost;
        p[next].from=from;
      }
    }

  }

  // startからgoalまでの最短距離を保存
  r_p->cost[0] = p[r_p->d].cost;
  r_p->course[0].insert(r_p->course[0].begin(),r_p->d);

  int while_count = 0;
  while(1){
    int from = p[r_p->course[0][0]].from;
    r_p->course[0].insert(r_p->course[0].begin(),from);
    if(from == r_p->s) break;
    if(++while_count > p.size()) {
      r_p->cost[0] = -1.0;
      return;
    }
  }
}
