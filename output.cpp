#include <stdio.h>

#include "main.h"
#include "output.h"


void phase1_4_out(Route out){
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
