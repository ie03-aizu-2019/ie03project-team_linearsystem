#include <stdio.h>

#include "main.h"
#include "output.h"


void phase1_4_out(){
  for(const auto& out: route){
    if(out.cost[0] == -1.0){
      puts("NA");
      return;
    }

    printf("%.5f\n",out.cost[0]);

    for(const auto& e: out.course[0]) {
      if(e <= N) printf("%d ",e);
      else printf("C%d ",e-N);
    }
    puts("");
  }
}


void phase2_6_out() {
  for(const auto& out: route){
    if(out.s < 0) continue;
    if(out.cost[0] == -1.0) {
      puts("NA");
      continue;
    }

    for(int i=0; i<out.cost.size(); i++){
      if(out.cost[i] == -1.0) break;

      printf("%.5f\n",out.cost[i]);

      for(const auto& e: out.course[i]){
        if(e <= N) printf("%d ",e);
        else printf("C%d ",e-N);
      }
      puts("");
    }
  }
}
