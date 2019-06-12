#include <stdio.h>
#include"main.h"
#include"debug.h"

void shortest(vector<Point>&array,Route *p){
  // 開始地点が不正な値なとき
  if(p->start > array.size()) {
    return;
  }

  // 初期化
  for(int i=0; i<array.size();i++){
    array[i].done = false;
    array[i].cost = -1.0;
    array[i].from = -1;
  }
  array[p->start].cost = 0.0;
  array[p->start].from = 0;


  while(1){
    Point doneNode;
    doneNode.x = -1;

    for(int i=0; array.size()>i;i++){
      if((array[i].done || array[i].cost<0)) continue;
      if(doneNode.x==-1 || array[i].cost<doneNode.cost) doneNode=array[i];
    }
    if(doneNode.x==-1) break;
    //確定フラグを立てる
    array[doneNode.index].done=true;

    //接続ノードの情報を更新する
    for(int j=0;doneNode.edges_to.size()>j;j++){
      int next=doneNode.edges_to[j];
      double cost=doneNode.cost+doneNode.edges_cost[j];
      int from=doneNode.index;

      if(array[next].cost<0 || cost<array[next].cost){
        array[next].cost=cost;
        array[next].from=from;
      }
    }
  }
  // startからgoalまでの最短距離を保存
  p->route_data[0].cost = array[p->goal].cost;
  p->route_data[0].route_detail.insert(p->route_data[0].route_detail.begin(),p->goal);
  while(1){
    int from = array[p->route_data[0].route_detail[0]].from;
    p->route_data[0].route_detail.insert(p->route_data[0].route_detail.begin(),from);
    if(from == p->start) break;
  }
}
