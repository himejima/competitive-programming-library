//
// 計算式を変形する
// 同じ変数通しで、右辺と左辺に分ける
// =>
// 一方を固定して考えることができるようになる
//
// verified
// [E - This Message Will Self-Destruct in 5s](https://atcoder.jp/contests/abc166/tasks/abc166_e)
//
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N;
vector<ll> A;
int main() {
    cin >> N;
    A.resize(N);
    rep(i, N) cin >> A[i];

    map<ll, ll> mp;
    rep(j, N) {
        mp[j + 1 - A[j]]++;
    }

    // for (auto iter = mp.begin(); iter != mp.end(); iter++) {
    //     cout << iter->first << " " << iter->second << endl;
    // }

    ll ans = 0;
    rep(i, N) {
        ll target = (i + 1) + A[i];
        ans += mp[target];
    }
    cout << ans << endl;
}
