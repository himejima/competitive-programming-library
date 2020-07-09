// Binary Indexed Tree
//
// 計算量: O(logN)
//
// verified
// [ALDS1_5_D < Problems | Aizu Online Judge](https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_D)
//
// 参考
// [library/bit.cpp at master · atcoder-live/library](https://github.com/atcoder-live/library/blob/master/bit.cpp)
//
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

const ll INF = 1LL << 60;

template<typename T>
struct BIT {
  int n;
  vector<T> d;
  BIT(int n=0):n(n),d(n+1) {}
  void add(int i, T x=1) {
    for (i++; i <= n; i += i&-i) {
      d[i] += x;
    }
  }
  T sum(int i) {
    T x = 0;
    for (i++; i; i -= i&-i) {
      x += d[i];
    }
    return x;
  }
  T sum(int l, int r) {
    return sum(r-1) - sum(l-1);
  }
};

ll n;
vector<P> a;
int main() {
    cin >> n;
    a.resize(n);

    rep(i, n) {
        ll tmp;
        cin >> tmp;
        // value, index
        a[i] = P(tmp, i);
    }

    // a[i] の値が大きいので振り直す
    sort(a.begin(), a.end());
    rep(i, n) {
        a[i].first = i + 1;
    }
    // index　順に振り直す

    sort(a.begin(), a.end(), [](const pair<int, int> &x, const pair<ll, ll> &y){return x.second < y.second;});

    BIT<int> bit(n + 5);

    ll ans = 0;
    for (int j = 0; j < n; j++) {
        ans += j - bit.sum(a[j].first);
        bit.add(a[j].first, 1);
    }
    cout << ans << endl;
}
