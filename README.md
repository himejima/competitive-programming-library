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

---

### Union-Find

- Union-Find (union by size)
- Union-Find (union by rank)
- 重みつき Union-Find
- 重みつき Union-Find (F2 体)
- 部分永続 Union-Find
- Quick Find
- Dynamic Connectivity

### セグメント木

- セグメント木
- セグメント木 (遅延評価)
- Starry Sky 木 (俗称)
- マージソート過程保存木
- 等差数列区間加算木
- 二次元セグメント木
- Binary Indexed 木

### Binary Indexed 木

- BIT
- BIT 上二分探索 (k 番目の要素を求める)
- BIT (区間加算, 区間和取得に両対応)
- 二次元 BIT
- 二次元 BIT (領域加算, 領域和取得に両対応)

### RMQ

- RMQ (セグメント木)
- RMQ (Sparse Table)

### 平方分割

- Mo 法

### 平衡二分探索木

- RBST
- Treap 木
- AVL 木
- Splay 木
- 赤黒木

### 永続データ構造

- 永続配列
- 完全永続 Union-Find 木
- 永続セグメント木
- 永続赤黒木

### ハッシュ

- Zobrist hash
- 木に対する hash

### ヒープ

- Skew Heap (マージ可能)
- Paring Heap (マージ可能)
- Radix Heap
- Fibonacci Heap

### その他

- Binary Trie
- Disjoint Sparse Table
- 並列二分探索
- Wavelet 木
- BinaryTrie 木
- Cartesian 木

### 木全般

- 部分木サイズ, LCA など

### LCA

- LCA (ダブリング)
- LCA (Euler Tour)
- LCA (HL 分解)

### テクニック

- Euler Tour (頂点上)
- Euler Tour (辺上のクエリ)
- HL 分解
- 重心分解
- Link-Cut 木
- マージテク (俗称)
- DSU on Tree

### その他の問題

- Level Ancester

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

---

### 典型処理

- 累積和
- 二次元累積和
- いもす法 (俗称)
- 二次元いもす法 (俗称)
- 三次元いもす法 (俗称)
- 座標圧縮
- スライド最小値

### 典型的 DP

- 転倒数
- LIS
- LCS
- 編集距離
- 重みつき区間スケジューリング問題
- ヒストグラム長方形面積最大化
- 最適二分探索木
- Set Cover
- k-Cover (O(n 2^n))
- k-partition (O(n^3 2^n))

### DP パターン例

- ナップサック DP
- 区間分割型ナップサック DP
- bitDP
- 桁 DP
- 部分列 DP
- ダブリング DP
- 木 DP
- 全方位木 DP (俗称)
- 二乗の木 DP (俗称)

### DP 高速化テクニック

- 累積和
- スライド最小値
- インライン DP (俗称)
- Convex Hull Trick (傾き単調, クエリも単調)
- Convex Hull Trick (傾き単調)
- Convex Hull Trick (単調でなくてよい)
- Monotone Minima
- Divide and Conquer
- Monge
- Alien DP
- 戻す DP (俗称)

## 文字列

- 複数文字列検索(Aho-Corasick)
- 接尾辞配列(Suffix-Array)
- 高さ配列(LCP-Array)
- 最長回文(Manacher)
- 最長共通接頭辞(Z-Algorithm)
- ローリングハッシュ

---

### 構文解析

- LL(1) 再帰降下パーサ

### 文字列検索

- ローリングハッシュ
- 二次元ローリングハッシュ
- 単一パターン検索 (KMP 法)
- 単一パターン検索 (Boyer-Moore 法)
- 複数パターン検索 (Aho-Corasick 法)

### 文字列系アルゴリズム

- Z 法
- Manacher 法

### 文字列系データ構造

- Trie 木
- Suffix Array
- Suffix Array (SA-IS)
- Palindromic 木 (AOJ 2292)

### その他

- 各 index 以降で各文字が最初に登場する index を求める関数
- split 関数
- 二次元盤面に番兵追加
- 二次元盤面を 90 度回転

## 幾何

ライブラリのせる

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

---

### DFS・BFS

- DFS (連結成分を数える)
- BFS (重みなしグラフの最短路)
- トポロジカルソート (DFS)
- トポロジカルソート (BFS)
- サイクル検出 (DFS)
- サイクル検出 (BFS)
- サイクル検出 (Union-Find)
- 二部グラフ判定 (DFS)
- 二部グラフ判定 (BFS)
- 二部グラフ判定 (Union-Find)

### 連結成分分解

- 強連結成分分解
- 橋, 関節点列挙 (Low-Link)
- 二重辺連結成分分解
- 二重頂点連結成分分解
- 2-SAT

### ツリー

- ツリーの直径
- ツリーの重心

### 最短路

- 重みなしグラフの最短路 (BFS)
- 重みが 0, 1 のみのグラフの最短路 (0-1 BFS)
- 単一始点最短路 (Dijkstra 法, 正辺のみ)
- 単一始点最短路 (Bellman-Ford 法, 負辺対応)
- 全頂点対間最短路 (Floyd-Warshall 法)
- 全頂点対間最短路 (Johnson 法)
- k-最短路
- SPFA

### その他

- 最小全域木 (Kruskal 法)
- 最小有向全域木 (Chu-Liu/Edmonds 法)
- 有向 Euler 路
- 無向 Euler 路
- 彩色数 (O(n2^n))
- 最大安定集合問題 (O(1.381^n))
- 最大クリーク列挙（O(1.443^n)）
- 最小シュタイナー木 (O(n 3^t + n^2 2^t + n^3))

### 最大流

- 最大流 (Ford-Fulkerson 法)
- 最大流 (Dinic 法)

### 最小費用流

- 最小費用流 (Primal-Dual 法, 正辺のみ)
- 最小費用流 (Primal-Dual 法, 負辺対応)
- 最小費用最大流 (Primal-Dual 法, 正辺のみ)
- 最小費用最大流 (Primal-Dual 法, 負辺対応)
- 最小費用循環流 (Cost-Scaling, 負閉路OK)

### カット

- 最小カット (= 最大流)
- 全域最小カット（Stoer-Wanger 法）
- 全頂点対間最小カット (Nagamochi-Ibaraki 法)
- Gomory-Hu 木

### マッチング

- 二部マッチング (Hopcroft-Karp 法)
- 重みつき二部マッチング (Hungarian 法)
- 一般グラフの最大マッチング (Edmonds 法)
- 一般グラフの最大マッチング (行列補間)

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

---

### 約数, 倍数

- 約数列挙
- 最大公約数 (Euclid の互除法)
- 最小公倍数
- 拡張 Euclid の互除法

### 素数

- 素数判定
- 素因数分解
- 確率的素数判定 (Miller-Rabin 法)
- エラトステネスの篩
- エラトステネスの区間篩
- アトキンの篩

### 素因数分解を基にしたアルゴリズム

- 高速素因数分解 (ロー法)
- Euler のファイ関数
- メビウス関数
- 素因数分解, 約数列挙, メビウス関数 (エラトステネスの篩風)

### 方程式

- 中国剰余定理
- 中国剰余定理 (Garner 法)
- 連立一次合同方程式
- ペル方程式
- 離散対数
- 平方剰余

### 有理数

- 有理数
- Stern-Brocot 木

### その他

- 平衡三進法展開
- 多倍長整数

### mod, 二項係数

- modint
- 実行時に法が決まる modint
- 累乗
- 逆元
- 二項係数 (オーソドックス, n<=10^7, r<=10^7, p<=10^9)
- 二項係数 (愚直計算, n<=10^9, r<=10^7, p<=10^9)
- 二項係数 (漸化式計算, n<=10^9, r<=10^9, p<=10^7)
- 二項係数 (任意 mod, n<=10^7, r<=10^7, m<=10^9)
- mod の値が大きいとき

### 様々な数

- 重複組合せ
- カタラン数
- 分割数
- スターリング数
- ベル数
- ベルヌーイ数

### ソート

- クイックソート
- マージソート
- ヒープソート
- コムソート
- Radix ソート
- 挿入ソート
- その他のソート達

### マトロイド

- マトロイド上の Greedy 法
- マトロイド交差

### その他

- Nim
- LIS and LDS

### 行列

- 行列 (基本演算)
- 行列累乗, ランク, 連立一次方程式 (実数)
- 行列累乗, ランク, 連立一次方程式 (mod. p)
- 行列累乗, ランク, 連立一次方程式 (binary)
- Toeplitz 行列 (乗算, 連立方程式が O(n^2))
- 巡回行列 (乗算が O(n^2))
- コンパニオン行列
- 三重対角行列 (連立方程式が O(n))
- Black Box Linear Algebra

### 多項式, 方程式

- 二次方程式
- 多項式 (実数係数)
- 多項式 (mod. p 係数)
- きたまさ法 (俗称)
- きたまさ法 with FFT (俗称)
- 多項式補間

### 畳み込み計算

- FFT (高速フーリエ変換)
- NTT (高速剰余変換)
- 高速アダマール変換 (SRM 518 div1 hard)
- 高速ゼータ変換
- 高速メビウス変換
- 添字 GCD 畳み込み
- Karatsuba 法

### 最適化

- 二分探索法 (方程式の解を 1 つ求める)
- 三分探索法
- 黄金探索法
- Newton 法
- 単体法
- 分枝限定法

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

---

### グリッド

- グリッドの 4 近傍, 8 近傍
- ハニカムの 6 近傍

### ビット演算テクニック

- XorShift, ランダムシャッフル
- next_combination
- 部分集合の部分集合

### 探索法

- α-β 探索
- 焼き鈍し法
- A*
- IDA*
- Baby-Step Giant-Step 法
- 平面走査法

### その他

- デバッグストリーム, chmin, chmax
- pn + r (n は非負整数) で表せる整数のうち, x 以上となる最小の整数
- タイマー
- サイコロ
- 曜日
- 四面体 (AOJ 2060)
