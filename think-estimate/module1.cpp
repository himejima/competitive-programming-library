//
// 剰余と累積和
//
// A[l], A[l + 1], ... A[r-1], A[r] = sum[r] - sum[l - 1]
//
// ここで上記式が M の倍数であるとすると、
// => sum[r] と sum[l - 1] の余り (mod M) が等しいことが言える
// => 数え上げの問題となった
//
// verified
// [D - Candy Distribution](https://atcoder.jp/contests/abc105/tasks/abc105_d)
//
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N, M;
vector<ll> A;
vector<ll> sum;

int main() {
    cin >> N >> M;
    A.resize(N);
    rep(i, N) cin >> A[i];
    sum.resize(N + 1);
    sum[0] = 0;

    rep(i, N) {
        sum[i + 1] = (sum[i] + A[i]) % M;
    }

    // rep(i, N + 1) {
    //     cout << sum[i] << endl;
    // }
    map<ll, ll> mp;

    rep(i, N + 1) {
        mp[sum[i]]++;
    }

    ll ans = 0;
    for (auto m : mp) {
        // cout << m.first << " " << m.second << endl;
        ll tmp = m.second * (m.second - 1) / 2;
        ans += tmp;
    }

    cout << ans << endl;
}
