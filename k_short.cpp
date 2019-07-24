#include <iostream>
#include <vector>
using std::vector;

// typedef struct{
//   vector< vector<int> >course;
// } Route;



vector<int> kshort(int super, Route kr){
//int:super Node
//Route:配列A(Route.Course)
//Courseは二次元配列
//Route.course=[i][j]の形でみれる

 vector<int> v;//雑に宣言

// super node から繋がるところを見つけて
// v.push_back(繋がるところ);
for(int i=0; i<kr.course.size();i++){
  for(int j=0; j<kr.course[i].size()-1;j++){
  if(super==kr.course[i][j]){
    v.push_back(kr.course[i][j+1]);
    }
  }
}

return v;
}

// int main(){
// int super=4;
// Route kr;
//   kshort(super,kr);
//   return 0;
// }
