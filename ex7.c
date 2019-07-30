#include<stdio.h>
#include<math.h>


typedef struct{
    double x;
    double y;
    double d;
}POINT;


POINT new_point(POINT new_p, POINT s, POINT g);
//Global value
//既存の点情報
static POINT p[6];
//             p[1].x=0,p[1].y=0,
//             p[2].x=2,p[2].y=5,
//             p[3].x=4,p[3].y=7,
//             p[4].x=5,p[4].y=5,
//             p[5].x=7,p[5].y=1,
//             p[6].x=9,p[6].y=5;


int main(){
    
    int n,i,j,k;
    POINT min;
    int convi[5][2]={{1,4},{1,6},{2,5},{3,5},{4,6}};//繋げる点の組み合わせ
    
    
//追加する点の情報
    printf("Input number of New Point->");
    scanf("%d",&n);
    
    POINT new_p[n];
    POINT tmp;
//    new_p.x=5;
//    new_p.y=1;
    
    printf("Input New Point\n");
    for(i=0;i<n;i++){
        scanf("%lf %lf",&new_p[i].x,&new_p[i].y);
              }

    //付け足す点の情報入力
    printf("Input Point\n");
    for(i=0;i<6;i++){
        scanf("%lf %lf",&p[i].x,&p[i].y);
    }
//     printf("Input convination of Points\n");
//   //どの点が繋がるか
//              for(i=0;i<5;i++){
//                  for(j=0;j<2;j++){
//                      scanf("%d",&convi[i][j]);
//                  }
//              }
   
  //付け足す点の数だけ繰り返す
   for(k=0;k<n;k++){
            min.d=9999;//初期化
              for(i=0;i<5;i++){//5回
               tmp= new_point(new_p[k],p[convi[i][0]-1],p[convi[i][1]-1]);
                  if(min.d>tmp.d){
                      min.d=tmp.d;
                      min.x=tmp.x;
                      min.y=tmp.y;
              }
            }
//    tmp= new_point(new_p,p[1],p[4]);
       
       
    printf("the anser are x:%lf,y:%lf d:%lf\n\n",min.x,min.y,min.d);
   }
    return 0;
}
              
              
              
              //KANSU!//
              
              
    POINT new_point(POINT new_p,POINT p3, POINT p6){
        POINT hit_point[2];//ヒットしたポイント
//    case1
    //２点間の式をもとめる。
    double x1=0,y1=0;//始点と終点の差
    double a=0,b=0;//y=ax+b
    double c=0;//y=-x/a+c
    double dis3=0,dis6=0;//new_point と始点, new_point と終点の距離
   
        
    
    
          ////          ////
       ///    ///    ///    ///
    //           ///           //
    //1つの点と1つの線の二人の作業 //
      //         💚          //
         //               //
           //        ///
             //  ///

        
        x1=p6.x-p3.x;
        y1=p6.y-p3.y;
        a=y1/x1;
        b=p3.y-a*p3.x;
    //距離と点を求める
        double d=0;
    d=fabs(-a*new_p.x+new_p.y-b)/sqrt(a*a+1);//点と線の距離
    //連立方程式
    //y=ax+b-- p
    //y=-x/a+c-- new_point
    //c=y+x/a=new_p.y+new_p.x/a
    //0=ax+x/a+(b-c)
    
    
    //cを求める
    //new_p[0].y=-new_p[0].x/a+c;
    c=new_p.y+(new_p.x/a);
    //交差点を求める
    //(a^2+1/a)x=-(b-c)
    //x=(c-b)*a/(a^2+1)
    hit_point[0].x=(c-b)*a/(a*a+1);
    hit_point[0].y=hit_point[0].x*a+b;//xを代入
//    printf("hit_point[0].x:%lf\n",hit_point[0].x);
//    printf("hit_point[0].y:%lf\n",hit_point[0].y);
//    printf("d:%lf\n",d);
    
    //判定用Y
    double miny,maxy;
    if(p6.y>p3.y){
        miny=p3.y;
        maxy=p6.y;
    }else{
        miny=p6.y;
        maxy=p3.y;
    }
    //
    //判定一つの線と点
    if((p3.x<=hit_point[0].x && hit_point[0].x<=p6.x) &&
       (miny<=hit_point[0].y && hit_point[0].y<=maxy)){//戦場に交点はあるか
        hit_point[0].d=d;
//       printf("dis1:%lf\n",d);
//        printf("x:%lf y:%lf\n",hit_point[0].x,hit_point[0].y);
    }else{
        dis3=sqrt(fabs(new_p.x-p3.x)*fabs(new_p.x-p3.x)+fabs(new_p.y-p3.y)*fabs(new_p.y-p3.y));
        dis6=sqrt(fabs(new_p.x-p6.x)*fabs(new_p.x-p6.x)+fabs(new_p.y-p6.y)*fabs(new_p.y-p6.y));
        if(dis3>dis6){
            hit_point[0].x=p6.x;
            hit_point[0].y=p6.y;
            hit_point[0].d=dis6;
//            printf("dis2:%lf\n",dis6);
//            printf("x:%lf y:%lf\n",hit_point[0].x,hit_point[0].y);
        }else{
            hit_point[0].x=p3.x;
            hit_point[0].y=p3.y;
            hit_point[0].d=dis3;
//            printf("dis3:%lf\n",dis3);
//            printf("x:%lf y:%lf\n",hit_point[0].x,hit_point[0].y);
            
        }
    }
//        printf("p3.x:%lf p3.y:%lf\n",p3.x,p3.y);
//        printf("p6.x:%lf p6.y:%lf\n",p6.x,p6.y);
//
    
//        printf("in function x: %lf,y: %lf d=%lf\n",hit_point[0].x,hit_point[0].y,hit_point[0].d);
        return hit_point[0];
    
    }
