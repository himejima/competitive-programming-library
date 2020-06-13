//
// クラスカル法  
//
// 計算量: O(|E|log|V|) 
// 
// verified
// [GRL_2_A < Problems | Aizu Online Judge](https://onlinejudge.u-aizu.ac.jp/problems/GRL_2_A)
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;
struct edge { int cost, u, v; };

bool comp(const edge& e1, const edge& e2) {
    return e1.cost < e2.cost;
}

class UnionFind {
public:
  //親の番号を格納する。親だった場合は-(その集合のサイズ)
  vector<int> Parent;

  //作るときはParentの値を全て-1にする
  //こうすると全てバラバラになる
  UnionFind(int N) {
    Parent = vector<int>(N, -1);
  }

  //Aがどのグループに属しているか調べる
  int root(int A) {
    if (Parent[A] < 0) return A;
    return Parent[A] = root(Parent[A]);
  }

  //自分のいるグループの頂点数を調べる
  int size(int A) {
    return -Parent[root(A)];//親をとってきたい]
  }

  //AとBをくっ付ける
  bool connect(int A, int B) {
    A = root(A);
    B = root(B);
    if (A == B) {
      return false;
    }

    if (size(A) < size(B)) swap(A, B);

    Parent[A] += Parent[B];

    Parent[B] = A;

    return true;
  }
};

int main() {
    ll V, E;
    cin >> V >> E;

    edge es[100100];
    rep(i, E) {
        int x, t, w;
        cin >> x >> t >> w;
        edge e { w, x, t };
        es[i] = e;
    }

    sort(es, es + E, comp);
    UnionFind uf = UnionFind(V);

    ll cost = 0;
    rep(i, E) {
        // cout << es[i].cost << " " << es[i].u << " " << es[i].v << endl;
        if (uf.root(es[i].u) != uf.root(es[i].v)) {
            uf.connect(es[i].u, es[i].v);
            cost += es[i].cost;
        }
    }
    cout << cost << endl;
}
