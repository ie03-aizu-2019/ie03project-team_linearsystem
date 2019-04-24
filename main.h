using namespace std;

typedef struct {
  // 座標のデータ
  double x, y;
  // この点から伸びる道の情報
  vector<int> next;
  vector<int> road;

  // ダイクストラ法のためのデータ
  int done;
  int cost;
} Point;

Point init_point(double, double);
