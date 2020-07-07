//
// 集合を Key に持たせた DP
//
// verified
// [E - Get Everything](https://atcoder.jp/contests/abc142/tasks/abc142_e)
//
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

const ll INF = 1LL << 60;

ll N, M;
vector<P> v;

// 宝箱を開ける時に必要な最小コスト
ll dp[5000];

int main() {
    cin >> N >> M;
    v.resize(M);
    rep(i, M) {
        ll a, b;
        cin >> a >> b;

        int s = 0;
        rep(j, b) {
            ll c;
            cin >> c;
            c--;
            s |= (1 << c);
        }
        // s を開けるのに a 円必要
        v[i] = P(s, a);
    }

    rep(i, 5000) dp[i] = INF;
    sort(v.begin(), v.end());

    // rep(i, v.size()) {
    //     cout << v[i].first << " " << v[i].second << endl;
    // }
    // return 0;

    dp[0] = 0;


   for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < M; j++) {
            // 使う
            ll idx = v[j].first;
            ll cost = v[j].second;

            // cout << cost << " " << idx << endl;
            dp[i | idx] = min(dp[i | idx],  dp[i] + cost);
        }
    }

    if (dp[(1 << N) - 1] == INF) {
        cout << -1 << endl;
    } else {
        cout << dp[(1 << N) - 1] << endl;
    }
}