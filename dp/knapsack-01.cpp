//
// 01のナップサック問題 
//
// verified
// [D - Mixing Experiment](https://atcoder.jp/contests/abc054/tasks/abc054_d)
//
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N, Ma, Mb;
vector<ll> a, b, c;

// i: 何個目？
// j: aのg数
// k: bのg数
// =: 最小cost 

ll dp[50][500][500];
int main() {
    cin >> N >> Ma >> Mb;
    a.resize(N);
    b.resize(N);
    c.resize(N);
    rep(i, N) cin >> a[i] >> b[i] >> c[i];

    rep(i, N + 1)rep(j, 40)rep(k, 40) {
        dp[i][j][k] = INF;
    }
    dp[0][0][0] = 0;

    rep(i, N)rep(j, 40)rep(k, 40) {
        // i個目を選んだ
        dp[i + 1][j + a[i]][k + b[i]] = min(dp[i + 1][j + a[i]][k + b[i]], dp[i][j][k] + c[i]);

        // i個目を選ばない
        dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
    } 

    // 作れるかチェック
    ll ans = INF;
    for (int j = 1; j <= 400; j++) {
        for (int k = 1; k <= 400; k++) {
            if (dp[N][j][k] == INF) continue;
            if (dp[N][j][k] == 0) continue;

            if (j * Mb == k * Ma) {
                ans = min(ans, dp[N][j][k]);
            } 
            // cout << j << " " << k << " " << dp[N][j][k] << endl;
        }
    }
    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl; 
    }
}