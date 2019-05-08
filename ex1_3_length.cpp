#include <stdio.h>
#include <vector>
#include <math.h>

void length(vector<point> & array){

  double l;//長さを一時保存

  //長さ計算

  for(int i=0;i<array.size();i++){//arrayのサイズの大きさ分
    for(int j=0;j<array[i].next.size();j++){//arrayのnextのサイズの大きさ分
	
      l=((array[i].x-array[array[i].next[j]].x)*(array[i].x-array[array[i].next[j]].x))
	  -((array[i].array[array[i].next[j]].y))*(array[i].array[array[i].next[j].y))); //長さを求める	
    
    l=sqrt(l);//平方根

	array[i].array[array[i].next[j]].road.push_back(l);//長さを入れる
      
      }
    }
  }
