#include "stdio.h"
#include "vector"
#include "main.h"
#include "stdlib.h"

#include "debug.h"

void print_for_debug(vector<Point> p,int f1, vector<Point>c_p, int f2, vector<Point>a_p, int f3, vector< vector<int> >road, int f4, vector<Route>route, int f5){

  if(f1 == true){
    printf("___p (size:%lu)___\n",p.size());
    for(int i=0; i<p.size(); i++){
      printf("(%f,%f)\n",p[i].x, p[i].y);
    }
    puts("");
  }
  else if(f1 == 2){
    printf("___p (size:%lu)___\n",p.size());
    for(int i=0; i<p.size(); i++){
      printf("x:%f,y:%f\nnext(size=%lu): ",p[i].x, p[i].y, p[i].edges_to.size());
      for(int j=0; j<p[i].edges_to.size(); j++){
        printf("%d ",p[i].edges_to[j]);
      }
      puts("\n");
    }
    puts("");
  }

  if(f2 == true){
    printf("___c_p (size:%lu)___\n",c_p.size());
    for(int i=0; i<c_p.size(); i++){
      printf("(%f,%f)\n",c_p[i].x, c_p[i].y);
    }
    puts("");
  }
  else if(f2 == 2){
    printf("___c_p (size:%lu)___\n",c_p.size());
    for(int i=0; i<c_p.size(); i++){
      printf("x:%f,y:%f\nnext(size=%lu): ",c_p[i].x, c_p[i].y, c_p[i].edges_to.size());
      for(int j=0; j<c_p[i].edges_to.size(); j++){
        printf("%d ",c_p[i].edges_to[j]);
      }
      puts("\n");
    }
    puts("");
  }

  if(f3 == true){
    printf("___a_p (size:%lu)___\n",a_p.size());
    for(int i=0; i<a_p.size(); i++){
      printf("(%f,%f)\n",a_p[i].x, a_p[i].y);
    }
    puts("");
  }
  else if(f3 == 2){
    printf("___a_p (size:%lu)___\n",a_p.size());
    for(int i=0; i<a_p.size(); i++){
      printf("a_p[%d] ",i);
      if(i<N) printf("(%d)\n",i+1);
      else printf("(C%d)\n",i-N+1);
      printf("x:%f,y:%f\nnext(size=%lu): ",a_p[i].x, a_p[i].y, a_p[i].edges_to.size());
      for(int j=0; j<a_p[i].edges_to.size(); j++){
        printf("%d ",a_p[i].edges_to[j]);
      }
      printf("\nroad(size=%lu): ",a_p[i].edges_cost.size());
      for(int j=0; j<a_p[i].edges_cost.size(); j++){
        printf("%f ",a_p[i].edges_cost[j]);
      }
      puts("\n");
    }
    puts("");
  }

  if(f4){
    printf("___road (size:%lu)___\n",road.size());
    for(int i=0; i<road.size(); i++){
      for(int j=0; j<road[i].size(); j++){
        printf("%d ",road[i][j]);
      }
      printf("\n");
    }
    puts("");
  }

  if(f5){
    printf("___route (size:%lu)___\n",route.size());
    for(int i=0; i<route.size(); i++){
      printf("start:%d,goal:%d,want_num:%d\n"
      ,route[i].start,route[i].goal,route[i].want_num);
      printf("start:%s,goal:%s\n",route[i].C[0],route[i].C[1]);
      printf("route_data.size():%lu\n",route.size());
      for(int j=0; j<route[i].route_data.size(); j++){
        printf("cost:%f (route detail:{",route[i].route_data[j].cost);
        for(int k=0; k<route[i].route_data[j].route_detail.size(); k++) {
          printf("%d ",route[i].route_data[j].route_detail[k]);
        }
        puts("})");
      }
      puts("");
    }
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

void print_Point(Point p){
  printf("x:%f,y:%f\n[next]:\n",p.x, p.y);
  for(int i=0; i<p.edges_to.size(); i++) printf("%d ",p.edges_to[i]);
  printf("[road]:");
  for(int i=0; i<p.edges_cost.size(); i++) printf("%f ",p.edges_cost[i]);
  printf("\ndone:%d,cost:%f\n",p.done, p.cost);
  puts("");
}

void print_Route(Route r){
  printf("start:%d,goal:%d,want_num:%d\n",r.start,r.goal,r.want_num);
  printf("start:%s,goal:%s\n",r.C[0],r.C[1]);
  for(int i=0; i<r.route_data.size(); i++){
    printf("cost:%f (route detail:{",r.route_data[i].cost);
    for(int j=0; j<r.route_data[i].route_detail.size(); j++) {
      printf("%d ",r.route_data[i].route_detail[j]);
    }
    puts("})\n");
  }
}


Point func(Point p1, Point p2){
  static int ct = -1;
  ct++;
  return init_point(ct, ct);
}
