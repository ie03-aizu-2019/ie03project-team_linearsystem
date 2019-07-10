#include <stdio.h>
#include"main.h"
#include"debug.h"

void shortest(p,Route *r_p){
  // 開始地点が不正な値なとき
  if(r_p->start > p.size()) {
    return;
  }

  // 初期化
  for(int i=0; i<p.size();i++){
    p[i].done = false;
    p[i].cost = -1.0;
    p[i].from = -1;
  }
  p[r_p->start].cost = 0.0;
  p[r_p->start].from = 0;


  while(1){
    Point doneNode;
    doneNode.x = -1;

    for(int i=0; p.size()>i;i++){
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
        py[next].from=from;
      }
    }
  }
  // startからgoalまでの最短距離を保存
  r_p->route_data[0].cost = p[r_p->goal].cost;
  r_p->route_data[0].route_detail.insert(r_p->route_data[0].route_detail.begin(),r_p->goal);
  while(1){
    int from = p[r_p->route_data[0].route_detail[0]].from;
    r_p->route_data[0].route_detail.insert(r_p->route_data[0].route_detail.begin(),from);
    if(from == r_p->start) break;
  }
}
