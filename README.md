# toyon-competitive-programming-library

未履修は黒文字でリンクがありません

## データ構造

### Union-Find

- [Union-Find (rank)](https://github.com/himejima/competitive-programming-library/blob/master/structure/uniondfind.cpp)
- [Union-Find (size)](https://github.com/himejima/competitive-programming-library/blob/master/structure/uniondfind-2.cpp)
- 部分永続Union-Find
- 完全永続Union-Find
- Undo可能Union-Find
- 重み付きUnion-Find
- 二部グラフの頂点彩色

### Segment-Tree

- Segment-Tree
- 双対Segment-Tree
- 遅延伝搬Segment-Tree
- 二次元Segment-Tree(一点更新矩形取得)
- 二次元Segment-Tree(矩形更新一点取得)
- 永続Segment-Tree
- Segment-Tree-Beats

### Trie

- Trie
- Binary-Trie
- 永続Binary-Trie

### Convex-Hull-Trick

- Conxex-Hull-Trick(追加クエリの傾きが単調)
- Li-Chao-Tree
- 動的Li-Chao-Tree
- 永続動的Li-Chao-Tree

### 平衡二分探索木

- RBST(列として)
- RBST(multisetとして)
- 赤黒木
- 永続赤黒木

### Link-Cut-Tree

- Link-Cut-Tree
- Link-Cut-Tree(部分木クエリ)

### 平衡二分探索木

- RBST(列として)
- RBST(multisetとして)
- 赤黒木
- 永続赤黒木

### Heap

- Skew-Heap
- Fibonacchi-Heap
- Radix-Heap

### ウェーブレット

- 完備辞書
- Wavelet-Matrix
- Wavelet-Matrix-Rectangle-Sum
- Wevelet-Tree

### その他

- Binary-Indexed-Tree
- Sparse-Table
- Disjoint-Sparse-Table
- 永続配列
- 列の平方分割
- 長方形の和集合の面積
- スライド区間の昇順k個の和
- Sliding-Window-Aggregation

## DP

### ナップサック問題

- 0-1ナップサック O(NW)
- 0-1ナップサック O(N sum(v_i))
- 個数制限なしナップサック O(NW)
- 個数制限付きナップサック O(NW)
- 個数制限付きナップサック O(N^2 max(v_i)^2)

### 累積和

- 一次元累積和
- 二次元累積和

### その他

- Divide-And-Conquer-Optimization
- 最適二分探索木
- ヒストグラム中の最大長方形
- 最長増加部分列(LIS)
- 編集距離
- Monotone-Minima
- オンラインオフライン変換
- スライド最小値

## 文字列

- 複数文字列検索(Aho-Corasick)
- 接尾辞配列(Suffix-Array)
- 高さ配列(LCP-Array)
- 最長回文(Manacher)
- 最長共通接頭辞(Z-Algorithm)
- ローリングハッシュ

## 幾何

## グラフ

### フロー

- 最大流(Ford-Fulkerson) O(FE)
- [最大流(Dinic) O(EV^2)](https://github.com/himejima/competitive-programming-library/blob/master/graph/dinic.cpp)
- 最小カット=最大流
- 最大流(Dinic) 容量スケーリング O(EV logU)
- 最大流(Push-Relabel) O(V^2 sqrt(E))
- 最小流量制限付き最大流, 循環流
- 最小費用流(Primal-Dual) O(FE logV)
- 二部グラフの最大マッチング O(EV)
- 二部グラフの最大マッチング(HopCroft-Karp) O(E sqrt(V))
- 二部グラフの最小重み最大マッチング(Hungarian) O(V^3)
- 一般グラフの最大マッチング(GabowEdmonds) O(VE logV)

### 連結成分分解

- 二重辺連結成分分解
- 二重頂点連結成分分解
- 強連結成分分解

### 最短路

- グリッド上の幅優先探索 O(HW)
- 単一始点最短路(Bellman-Ford) O(VE)
- 単一始点最短路(SPFA) O(VE)
- [単一始点最短路 (Dijkstra) O(|E|log|V|) ※ 正辺のみ](https://github.com/himejima/competitive-programming-library/blob/master/graph/dijkstra.cpp)
- 単一始点最短路(Dijkstra with Fibonacch-Heap) O(V logV + E)
- 単一始点最短路(Dijkstra with Radix-Heap) O((E + V) logU)
- [全点対間最短路(Warshall-Floyd) O(V^3)](https://github.com/himejima/competitive-programming-library/blob/master/graph/warshall-floyd.cpp)

### 最小全域木

- 最小全域木(Borůvka)
- 最小全域木(Kruskal)
- 最小全域木(Prim)
- 最小全域木(Prim with Fibonacchi-Heap)

### 木

- 重心分解
- 最終共通祖先(ダブリング)
- HL分解
- 全方位木DP
- 木の直径
- 木の重心
- 木の同型性 O(V logV)
- 根付き木に変換

### その他

- オイラー路の復元
- 彩色数 O(2^V V)
- 最小全域有向木(Chu-Liu/Edmond) O(E logV)
- 橋/関節点
- 最大クリーク O(2^sqrt(2E) V)
- 最大独立集合(乱択)
- トポロジカルソート
- DAGの到達可能性クエリ(オフライン) O((V+E)Q/64)
- Dominator-Tree

## 数学

### 数論

- オイラーのφ関数(値) O(sqrt(N))
- オイラーのφ関数(テーブル) O(N loglogN)
- メビウスのμ関数(テーブル) O(N loglogN)
- 商の列挙
- 拡張ユークリッドの互除法 O(logN)
- 約数列挙 O(sqrt(N)
- 素因数分解 O(sqrt(N))
- 素数判定 (確率的素数判定) / 素因数分解 (Pollard-Rho)
- 進数変換

### 組合せ

- ModInt
- 任意ModInt
- 組合せ
- 累乗 O(logN)
- Mod-Sqrt
- ベル数(値) O(min(N,K) logN)
- ラグランジュ補間
- 二項係数(値) O(K)
- 二項係数(テーブル) O(N^2)
- 第2種スターリング数 O(K logN)
- 階乗 mod p O(sqrt(p) log p)
- 離散対数問題 O(sqrt(p))
- モンモール数 O(N)

### FFT

- 高速フーリエ変換(FFT)
- 高速フーリエ変換(NTT)
- 高速フーリエ変換(NTT) ModInt
- 任意mod畳み込み (30bit)
- 任意mod畳み込み (38bit)

### 形式的冪級数

- 形式的冪級数
- Multipoint-Evaluation O(N log^2N)
- Polynomial-Interpolation O(N log^2N)
- ベルヌーイ数, スターリング数などの列挙
- Berlekamp-Massey O(N^2)
- 疎行列の行列累乗/行列式

### 行列

- 行列

## その他

- [ダブリング](https://github.com/himejima/competitive-programming-library/blob/master/other/doubling.cpp)
- Mo's algorithm
- Mo's algorithm(ロールバッグ平方分割)
- Offline-Dynamic-Connectivity
- サイコロ
- タイマー
- 乱数生成器
- 座標圧縮
- 高速入力
