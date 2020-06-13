//
// modpow 
// 
// 計算量: O(log n)
// 
// verified
// [E - 散歩 (E869120 and Path Length)](https://atcoder.jp/contests/s8pc-1/tasks/s8pc_1_e) 
//
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

ll mod_pow(ll x, ll n) {
    if (n == 0) return 1;
    ll res = mod_pow(x * x % MOD, n / 2);
    if (n & 1) res = x * res % MOD;
    return res;
}
int main() {
    ll N, Q;
    cin >> N >> Q;
    vector<ll> a(N), c(Q);
    rep(i, N) cin >> a[i];
    rep(i, Q) cin >> c[i];

    vector<ll> sum(N + 1);
    sum[1] = 0;
    for (int i = 1; i <= N - 1; i++) {
        sum[i + 1] = sum[i] + mod_pow(a[i - 1], a[i]);
    }

    // rep(i, N + 1) {
    //     cout << i << " " << sum[i] << endl;
    // }
    ll ans = 0;
    if (c[0] != 1) {
        ans += abs(sum[1] - sum[c[0]]);
        ans %= MOD;
    }
    if (c[Q - 1] != 1) {
        ans += abs(sum[c[Q - 1] - sum[1]]);
        ans %= MOD;
    }
    rep(i, Q) {
        if (i + 1 > Q - 1) continue;
        ans += abs(sum[c[i]] - sum[c[i + 1]]);
        ans %= MOD;
    }
    cout << ans << endl;
}