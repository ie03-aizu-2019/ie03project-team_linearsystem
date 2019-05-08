#include "stdio.h"
#include "vector"
#include "main.h"
#include "stdlib.h"

#include "debug.h"

void print_for_debug(vector<Point> p, vector<Point>c_p, vector<Point>a_p, vector< vector<int> >road, vector< vector<int> >route){

  if(true){
    printf("p (size:%lu)\n",p.size());
    for(int i=0; i<p.size(); i++){
      printf("(%f,%f)\n",p[i].x, p[i].y);
    }
    puts("");
  }
  if(true){
    printf("c_p (size:%lu)\n",c_p.size());
    for(int i=0; i<c_p.size(); i++){
      printf("(%f,%f)\n",c_p[i].x, c_p[i].y);
    }
    puts("");
  }
  if(true){
    printf("a_p (size:%lu)\n",a_p.size());
    for(int i=0; i<a_p.size(); i++){
      printf("(%f,%f)\n",a_p[i].x, a_p[i].y);
    }
    puts("");
  }
  if(true){
    printf("road (size:%lu)\n",road.size());
    for(int i=0; i<road.size(); i++){
      for(int j=0; j<road[i].size(); j++){
        printf("%d ",road[i][j]);
      }
      printf("\n");
    }
    puts("");
  }
  if(true){
    printf("route (size:%lu)\n",route.size());
    for(int i=0; i<route.size(); i++){
      for(int j=0; j<route[i].size(); j++){
        printf("%d ",route[i][j]);
      }
      printf("\n");
    }
    puts("");
  }

}

void print_for_debug(vector<Point> v, char* name){
  printf("%s (size:%lu)\n",name ,v.size());
  for(int i=0; i<v.size(); i++){
    printf("(%f,%f)\n",v[i].x, v[i].y);
  }
  puts("");
}

void print_for_debug(vector< vector<int> > v, char* name){
  printf("%s (size:%lu)\n",name, v.size());
  for(int i=0; i<v.size(); i++){
    for(int j=0; j<v[i].size(); j++){
      printf("%d ",v[i][j]);
    }
    printf("\n");
  }
  puts("");
}


Point func(Point p1, Point p2){
  static int ct = -1;
  ct++;
  return init_point(ct, ct);
}
