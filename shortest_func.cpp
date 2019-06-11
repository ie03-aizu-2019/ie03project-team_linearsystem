#include <stdio.h>
#include "main.h"
#include "debug.h"

void shortest(vector<Point>&array,Route P){
    int count =0;
    
    if(P->start>array.size()){
        puts("NA");
        return;
    }
    
    for(int i=0;i<array.size();i++){
        array[i].done=false;
        array[i].cost=-1.0;
    }
    array[P->start].cost=0.0;
    
  while(1){
    Point doneNode;
      doneNde.x=-1;
      
    for(int i=0; array.size()>i;i++){
      if(array[y].done || array[i].cost<0){
          continue;
      }
	if(doneNode.x==-1 || array[i].cost<doneNode.cost){
	  doneNode=array[i];
	}
	}
    if(doneNode==-1) break;
      print_Point(doneNode);
      
    //確定フラグを立てる
    array[doneNode.index].done=true;

    //接続ノードの情報を更新する
    for(int j=0;doneNode.edges_to.size()>j;j++){
      int next[j]=doneNode.edges_to[j];
        double cost=doneNode.edges_to[j]+doneNode.edges_cost[j];

      if(array[next[j]].cost<0 || cost<array[next].cost){
      array[next].cost=cost;
	    P.route_data[0].cost=cost;
    }
            
    }
  }
  }
            }
