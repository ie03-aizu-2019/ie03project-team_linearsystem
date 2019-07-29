# ie03project-team_linearsystem

## メンバー

- ### s1250139 Magata Satomi
- ### s1250164 Munakata Ren

## 進捗状況


 フェイズ | 小課題 | 状況
-|-|-
 1 | 1 | テスト済み
 1 | 2 | テスト済み  
 1 | 3 | テスト済み
 1 | 4 | テスト済み
 2 | 5 | 一応動く
 2 | 6 | 一応動く
 2 | 7 |
 2 | 8 |
 3 | 9 |
 3 | 10 |
 3 | 11 |

 一応、フェイズ２小課題６の入出力例はテスト済み。　他のケースは試してない。  
 ~~あと、稀に `Segmentation fault: 11` になる。原因は調査中。~~  
 追記：結果の出力方法を変えたら今のところ問題なし。



## ファイル説明

- ### main.cpp

    main文があるところ

- ### main.h

    プログラム全体で使う構造体やグローバル変数が書いてある

- ### initialize.cpp / initialize.h

    初期化するときに使う

- ### matrix.cpp / matrix.h

    隣接行列を扱う

- ### cross_point.cpp / cross_point.h

    交差点の検出を行う

- ### shortest_path.cpp / k_shortest.cpp / shortest_path.h

    最短経路を求める

- ### output.cpp / output.h

    結果を表示する

- ### testdata/

    テスト用のデータが入ってる

- ### testdata/

    テスト用のデータが入ってる


## 構造体について

- ### Point

    点に関するデータを格納。

    - 要素番号
    - x,y座標
    - 繋がってる点とその距離
    - ダイクストラで使うもの

- ### Route

    経路に関するデータを格納。

    - 始点、終点、問い合わせ数
    - 入力した始点と終点の文字列のデータ
    - 経路とそのコスト


## グローバル変数について

- N, M, P, Q

    最初に入力する点の数、道路の数、追加の点の数、経路探索数

- p, inp_p, add_p, c_p

    全ての点、最初に入力した点、追加の点、交差点

- road

    入力した道の番号を保存

- route

    経路に関する情報

- matrix

    隣接行列


## コンパイル＆実行方法

- コンパイル

``` 
 g++ -std=c++11 *.cpp
```

- 実行

``` 
 ./a.out
```

- testdataのテストデータを使う

``` 
 ./a.out < testdata/hoge
```
