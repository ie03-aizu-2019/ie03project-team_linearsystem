# ie03project-team_linearsystem

## メンバー

- ### s1250139 Magata Satomi 
- ### s1250164 Munakata Ren


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

- ### shortest_path.cpp / shortest_path.h

    最短経路を求める

- ### output.cpp / output.h

    結果を表示する
    
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
