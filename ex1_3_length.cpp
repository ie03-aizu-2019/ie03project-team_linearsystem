#include <stdio.h>
#include <math.h>
#include "main.h"

void length(std::vector<Point> & array){

  double l;//長さを一時保存

  //長さ計算

  for(int i=0;i<array.size();i++){//arrayのサイズの大きさ分
    for(int j=0;j<array[i].edges_to.size();j++){//arrayのnextのサイズの大きさ分

      /*
      l=((array[i].x-array[array[i].edges_to[j]].x)*(array[i].x-array[array[i].edges_to[j]].x))
      -(((array[i].y-array[array[i].edges_to[j]].y))*(array[i].y-array[array[i].edges_to[j]].y))); //長さを求める

      l=sqrt(l);//平方根
      */
      Point next = array[array[i].edges_to[j]];
      l = sqrt(pow(array[i].x - next.x,2)+pow(array[i].y - next.y,2));

      array[i].edges_cost.push_back(l);//長さを入れる

    }
  }
}
