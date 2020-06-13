//
// エラトステネスの篩 
// 計算量: O(n log log n程度) 
// verified
// [D - 2017-like Number](https://atcoder.jp/contests/abc084/tasks/abc084_d)
//
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

int Q;

struct Sieve {
  int n;
  vector<int> f, primes;
  Sieve(int n=1):n(n), f(n+1) {
    f[0] = f[1] = -1;
    for (ll i = 2; i <= n; ++i) {
      if (f[i]) continue;
      primes.push_back(i);
      f[i] = i;
      for (ll j = i*i; j <= n; j += i) {
        if (!f[j]) f[j] = i;
      }
    }
  }
  bool isPrime(int x) { return f[x] == x;}
  vector<int> factorList(int x) {
    vector<int> res;
    while (x != 1) {
      res.push_back(f[x]);
      x /= f[x];
    }
    return res;
  }
  vector<P> factor(int x) {
    vector<int> fl = factorList(x);
    if (fl.size() == 0) return {};
    vector<P> res(1, P(fl[0], 0));
    for (int p : fl) {
      if (res.back().first == p) {
        res.back().second++;
      } else {
        res.emplace_back(p, 1);
      }
    }
    return res;
  }
};

int main() {
    cin >> Q;

    // エラトステネスの篩
    Sieve sieve = Sieve(100100);
    map<ll, ll> sum;
    ll tmp = 0; 
    for (int i = 1; i <= 100100; i++) {
        if (i % 2 == 0) {
            sum[i] = tmp;
            continue;
        }

        if (sieve.isPrime(i) && sieve.isPrime((i + 1) / 2)) {
            tmp++;
            sum[i] = tmp;
        } else {
            sum[i] = tmp;
        }
    }
    // ll cnt = 0;
    // for (auto mp : sum) {
    //     cout << mp.first << " " << mp.second << endl;
    //     cnt++;
    //     if (cnt > 20) {
    //         return 0;
    //     }
    // }

    rep(i, Q) {
        ll l, r;
        cin >> l >> r;
        ll ans = sum[r] - sum[l - 1];
        // cout << sum[r] << " " << sum[l] << endl;
        cout << ans << endl;
    }
}