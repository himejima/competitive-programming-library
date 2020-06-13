//
// Doubling 
//
// 参考
//   [ダブリング | Luzhiled’s memo](https://ei1333.github.io/luzhiled/snippets/memo/doubling.html)
// 
// 計算量
//   前計算: NlogN
//   クエリ: logN
//
// verified
// [D - Teleporter](https://atcoder.jp/contests/abc167/tasks/abc167_d)

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

struct Doubling
{
  const int LOG;
  vector< vector< int > > table;
  
  Doubling(int sz, int64_t lim_t) : LOG(64 - __builtin_clzll(lim_t))
  {
    table.assign(LOG, vector< int >(sz, -1));
  }

  void set_next(int k, int x)
  {
    table[0][k] = x;
  }

  void build()
  {
    for(int k = 0; k + 1 < LOG; k++) {
      for(int i = 0; i < table[k].size(); i++) {
        if(table[k][i] == -1) table[k + 1][i] = -1;
        else table[k + 1][i] = table[k][table[k][i]];
      }
    }
  }

  // どこから、どこまで？
  int query(int k, int64_t t)
  {
     //  cout << t << endl;
    for(int i = LOG - 1; i >= 0; i--) {
      if((t >> i) & 1) k = table[i][k];
    }
    return k;
  }
};

ll N, K;

int main() {
    cin >> N >> K;

    // Doubling d = Doubling(N, 1LL << 61);
    // Doubling d = Doubling(N, 1LL << 60);
    Doubling d = Doubling(N, INF);

    rep(i, N) {
        ll dest;
        cin >> dest;
        dest--;
        d.set_next(i, dest);
    }
    d.build();

    cout << d.query(0, K) + 1 << endl;
    // rep(i, 20) {
    //     cout << i << " " << d.query(K, i) << endl;
    // }
}