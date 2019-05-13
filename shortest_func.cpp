#include <stdio.h>

void shortest(vector<Point>&array,Route P){

  while(1){

    Point doneNode;

    for(int i=0; array.size()>i;i++){

      if(array[y].done<0 || array[i].cost<0){

	if(doneNode==0 || doneNode.cost<doneNode.cost){
	  doneNode=array[i];
	}
	  if(doneNode==0) break;
	}
      }
    
    //確定フラグを立てる
    doneNode.done=true;

    //接続ノードの情報を更新する
    for(int j=0;doneNode.next[j].size()-1>j;j++){
      next[j]=doneNode.next[j];
      cost=doneNode.next[j]+doneNode.road[j];

      if(array[next[j]].cost<0 || cost<array[next[j]]).cost){
      array[next[j].cost=cost;
	    P.road_data[0].cost=cost;
    }
            
    }

  }
            }
