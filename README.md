# toyon-competitive-programming-library

問題を解くときに使用したアルゴリズム、データ構造、考え方を出来るだけ分類していきます。

## 探索

- [ビット全探索](https://github.com/himejima/competitive-programming-library/blob/master/full-search/bit.cpp)
- [順列全探索](https://github.com/himejima/competitive-programming-library/blob/master/full-search/permutation.cpp)
- [二分探索](https://github.com/himejima/competitive-programming-library/blob/master/full-search/binary-search.cpp)
- [二分探索 (最大値の最小化)](https://github.com/himejima/competitive-programming-library/blob/master/full-search/binary-search-value.cpp)

## データ構造

### Union-Find

- [Union-Find (rank)](https://github.com/himejima/competitive-programming-library/blob/master/structure/uniondfind.cpp)
- [Union-Find (size)](https://github.com/himejima/competitive-programming-library/blob/master/structure/uniondfind-2.cpp)

### Priority Queue

- [Priority Queue](https://github.com/himejima/competitive-programming-library/blob/master/structure/priority-queue.cpp)

### BIT

- [BIT](https://github.com/himejima/competitive-programming-library/blob/master/structure/bit.cpp)

## DP

### 累積和

- [一次元累積和](https://github.com/himejima/competitive-programming-library/blob/master/dp/cumulative-sum.cpp)
- [二次元累積和](https://github.com/himejima/competitive-programming-library/blob/master/dp/cumulative-sum-2d.cpp)
- [いもす法](https://github.com/himejima/competitive-programming-library/blob/master/dp/imos.cpp)

### DP パターン例

- [0-1ナップサック DP](https://github.com/himejima/competitive-programming-library/blob/master/dp/knapsack-01.cpp)
- 区間分割型ナップサック DP
- [bitDP](https://github.com/himejima/competitive-programming-library/blob/master/dp/bit-dp.cpp)
- [桁 DP](https://github.com/himejima/competitive-programming-library/blob/master/dp/digit-dp.cpp)
- 部分列 DP
- ダブリング DP
- [木 DP](https://github.com/himejima/competitive-programming-library/blob/master/dp/tree-dp.cpp)
- [全方位木 DP (俗称)](https://github.com/himejima/competitive-programming-library/blob/master/dp/reroot-dp.cpp)
- 二乗の木 DP (俗称)
- [LCS (最長共通部分列)](https://github.com/himejima/competitive-programming-library/blob/master/dp/lcs.cpp)


## 文字列

- [ローリングハッシュ](https://github.com/himejima/competitive-programming-library/blob/master/string/rolling_hash.cpp)
- [Z-algorithm](https://github.com/himejima/competitive-programming-library/blob/master/string/z-algorithm.cpp)

## 幾何

- [基本処理詰め合わせ](https://github.com/himejima/competitive-programming-library/blob/master/geometry/template.cpp)

## グラフ

### DFS・BFS

- [DFS (探索)](https://github.com/himejima/competitive-programming-library/blob/master/graph/dfs.cpp)
- [DFS (連結成分の数を求める)](https://github.com/himejima/competitive-programming-library/blob/master/graph/dfs2.cpp)
- [DFS (2部グラフの頂点彩色)](https://github.com/himejima/competitive-programming-library/blob/master/graph/dfs-bipartite-graph.cpp)
- [BFS (重みなしグラフの最短路)](https://github.com/himejima/competitive-programming-library/blob/master/graph/bfs.cpp)

### フロー

- [最大流(Dinic) O(EV^2)](https://github.com/himejima/competitive-programming-library/blob/master/graph/dinic.cpp)
- 最小カット=最大流
- 二部マッチング=最大流 (※別解あり)
- [最小費用流](https://github.com/himejima/competitive-programming-library/blob/master/graph/min_cost_flow.cpp)

### 最短路

- [単一始点最短路 (Dijkstra) O(|E|log|V|) ※ 正辺のみ](https://github.com/himejima/competitive-programming-library/blob/master/graph/dijkstra.cpp)
- [全点対間最短路(Warshall-Floyd) O(V^3)](https://github.com/himejima/competitive-programming-library/blob/master/graph/warshall-floyd.cpp)

### 最小全域木

- [最小全域木(Kruskal)](https://github.com/himejima/competitive-programming-library/blob/master/graph/kruskal.cpp)

## 数学

### 数論

- [GCD, LCM](https://github.com/himejima/competitive-programming-library/blob/master/math/base.cpp)
- [素数判定](https://github.com/himejima/competitive-programming-library/blob/master/math/base.cpp)
- [約数列挙](https://github.com/himejima/competitive-programming-library/blob/master/math/base.cpp)
- [素因数分解](https://github.com/himejima/competitive-programming-library/blob/master/math/base.cpp)
- [エラトステネスの篩](https://github.com/himejima/competitive-programming-library/blob/master/math/sieve-eratosthenes.cpp)
- [modpow](https://github.com/himejima/competitive-programming-library/blob/master/math/modpow.cpp)
- [xor](https://github.com/himejima/competitive-programming-library/blob/master/math/xor.cpp)
- [Nim](https://github.com/himejima/competitive-programming-library/blob/master/math/nim.cpp)

### 組合せ

- [modint](https://github.com/himejima/competitive-programming-library/blob/master/math/modint-combination.cpp)
- [組合せ](https://github.com/himejima/competitive-programming-library/blob/master/math/modint-combination.cpp)

### 行列

- [行列累乗](https://github.com/himejima/competitive-programming-library/blob/master/math/matrix.cpp)

## その他

- [ダブリング](https://github.com/himejima/competitive-programming-library/blob/master/other/doubling.cpp)
- [しゃくとり法](https://github.com/himejima/competitive-programming-library/blob/master/other/two-pointers.cpp)
- [角度とラジアンの変換](https://github.com/himejima/competitive-programming-library/blob/master/other/radian-degree.cpp)
- [グリッド](https://github.com/himejima/competitive-programming-library/blob/master/other/grid-neighbors.cpp)
