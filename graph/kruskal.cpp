//
// クラスカル法  
//
// 計算量: O(|E|log|V|) 
// 
// verified
// [D - Built?](https://atcoder.jp/contests/abc065/tasks/arc076_b)
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;
struct edge { ll cost, u, v; };

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

ll N;
int main() {
    cin >> N;

    vector<edge> es;

    vector<P> a;
    vector<P> b;

    // 辺の数
    rep(i, N) {
        int x, y;
        cin >> x >> y;
        a.push_back(P(x, i));
        b.push_back(P(y, i));
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int i = 1; i <= N - 1; i++) {
        P prev = a[i - 1];
        P current = a[i];

        ll w = abs(prev.first - current.first);
        edge e { w, prev.second, current.second };
        es.push_back(e);
    }

    for (int i = 1; i <= N - 1; i++) {
        P prev = b[i - 1];
        P current = b[i];

        ll w = abs(prev.first - current.first);
        edge e { w, prev.second, current.second };
        es.push_back(e);
    }

    sort(es.begin(), es.end(), comp);
    UnionFind uf = UnionFind(N);

    ll cost = 0;
    rep(i, es.size()) {
        if (uf.root(es[i].u) != uf.root(es[i].v)) {
            uf.connect(es[i].u, es[i].v);
            cost += es[i].cost;
        }
    }
    cout << cost << endl;
}