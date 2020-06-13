//
// 一次元累積和 
//
// verified
// [A - 旅人](https://atcoder.jp/contests/joi2010ho/tasks/joi2010ho_a)
//
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;
const ll MOD = 1e5;

ll n, m;
vector<ll> a, dist;
int main() {
    cin >> n >> m;
    dist.resize(n - 1);
    a.resize(m);
    rep(i, n - 1) cin >> dist[i];
    rep(i, m) {
        cin >> a[i];
        // a[i]--;
    }

    vector<ll> sum(n);
    sum[0] = 0;
    rep(i, n - 1) {
        sum[i + 1] = sum[i] + dist[i]; 
    }

    ll ans = 0;
    ll current = 0; 
    rep(i, m) {
        ll now = current;
        ll next = current + a[i];
        ans += abs(sum[next] - sum[now]);
        // cout << i << " " << ans << " next: " << next << " now " << now << endl; 
        ans %= MOD;

        current = next;
    }
    cout << ans << endl;
}